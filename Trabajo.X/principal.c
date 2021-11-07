#include <xc.h>
#include <dsp.h>
#include <pps.h>
#include <stdio.h>
#include "perifericos.h"
#include "defs.h"
#include "interrupciones.h"
#include "procesamiento.h"
#include "config.h"
#include "lcd.h"
#include "pwm.h"

fractcomplex valCH0[FFT_BLOCK_LENGTH]
__attribute__ ((eds, space(ymemory), aligned (FFT_BLOCK_LENGTH * 2 *2)));
fractcomplex valCH1[FFT_BLOCK_LENGTH]
__attribute__ ((eds, space(ymemory), aligned (FFT_BLOCK_LENGTH * 2 *2)));

fractional hamming[FFT_BLOCK_LENGTH] 	
 __attribute__ ((section (".xbss, bss, xmemory"), aligned (FFT_BLOCK_LENGTH* 2 *2)));

int procesar = 0;
int segundos = 0;
int contPruebas = 0;
int estaActivo = 0;
int tdcs = 0;
float lnCH0 = 0, lnCH1 = 0;
float faa = 0;
float bandaAlfaCH0 = 0, bandaAlfaCH1 = 0;
char valorfaa[8];
//Variables para temporizador
char tiempo[7];
char dmin, umin, dseg, useg, actualizarTiempo, decremento;
int incrementos;

int main(int argc, char** argv) {
    
    iniPerifericos();
    ini_lcd();
    iniTimer3();
    iniADC();
    //iniUART();
    //iniTimer5();
    iniInterrupcionesADC();
    //iniInterrupcionesUART();
    
	//Habilitaci?n de puertos
	TRISA = 0x0001;         //AN0 se configura como entrada
    TRISB = 0x0002;         //AN3 se configura como entrada
    //PORTB = 0x01;           //RB0 se configura como salida
    TRISAbits.TRISA1=1;
    /*PPSUnLock;
    iPPSOutput(OUT_PIN_PPS_RP0, OUT_FN_PPS_U1TX);
    PPSLock;*/
    //Inicializaci?n de los coeficientes de hamming
    HammingInit(FFT_BLOCK_LENGTH,&hamming[0]);
    
    comando_lcd(0x0080); //Poner cursor en posc 0
    string_lcd(" Inicie lectura ");
    //RPOR5bits.RP10R = 0x0003;
    int i;
    while(1) 
    {
        if(PORTAbits.RA1 == 1 && estaActivo == 0)
        {
            limpiar_lcd();
            comando_lcd(0x0080); //Poner cursor en posc 0
            string_lcd("Leyendo...");
            activaADC();
            estaActivo = 1;
            //LATBbits.LATB15= ~LATBbits.LATB15;
        }
        if(procesar == 2)
        {
            desactivaADC();
            //LATBbits.LATB7= ~LATBbits.LATB7;
            procesarMuestras(0);
            procesarMuestras(1);
            segundos++;
            
            if( segundos == SEGUNDOS_PROCESAMIENTO)
            {
                //LATBbits.LATB7= ~LATBbits.LATB7;
                bandaAlfaCH0/= SEGUNDOS_PROCESAMIENTO * 5;
                bandaAlfaCH1/= SEGUNDOS_PROCESAMIENTO * 5;
                
                //Calcular el logaritmo natural del promedio
                lnCH0 = logf(bandaAlfaCH0);
                lnCH1 = logf(bandaAlfaCH1);
                faa = fabsf(lnCH1) - fabsf(lnCH0);
                if( faa < 0 ){
                    faa *= -1;
                    valorfaa[0]='-';
                    tdcs=1;
                }else{
                    valorfaa[0]=' ';
                }
                if(faa >= 10 && faa<100){
                    faa = faa/10;
                    valorfaa[1]=(int)faa + 0x0030;
                    faa -=(int)faa;
                    faa*=10;
                }
                else
                {
                    valorfaa[1]=0 + 0x0030;   
                }
                valorfaa[2]=(int)faa + 0x0030;
                faa -=(int)faa;
                valorfaa[3]='.';
                for( i = 0; i<3 ; i++)
                {
                    faa*=10;
                    valorfaa[i+4]=(int)faa  + 0x0030;
                    faa -=(int)faa;
                }
                valorfaa[7]=0;
                limpiar_lcd();
                comando_lcd(0x0080); //Poner cursor en posc 0
                string_lcd("Valor FAA:");
                comando_lcd(0x00C0); //Poner cursor en posc 0
                string_lcd(valorfaa);
                __delay_ms(5000);
                
                if( tdcs==1)
                {
                    
                    iniTimer1();
                    iniInterrupcionesTimer1();
                    iniPWM();
                    
                    limpiar_lcd();
                    comando_lcd(0x0080); //Poner cursor en posc 0
                    string_lcd("Preparando tDCS");
                    
                    LATBbits.LATB15=1;
                    __delay_ms(30000);
                    LATBbits.LATB15=0;
                    
                    //Inicializar tiempo
                    incrementos=0;
                    decremento=0;
                    dmin=2; umin=0; dseg=0; useg=0;
                    tiempo[2]= 'm';
                    tiempo[5]= 's';
                    tiempo[6]= 0;
                    limpiar_lcd();
                    
                    comando_lcd(0x0080);
                    string_lcd("Tiempo restante:");
                    comando_lcd(0x00C5);
                    string_lcd(tiempo);
                    __delay_ms(1000);
                    
                    activarPWM();
                    activaPerifericosTimer1();
                    actualizarTiempo=0;
                }
                else
                {
                    limpiar_lcd();
                    comando_lcd(0x0080); //Poner cursor en posc 0
                    string_lcd("No Activa tDCS");
                    __delay_ms(1000);
                    
                    activaADC();
                    limpiar_lcd();
                    comando_lcd(0x0080); //Poner cursor en posc 0
                    string_lcd("Leyendo...");
                    //LATBbits.LATB7= ~LATBbits.LATB7;
                    //activaUART();
                }
                segundos = 0;
                bandaAlfaCH0 = 0;
                bandaAlfaCH1 = 0;
            }
            else
            {
                activaADC();
                LATBbits.LATB5= ~LATBbits.LATB5;
            }
            //IEC1bits.T5IE=1;
            procesar = 0;
            
        }
        //Si tDCS esta activada
        if( tdcs == 1 )
        {
            if(actualizarTiempo)
            {
                comando_lcd(0x00C5); //Poner cursor en posc 45 - fila debajo posc 5
                tiempo[0]=dmin+0x0030;
                tiempo[1]=umin+0x0030;
                tiempo[3]=dseg+0x0030;
                tiempo[4]=useg+0x0030;
                string_lcd(tiempo);
                actualizarTiempo=0;
            }
            Nop();
        }
    }
    return (EXIT_SUCCESS);
}

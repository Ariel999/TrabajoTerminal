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
int eliminarMuestra = 0;
//Variables para temporizador
char tiempo[7];
char dmin, umin, dseg, useg, actualizarTiempo, decremento;
int incrementos;
float corriente = 0;
char detenerCorriente;
char valorCorriente[7];
float limCorriente = 0;

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
    TRISBbits.TRISB15 = 1;  //AN9 se configura como entrada
    //PORTB = 0x01;           //RB0 se configura como salida
    TRISAbits.TRISA1=1;     //Entrada Push Button
    TRISAbits.TRISA2=1;     //Entrada selecci?n de corriente
    /*PPSUnLock;
    iPPSOutput(OUT_PIN_PPS_RP0, OUT_FN_PPS_U1TX);
    PPSLock;*/
    //Inicializaci?n de los coeficientes de hamming
    HammingInit(FFT_BLOCK_LENGTH,&hamming[0]);
    
    comando_lcd(0x0080); //Poner cursor en posc 0
    string_lcd(" Inicie lectura ");
    //RPOR5bits.RP10R = 0x0003;
    int i;
    int contador=0;
    int muestrasConRuido = 0;
    detenerCorriente = 0;
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
            eliminarMuestra = 0;
            validarMuestras();
            if( eliminarMuestra == 1)
            {
                muestrasConRuido++;
            }
            else
            {
                procesarMuestras(0);
                procesarMuestras(1);
            }
            segundos++;
            
            if( segundos == SEGUNDOS_PROCESAMIENTO)
            {
                //LATBbits.LATB7= ~LATBbits.LATB7;
                bandaAlfaCH0/= (SEGUNDOS_PROCESAMIENTO - muestrasConRuido) * 5;
                bandaAlfaCH1/= (SEGUNDOS_PROCESAMIENTO - muestrasConRuido) * 5;
                
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
                
                contador++;
                if( tdcs==1 && contador>=3)
                {
                    
                    iniTimer1();
                    iniInterrupcionesTimer1();
                    iniPWM();
                    iniADCtDCS();
                    
                    limpiar_lcd();
                    comando_lcd(0x0080); //Poner cursor en posc 0
                    string_lcd("Activa tDCS");
                    
                    __delay_ms(10000);
                    
                    limpiar_lcd();
                    comando_lcd(0x0080); //Poner cursor en posc 0
                    string_lcd("Preparando tDCS");
                    
                    LATBbits.LATB5=1;
                    __delay_ms(10000);
                    LATBbits.LATB5=0;
                    limpiar_lcd();
                    comando_lcd(0x0080); //Poner cursor en posc 0
                    string_lcd("   Seleccione   ");
                    comando_lcd(0x00C0); //Poner cursor en posc 0
                    string_lcd("  cte. deseada  ");
                    __delay_ms(10000);
                    
                    if( PORTAbits.RA2 == 0 )
                    {
                        limCorriente=2;
                    }
                    else
                    {
                        limCorriente=1;
                    }
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
                    activaADC();
                    actualizarTiempo=0;
                }
                else
                {
                    if(contador>=3){
                        limpiar_lcd();
                        comando_lcd(0x0080); //Poner cursor en posc 0
                        string_lcd("No Activa tDCS");
                        __delay_ms(5000);
                    }
                    
                    activaADC();
                    limpiar_lcd();
                    comando_lcd(0x0080); //Poner cursor en posc 0
                    string_lcd("Leyendo...");
                    //LATBbits.LATB7= ~LATBbits.LATB7;
                    //activaUART();
                }
                segundos = 0;
                muestrasConRuido = 0;
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
                comando_lcd(0x00C1); //Poner cursor en posc 45 - fila debajo posc 5
                tiempo[0]=dmin+0x0030;
                tiempo[1]=umin+0x0030;
                tiempo[3]=dseg+0x0030;
                tiempo[4]=useg+0x0030;
                string_lcd(tiempo);
                comando_lcd(0x00C9);
                
                if(corriente > 0)
                {
                    valorCorriente[0]=(int)corriente + 0x0030;
                    corriente -=(int)corriente;
                }
                else
                {
                    valorCorriente[0]=0 + 0x0030;
                }
                valorCorriente[1]='.';
                for( i = 0; i<2 ; i++)
                {
                    corriente*=10;
                    valorCorriente[i+2]=(int)corriente  + 0x0030;
                    corriente -=(int)corriente;
                }
                valorCorriente[4]='m';
                valorCorriente[5]='A';
                valorCorriente[6]=0;
                string_lcd(valorCorriente);
                actualizarTiempo=0;
            }
            Nop();
        }
        //if(PORTAbits.RA2 == )
        if(detenerCorriente)
        {
            //Funcion de detenci?n
            __delay_ms(90000);
            limpiar_lcd();
            comando_lcd(0x0080); //Poner cursor en posc 0
            string_lcd("Deteniendo tDCS");
            __delay_ms(1000);
        }
        if(PORTAbits.RA1 == 1 && tdcs == 1)
        {
            //Funcion de detenci?n
        }
    }
    return (EXIT_SUCCESS);
}

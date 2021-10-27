#include <xc.h>
#include <dsp.h>
#include <pps.h>
#include <stdio.h>
#include "perifericos.h"
#include "defs.h"
#include "interrupciones.h"
#include "procesamiento.h"
#include "config.h"

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
float bandaAlfaCH0 = 0, bandaAlfaCH1 = 0;
extern const float prueba[];
extern const float prueba1[];

int main(int argc, char** argv) {
    iniTimer3();
    iniADC();
    iniUART();
    iniTimer5();
    iniInterrupcionesADC();
    iniInterrupcionesUART();
    //activaADC();
    
	//Habilitación de puertos
	TRISA = 0x0001;         //AN0 se configura como entrada
    TRISB = 0x0002;         //AN3 se configura como entrada
    PORTB = 0x01;           //RB0 se configura como salida
    PPSUnLock;
    iPPSOutput(OUT_PIN_PPS_RP0, OUT_FN_PPS_U1TX);
    PPSLock;
    //Inicialización de los coeficientes de hamming
    HammingInit(FFT_BLOCK_LENGTH,&hamming[0]);
    //RPOR5bits.RP10R = 0x0003;
    int i;
    while (1) 
    {
        if(PORTAbits.RA1 == 1 && estaActivo == 0)
        {
            activaADC();
            estaActivo = 1;
            LATBbits.LATB15= ~LATBbits.LATB15;
        }
        if(procesar == 2)
        {
            desactivaADC();

            for( i= 0; i<MUESTRAS ; i++ )
            {
                valCH0[i].real=Q15(prueba[i]);
                valCH0[i].imag=0x0000;
                valCH1[i].real=Q15(prueba1[i]);
                valCH1[i].imag=0x0000;
            }
            LATBbits.LATB7= ~LATBbits.LATB7;
            procesarMuestras(0);
            procesarMuestras(1);
            segundos++;
            
            if( segundos == SEGUNDOS_PROCESAMIENTO)
            {
                LATBbits.LATB7= ~LATBbits.LATB7;
                bandaAlfaCH0/= SEGUNDOS_PROCESAMIENTO * 5;
                bandaAlfaCH1/= SEGUNDOS_PROCESAMIENTO * 5;
                
                //Calcular el logaritmo natural del promedio
                lnCH0 = logf(bandaAlfaCH0);
                lnCH1 = logf(bandaAlfaCH1);
                if( fabsf(lnCH0) - fabsf(lnCH1) < 0)
                {
                    tdcs=1;
                }
                segundos = 0;
                bandaAlfaCH0 = 0;
                bandaAlfaCH1 = 0;
                LATBbits.LATB7= ~LATBbits.LATB7;
                activaUART();
            }
            //IEC1bits.T5IE=1;
            procesar = 0;
            activaADC();
        }
    }
    return (EXIT_SUCCESS);
}

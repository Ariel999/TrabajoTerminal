#include <xc.h>
#include <dsp.h>
#include <stdio.h>
#include "defs.h"

int contCH0 = 0, contCH1 = 0;
char adCH = 0;

extern fractcomplex valCH0[FFT_BLOCK_LENGTH]
__attribute__ ((eds, space(ymemory), aligned (FFT_BLOCK_LENGTH * 2 *2)));
extern fractcomplex valCH1[FFT_BLOCK_LENGTH]
__attribute__ ((eds, space(ymemory), aligned (FFT_BLOCK_LENGTH * 2 *2)));

extern int procesar;
extern int contPruebas;

unsigned char *chptr;

void __attribute__((interrupt, no_auto_psv))_ADC1Interrupt(void){
    switch (adCH)
	{
        case 0:	
            if( contCH0 == MUESTRAS - 1 )
            {
                valCH0[contCH0].real = ADC1BUF0;
                procesar++;
                contCH0 = 0;
            }
            else
            {
                valCH0[contCH0++].real = ADC1BUF0;
            }
			break;

		case 1:
			if( contCH1 == MUESTRAS - 1)
            {
                valCH1[contCH1].real = ADC1BUF0;
                procesar++;
                contCH1 = 0;
            }
            else
            {
                valCH1[contCH1++].real = ADC1BUF0;
            } 
			break;
            
		default:
			break;
    }
			
    adCH++; adCH&=1;
    IFS0bits.AD1IF=0;
}
void __attribute__((interrupt, no_auto_psv))_T3Interrupt(void)
{
    AD1CON1bits.SAMP = 1;
    IFS0bits.T3IF = 0;
}
void __attribute__((interrupt, no_auto_psv))_T5Interrupt(void)
{
    if( contPruebas == MUESTRAS ){
        IEC1bits.T5IE=0;
        //IEC0bits.AD1IE=1;
        //IEC0bits.T3IE=1; 
        contPruebas = 0;
    }
    else{
        //sprintf(buffer, "%f" , valCH0Float[contPruebas]);
        //chptr = (unsigned char *) &valCH0Float[contPruebas];
        chptr = (unsigned char *) &valCH0[contPruebas];
        
        //U1TXREG = *chptr++;
        //U1TXREG = *chptr++;
        U1TXREG = *chptr++;
        U1TXREG = *chptr;
        
        contPruebas++;
    }
    IFS1bits.T5IF = 0;
}
void __attribute__ ((interrupt, no_auto_psv)) _U1TXInterrupt(void) 
{
	IFS0bits.U1TXIF = 0;
    LATBbits.LATB5= ~LATBbits.LATB5;
}
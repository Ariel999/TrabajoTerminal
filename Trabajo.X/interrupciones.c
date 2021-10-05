#include <xc.h>
#include <dsp.h>
#include <stdio.h>
#include "defs.h"

int contCH0 = 0, contCH1 = 0;
char adCH = 0;

extern fractcomplex valCH0[FFT_BLOCK_LENGTH]
__attribute__ ((eds, space(ymemory), aligned (FFT_BLOCK_LENGTH * 2 *2)));

extern fractional valCH1[MUESTRAS];
//extern fractional valCH0[MUESTRAS], valCH1[MUESTRAS];
extern int procesar;
extern int contPruebas;
extern float valCH0Float[MUESTRAS], valCH1Float[MUESTRAS];
unsigned char *chptr;
extern float epochs[MUESTRAS];

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
                valCH1[contCH1] = ADC1BUF0;
                procesar++;
                contCH1 = 0;
            }
            else
            {
                valCH1[contCH1++] = ADC1BUF0;
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
        chptr = (unsigned char *) &epochs[contPruebas];
        
        U1TXREG = *chptr++;
        U1TXREG = *chptr++;
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
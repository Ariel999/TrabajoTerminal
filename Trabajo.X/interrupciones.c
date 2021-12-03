#include <xc.h>
#include <dsp.h>
#include <stdio.h>
#include <p33FJ64GP802.h>
#include "defs.h"
#include "perifericos.h"
#include "lcd.h"

int contCH0 = 0, contCH1 = 0;
char adCH = 0;
extern int tdcs;
extern float corriente;
extern char detenerCorriente;
extern float limCorriente;

extern fractcomplex valCH0[FFT_BLOCK_LENGTH]
__attribute__ ((eds, space(ymemory), aligned (FFT_BLOCK_LENGTH * 2 *2)));
extern fractcomplex valCH1[FFT_BLOCK_LENGTH]
__attribute__ ((eds, space(ymemory), aligned (FFT_BLOCK_LENGTH * 2 *2)));

extern int procesar;
extern int contPruebas;
extern float lnCH0, lnCH1;
unsigned char *chptr;
extern fractional output[FFT_BLOCK_LENGTH];

void __attribute__((interrupt, no_auto_psv))_ADC1Interrupt(void){
    if( tdcs == 1)
    {
        corriente = ADC1BUF0 * 0.00322265625;
        
        if(corriente >= limCorriente)
        {
            limpiar_lcd();
            comando_lcd(0x0080); //Poner cursor en posc 0
            string_lcd("MaxCor...");
            detenerCorriente = 1;
            tdcs = 0;
            desactivaADC();
        }
    }
    else
    {
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
    }
    IFS0bits.AD1IF=0;
}
void __attribute__((interrupt, no_auto_psv))_T3Interrupt(void)
{
    AD1CON1bits.SAMP = 1;
    IFS0bits.T3IF = 0;
}
void __attribute__((interrupt, no_auto_psv))_T5Interrupt(void)
{
    if( contPruebas == 2 ){
        desactivaUART();
        contPruebas = 0;
    }
    else if( contPruebas == 0 )
    {
        chptr = (unsigned char *) &lnCH0;
        
        U1TXREG = *chptr++;
        U1TXREG = *chptr++;
        U1TXREG = *chptr++;
        U1TXREG = *chptr;
        contPruebas++;
    }
    else{
        chptr = (unsigned char *) &lnCH1;
        
        U1TXREG = *chptr++;
        U1TXREG = *chptr++;
        U1TXREG = *chptr++;
        U1TXREG = *chptr;
        contPruebas++;
        //sprintf(buffer, "%f" , valCH0Float[contPruebas]);
        //chptr = (unsigned char *) &valCH0Float[contPruebas];
        //chptr = (unsigned char *) &valCH0[contPruebas];
        
        //U1TXREG = *chptr++;
        //U1TXREG = *chptr++;
        //U1TXREG = *chptr++;
        //U1TXREG = *chptr;
        /*chptr = (unsigned char *) &valCH1[contPruebas].real;
        
        //U1TXREG = *chptr++;
        //U1TXREG = *chptr++;
        U1TXREG = *chptr++;
        U1TXREG = *chptr;*/
        
        //contPruebas++;
    }
    IFS1bits.T5IF = 0;
}
void __attribute__ ((interrupt, no_auto_psv)) _U1TXInterrupt(void) 
{
	IFS0bits.U1TXIF = 0;
    LATBbits.LATB5= ~LATBbits.LATB5;
}
void __attribute__ ((__interrupt__, no_auto_psv)) _T2Interrupt(void)
{
    IFS0bits.T2IF= 0;
}


extern char dmin, umin, dseg, useg, actualizarTiempo, decremento;
extern int incrementos;
void __attribute__ ((__interrupt__, no_auto_psv)) _T1Interrupt(void){
    
    LATBbits.LATB5=~LATBbits.LATB5;
    if(incrementos!=61){
       incrementos++;
       OC1RS +=69;
    }else if(dmin==0 && umin==1 && dseg==0 && useg==0){ //01:00seg
        decremento=1;
    }
    if(decremento){
        OC1RS -=69;
    }
    
    if(useg!=0){
        useg--;
    }else{
        if(dseg!=0){
            dseg--;
            useg=9;
        }else{
            if(umin!=0){
                umin--;
                dseg=5;
                useg=9;
            }else{
                if(dmin!=0){
                    dmin--;
                    umin=9;
                    dseg=5;
                    useg=9;
                }else{
                    OC1RS =0x0000; //0% duty cycle
                    T1CONbits.TON = 0; //Detiene el contador del Timer1
                    IEC0bits.T1IE = 0; //Deshabilita la interrupci?n Timer1
                    IFS0bits.T1IF = 0; //Apaga la bandera de la interrupci?n
                    incrementos=0;
                    decremento=0;
                    limpiar_lcd();
                    //bf_lcd();
                    comando_lcd(0x0080);
                    string_lcd("Finalizado...");
                }
            }
        }
    }
    actualizarTiempo=1;
    /* reset Timer 1 interrupt flag */
 	IFS0bits.T1IF = 0;
}

#include <xc.h>
#include <dsp.h>
#include "defs.h"

void iniTimer( void )
{
    TMR3    = 0X0000;
    T3CON   = 0X0000;
    //PR3     = 7197;
    PR3     = 14394;
}
void iniTimer5( void )
{
    TMR5    = 0X0000;
    T5CON   = 0X0000;
    //PR5     = 28789;
    PR5     = 57578;
    
    IFS1bits.T5IF=0;
    T5CONbits.TON = 1;
}
void iniADC( void )
{
    AD1CHS0=0x0000;                 //Se selecciona AN0 para el CH0
    AD1CHS123bits.CH123SA=1;        //Se selecciona AN3 para el CH1
    AD1CHS123bits.CH123SB=1;       
    
    AD1PCFGL = 0xFFF6;              //Habilita AN0 y AN3 como analogicos
    AD1CON1bits.AD12B = 0;          //Habilita el convertidor en 10 bits
    AD1CON1bits.SIMSAM = 1;         //Habilita el muestreo simultaneo
    AD1CON1bits.ASAM = 0;           //Muestreo comienza cuando se habilita el bit SAMP
    AD1CON2bits.VCFG = 0b000;       //Voltaje de referencia Vref: AVdd, AVss
    AD1CON3bits.ADCS = 3;           //Tad = 3*Tcy = 3 (542 ns)
    AD1CON2bits.CHPS = 0b01;        //Convierte el CH0 and CH1
    AD1CON1bits.SSRC = 0b010;       //Habilita el GP timer (Timer3 for ADC1)
    AD1CON3bits.SAMC = 8;           //Sample 8 TAD
    AD1CON1bits.FORM = 0b11;        // Formato de salida de datos en entero sin signo
    
}
void iniInterrupciones( void )
{
    IFS0bits.AD1IF=0;               //Se habilita la bandera del ADC
    IFS0bits.T3IF=0;                //Se habilita la bandera del Timer3
    IFS0bits.U1TXIF=0;
    IPC3bits.AD1IP=7;               //Prioridad del ADC
    IEC0bits.AD1IE=1;               //Se habilita la interrupcion del ADC
    IEC0bits.T3IE=1;                //Se habilita la interrupcion del Timer3
    IEC0bits.U1TXIE=1;
    
}
void activaPerifericos( void )
{
    AD1CON1bits.ADON = 1;           //Enciende el ADC
    T3CONbits.TON =1;               //Enciende el Timer3
    U1MODEbits.UARTEN=1;
    U1STAbits.UTXEN=1;
}
void iniUART( void )
{
    U1MODEbits.ABAUD = 1;
    //U1STAbits.UTXISEL0 = 1;
    U1BRG = 11; 
}

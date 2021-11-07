#include <xc.h>
#include <dsp.h>
#include "defs.h"

void enLPOSC(void);
void iniPerifericos(void)
{
    PORTB = 0;
    Nop();
    LATB = 0;
    Nop();
    TRISB = 0;
    Nop();
    AD1PCFGL = 0XFFFF; //No hay entradas anal?gicas
    PORTA = 0;
    Nop();
    LATA = 0;
    Nop();
    TRISA = 0;
    Nop();
}
void iniTimer1(void)
{
	//Pines SOSCI y SOSCO configurados como entradas
    TRISBbits.TRISB4=1; //SOSCI
    TRISAbits.TRISA4=1; //SOSCO
    Nop();
	
    T1CON = 0;          // Resetear el Timer1
    //PR1 = 0x0005;
	PR1 = 0x8000;       // Periodo de registro Timer1 = 32768 (Frecuencia oscilador externo)
    T1CONbits.TCS = 1;  // Seleccionar para Timer1 Reloj Externo
    enLPOSC();          //Habilitar el oscilador secundario
}
void iniTimer3( void )
{
    TMR3    = 0X0000;
    T3CON   = 0X0000;
    PR3     = 14394; //Frecuencia de 256 Hz
}
void iniTimer5( void )
{
    TMR5    = 0X0000;
    T5CON   = 0X0000;
    PR5     = 28789;
    
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
    AD1CON1bits.FORM = 0b11;        //Formato de salida de datos en fractional con signo
    
}
void iniADCtDCS( void )
{
    AD1CHS0=0x0000;                 //Se selecciona AN0 para el CH0
    
    AD1PCFGL = 0xFFFE;              //Habilita AN0 y AN3 como analogicos
    AD1CON1bits.AD12B = 0;          //Habilita el convertidor en 10 bits
    AD1CON1bits.SIMSAM = 0;         //Habilita el muestreo simultaneo
    AD1CON1bits.ASAM = 0;           //Muestreo comienza cuando se habilita el bit SAMP
    AD1CON2bits.VCFG = 0b000;       //Voltaje de referencia Vref: AVdd, AVss
    AD1CON3bits.ADCS = 3;           //Tad = 3*Tcy = 3 (542 ns)
    AD1CON2bits.CHPS = 0b00;        //Convierte el CH0 and CH1
    AD1CON1bits.SSRC = 0b010;       //Habilita el GP timer (Timer3 for ADC1)
    AD1CON3bits.SAMC = 8;           //Sample 8 TAD
    AD1CON1bits.FORM = 0b00;         //Formato de salida de datos en fractional con signo
    
}
void iniUART( void )
{
    U1MODEbits.ABAUD = 1;
    //U1STAbits.UTXISEL0 = 1;
    U1BRG = 5; 
}
void iniInterrupcionesTimer1( void )
{
    //TIMER1
    IFS0bits.T1IF = 0;      // Habilita/Apaga la bandera del Timer1
    //IPC0bits.T1IP = 4;      // Prioridad nivel 4 para interrupcion Timer1
 	IEC0bits.T1IE = 1;      // Se habilita la interrupci?n Timer1
    
}
void iniInterrupcionesADC( void )
{
    IFS0bits.AD1IF=0;               //Se habilita la bandera del ADC
    IFS0bits.T3IF=0;                //Se habilita la bandera del Timer3
    IFS0bits.U1TXIF=0;              //Se habilita la bandera del UART
    //IPC3bits.AD1IP=7;               //Prioridad del ADC
    IEC0bits.AD1IE=1;               //Se habilita la interrupcion del ADC
    IEC0bits.T3IE=1;                //Se habilita la interrupcion del Timer3
    IEC0bits.U1TXIE=1;              //Se habilita la interrupcion de escritura del UART
    
}
void iniInterrupcionesUART( void )
{
    IFS0bits.U1TXIF=0;              //Se habilita la bandera del UART
    IEC0bits.U1TXIE=1;              //Se habilita la interrupcion de escritura del UART
    IFS1bits.T5IF=0;                //Se habilita la bandera del Timer5
    IEC1bits.T5IE=1;                //Se habilita la interrupcion del Timer5
}
void activaPerifericosTimer1( void )
{
    TMR1=0;
    T1CONbits.TON = 1;      //Enciende el Timer1, inicia el conteo
}
void activaADC( void )
{
    AD1CON1bits.ADON = 1;           //Enciende el ADC
    T3CONbits.TON =1;               //Enciende el Timer3
}
void desactivaADC( void )
{
    AD1CON1bits.ADON = 0;
    T3CONbits.TON =0;
}
void activaUART( void )
{
    U1MODEbits.UARTEN = 1;            //Enciende el UART
    U1STAbits.UTXEN = 1;              //Enciende la escritura del UART
    T5CONbits.TON = 1;
}
void desactivaUART( void )
{
    T5CONbits.TON = 0;
}

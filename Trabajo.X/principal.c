#include <xc.h>
#include <dsp.h>
#include <pps.h>
#include <stdio.h>
#include "perifericos.h"
#include "defs.h"
#include "interrupciones.h"
#include "procesamiento.h"

// DSPIC33FJ64GP802 Configuration Bit Settings
// FBS
#pragma config BWRP = WRPROTECT_OFF     // Boot Segment Write Protect (Boot Segment may be written)
#pragma config BSS = NO_FLASH           // Boot Segment Program Flash Code Protection (No Boot program Flash segment)
#pragma config RBS = NO_RAM             // Boot Segment RAM Protection (No Boot RAM)
// FSS
#pragma config SWRP = WRPROTECT_OFF     // Secure Segment Program Write Protect (Secure segment may be written)
#pragma config SSS = NO_FLASH           // Secure Segment Program Flash Code Protection (No Secure Segment)
#pragma config RSS = NO_RAM             // Secure Segment Data RAM Protection (No Secure RAM)
// FGS
#pragma config GWRP = OFF               // General Code Segment Write Protect (User program memory is not write-protected)
#pragma config GSS = HIGH               // General Segment Code Protection (High Security Code Protection is Enabled)
// FOSCSEL
#pragma config FNOSC = FRCPLL           // Oscillator Mode (Internal Fast RC (FRC) w/ PLL)
#pragma config IESO = ON                // Internal External Switch Over Mode
// FOSC
#pragma config POSCMD = NONE            // Primary Oscillator Source (Primary Oscillator Disabled)
#pragma config OSCIOFNC = ON            // OSC2 Pin Function (OSC2 pin has digital I/O function)
#pragma config IOL1WAY = ON             // Peripheral Pin Select Configuration (Allow Only One Re-configuration)
#pragma config FCKSM = CSDCMD           // Clock Switching and Monitor (Both Clock Switching and Fail-Safe Clock Monitor are disabled)
// FWDT
#pragma config WDTPOST = PS32768        // Watchdog Timer Postscaler (1:32,768)
#pragma config WDTPRE = PR128           // WDT Prescaler (1:128)
#pragma config WINDIS = OFF             // Watchdog Timer Window (Watchdog Timer in Non-Window mode)
#pragma config FWDTEN = OFF             // Watchdog Timer Enable (Watchdog timer enabled/disabled by user software)
// FPOR
#pragma config FPWRT = PWR128           // POR Timer Value (128ms)
#pragma config ALTI2C = OFF             // Alternate I2C  pins (I2C mapped to SDA1/SCL1 pins)
// FICD
#pragma config ICS = PGD2               // Comm Channel Select (Communicate on PGC2/EMUC2 and PGD2/EMUD2)
#pragma config JTAGEN = OFF             // JTAG Port Enable (JTAG is Disabled)

fractional valCH0[MUESTRAS], valCH1[MUESTRAS];
int procesar = 0;
int contPruebas = 0;

int main(int argc, char** argv) {
    /*
     * Configuración para la frecuencia del oscilador
     * FOSC = FIN * (M/(N1*N2))
     */
	CLKDIVbits.PLLPRE = 0;          //N1=2
	CLKDIVbits.PLLPOST = 0;         //N2=2
    //PLLFBDbits.PLLDIV = 0;          //M=2
    PLLFBDbits.PLLDIV = 6;
    /*
     * FOSC = 7.37MHz * (2/(2*2)) = 3.685MHz
     * FCY = FOSC / 2 = 1.8425MHz
     */
    
    iniTimer();
    iniADC();
    iniUART();
    iniTimer5();
    iniInterrupciones();
    activaPerifericos();
    
	//Habilitación de puertos
	TRISA = 0x0001;         //AN0 se configura como entrada
    TRISB = 0x0002;         //AN3 se configura como entrada
    PORTB = 0x01;
    PPSUnLock;
    iPPSOutput(OUT_PIN_PPS_RP0, OUT_FN_PPS_U1TX);
    PPSLock;
    //RPOR5bits.RP10R = 0x0003;
    IEC0bits.AD1IE=0;
    IEC0bits.T3IE=0;
    
    while (1) 
    {
        LATBbits.LATB7= ~LATBbits.LATB7;
        procesarEPOC();
        LATBbits.LATB7= ~LATBbits.LATB7;
        IEC1bits.T5IE=1;
        while(1)
        {
            Nop();
        }
        if(procesar == 2)
        {
            //U1TXREG = valCH0[1];
            //U1TXREG = valCH0[1]>>8;
            IEC0bits.AD1IE=0;
            IEC0bits.T3IE=0;
            
            convertirDatos(0);
            convertirDatos(1);
            
            procesarEPOC();
            
            IEC1bits.T5IE=1;
            
            /*for( i = 0 ; i < SAMPLES ; i++)
            {
                U1TXREG = valCH0[i];
                U1TXREG = valCH0[i]>>8;
            }*/
            //procesarMuestras();
            procesar = 0;
        }
    }
    return (EXIT_SUCCESS);
}

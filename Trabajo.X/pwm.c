#include "xc.h"
#include <dsp.h>
#include <stdio.h>
#include <p33FJ64GP802.h>
#include "defs.h"
#include <pps.h>

void iniPWM(void){
	//Remapear salida del comparador OC1 en pin RB14
	PPSUnLock;
    iPPSOutput(OUT_PIN_PPS_RP14, OUT_FN_PPS_OC1);
    PPSLock;
	
	//Configuración registros
	//Fosc=7.37MHz, Frecuencia PWM=900Hz - 1kHz, TIMER2, OC1
    OC1CON = 0x0000; // Apaga la salida del comparador 1
    OC1R = 0x0000; // El registro del comparador 1 inicializado en 0
    OC1RS = 0x0000; // El registro secundario del comparador 1 inicializado en 0
    OC1CON = 0x0006; // Selecciona el modo de comparación de OC1CON como PWM - OCM<2:0>=110
    
	//Timer2
    PR2 = 0x0FFF; // PR2 con 4095 o 0FFF
    T2CON=0x0000; //Selecciona oscilador interno
    TMR2=0; //Iniciliaza el contador
}

void activarPWM(void){
	IPC1bits.T2IP = 1; // Prioridad nivel 1 para interrupcion Timer2
    IFS0bits.T2IF = 0; // Limpia la bandera del Timer2
    IEC0bits.T2IE = 1; // Se habilita la interrupción Timer2
    T2CONbits.TON = 1; // Enciende el Timer2, inicia el conteo
}
#include "xc.h"
#include <dsp.h>
#include <stdio.h>
#include <p33FJ64GP802.h>
#include "defs.h"
#include "lcd.h"

// Pines de control 
#define  RW  LATBbits.LATB0       // LCD R/W signal
#define  RS  LATBbits.LATB2      // LCD RS signal
#define  E   LATBbits.LATB3       // LCD E signal 
// Pines de datos; RB6 (D0)- RB13(D7)
// Corrimiento de variable
#define CORR 6 //D7 - RB13


void retardo15ms(void);

void ini_lcd(void){
    //Secuencia de inicialización
    retardo15ms();
    comando_lcdNoBF(0x0030);
    retardo15ms();
    comando_lcdNoBF(0x0030);
    retardo15ms();
    comando_lcdNoBF(0x0030);
    //Configuración
    //bf_lcd();
    comando_lcd(0x0038); //DL(1) modo 8 bits, N(1) 2 líneas del LCD, F(0) fuente 5x7
    //bf_lcd();
    comando_lcd(0x0008); //display apagado, cursor apagado, parpadeo apagado
    //bf_lcd();
    comando_lcd(0x0001); //Clear, limpiar lcd
    //bf_lcd();
    comando_lcd(0x0006); //Conf. Entrada. Incremento (derecha nuevos valores) sin movimiento.
    //bf_lcd();
    //comando_lcd(0x000F); //display encendido, cursor encendido, parpadeo encendido
    comando_lcd(0x000C); //display encendido, cursor apagado, parpadeo apagado
}
void comando_lcdNoBF(short comando){
	RS=0; //Seleccionar modo comando
    Nop();
    RW=0; //Modo Escritura
    Nop();
    E=1; //Habilitar escritura
    Nop();
    comando=comando<<CORR; //Corrimiento para que el comando se copie en los bits de datos
    LATB&=0xC03F; //AND para preparar los bits de datos, hacer 0's
    LATB|=comando; //OR para cambiar bits de datos
    Nop();
    E=0;
}
void comando_lcd(short comando){
	bf_lcd();
    RS=0; //Seleccionar modo comando
    Nop();
    RW=0; //Modo Escritura
    Nop();
    E=1; //Habilitar escritura
    Nop();
    comando=comando<<CORR; //Corrimiento para que el comando se copie en los bits de datos
    LATB&=0xC03F; //AND para preparar los bits de datos, hacer 0's
    LATB|=comando; //OR para cambiar bits de datos
    Nop();
    E=0;
}

void dato_lcd(short dato){
	bf_lcd();
    RS=1; //Seleccionar modo comando
    Nop();
    RW=0; //Modo Escritura
    Nop();
    E=1; //Habilitar escritura
    Nop();
    dato=dato<<CORR; //Corrimiento para que el comando se copie en los bits de datos
    LATB&=0xC03F; //AND para preparar los bits de datos, hacer 0's
    LATB|=dato; //OR para cambiar bits de datos
    Nop();
    E=0;
}

void bf_lcd(void){
    TRISBbits.TRISB13=1; //Poner como entrada para leer la BF en RB13|D7
    RS=0; //Seleccionar modo registro
    Nop();
    RW=1; //Seleccionar lectura
    Nop();
    E=1;  //Habilitar
    Nop();
    while(PORTBbits.RB13); //Si la bandera está ocupada (BF=1)) espera a que se desocupe
    E=0;
    Nop();
    TRISBbits.TRISB13=0; //Poner como salida RB13|D7
}

void string_lcd(char cadena[]){
    int i=0;
    while(cadena[i]!=0){
        //bf_lcd();
        dato_lcd(cadena[i]);
        //dato_lcd(0x0048);
        i++;
    }
}

void limpiar_lcd(void){
    //bf_lcd();
    comando_lcd(0x0001); //Clear, limpiar lcd
}
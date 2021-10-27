/* 
 * File:   perifericos.h
 * Author: Ariel
 *
 * Created on July 18, 2021, 12:50 PM
 */

#ifndef PERIFERICOS_H
#define	PERIFERICOS_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

void iniTimer3( void );
void iniTimer5( void );
void iniADC( void );
void iniUART( void );
void iniInterrupcionesADC( void );
void iniInterrupcionesUART( void );
void activaADC( void );
void desactivaADC( void );
void activaUART( void );
void desactivaUART( void );

#endif	/* PERIFERICOS_H */


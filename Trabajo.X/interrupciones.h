/* 
 * File:   interrupciones.h
 * Author: Ariel
 *
 * Created on July 18, 2021, 12:55 PM
 */

#ifndef INTERRUPCIONES_H
#define	INTERRUPCIONES_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

void __attribute__((interrupt, no_auto_psv))_T3Interrupt(void);
void __attribute__((interrupt, no_auto_psv))_T5Interrupt(void);
void __attribute__((interrupt, no_auto_psv))_ADC1Interrupt(void);
void __attribute__ ((interrupt, no_auto_psv)) _U1TXInterrupt(void);
#endif	/* INTERRUPCIONES_H */


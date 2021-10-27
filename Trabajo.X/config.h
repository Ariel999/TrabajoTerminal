/* 
 * File:   config.h
 * Author: Ariel
 *
 * Created on October 27, 2021, 12:02 PM
 */
#include <xc.h>
#ifndef CONFIG_H
#define	CONFIG_H

#ifdef	__cplusplus
extern "C" {
#endif

#define FOSC 7370000LL // frecuencia del Oscilador
#define FCY (FOSC/2)
#include <libpic30.h>

#ifdef	__cplusplus
}
#endif

#endif	/* CONFIG_H */


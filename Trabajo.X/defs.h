#ifndef DEFS_H
#define DEFS_H

#define MUESTRAS 256
#define LOG2_BLOCK_LENGTH 8
#define FFT_BLOCK_LENGTH 256
#define FRECUENCIA_MUESTREO 256
#define SEGUNDOS_PROCESAMIENTO 60

#define FFTTWIDCOEFFS_IN_PROGMEM     /*<---Comment out this line of the code if twiddle factors (coefficients) */
                                    /*reside in data memory (RAM) as opposed to Program Memory */
                                    /*Then remove the call to "TwidFactorInit()" and add the twiddle factor*/
                                    /*coefficient file into your Project. An example file for a 256-pt FFT*/
                                    /*is provided in this Code example */
#endif
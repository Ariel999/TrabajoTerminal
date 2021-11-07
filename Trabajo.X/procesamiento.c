#include <xc.h>
#include <dsp.h>
#include <math.h>
#include "defs.h"
#define M_PI 3.14159265358979323846

typedef struct{
	float real;
	float imag;
} complejo;
extern fractcomplex valCH0[FFT_BLOCK_LENGTH]
__attribute__ ((eds, space(ymemory), aligned (FFT_BLOCK_LENGTH * 2 *2)));
extern fractcomplex valCH1[FFT_BLOCK_LENGTH]
__attribute__ ((eds, space(ymemory), aligned (FFT_BLOCK_LENGTH * 2 *2)));

extern fractional hamming[FFT_BLOCK_LENGTH] 	
 __attribute__ ((section (".xbss, bss, xmemory"), aligned (FFT_BLOCK_LENGTH* 2 *2)));

 #ifndef FFTTWIDCOEFFS_IN_PROGMEM
 fractcomplex twiddleFactors[FFT_BLOCK_LENGTH/2] 	
 __attribute__ ((section (".xbss, bss, xmemory"), aligned (FFT_BLOCK_LENGTH*2)));
 #else
 extern const fractcomplex twiddleFactors[FFT_BLOCK_LENGTH/2]	/* Twiddle Factor array in Program memory */
 __attribute__ ((space(prog), aligned (FFT_BLOCK_LENGTH*2)));
 #endif

int	peakFrequencyBin = 0;				/* Declare post-FFT variables to compute the */
unsigned long peakFrequency = 0;
extern float lnCH0, lnCH1;
extern float bandaAlfaCH0, bandaAlfaCH1;
fractional output[FFT_BLOCK_LENGTH];

void procesarMuestras( char canal )
{
    int i = 0;
    fractional magnitudAlfa;
    
    //Ventana de Hamming
    if( canal == 0 )
        VectorWindow(FFT_BLOCK_LENGTH,&valCH0[0].real,&valCH0[0].real,&hamming[0]);
    else if( canal == 1 )
        VectorWindow(FFT_BLOCK_LENGTH,&valCH1[0].real,&valCH1[0].real,&hamming[0]);
    
    //Factores de giro para la FFT
    #ifndef FFTTWIDCOEFFS_IN_PROGMEM					
    TwidFactorInit (LOG2_BLOCK_LENGTH, &twiddleFactors[0], 0);	
    #endif
    
    //Corrimiento para mantener datos entre -0.5 y 0.5
    for ( i = 0; i < FFT_BLOCK_LENGTH; i++ )
    {
        if( canal == 0 )
        {
            valCH0[i].real = valCH0[i].real >> 1 ;		
            valCH0[i].imag = 0;	
        }
        else if( canal == 1 )
        {
            valCH1[i].real = valCH1[i].real >> 1 ;		
            valCH1[i].imag = 0;
        }
    }
    
    //FFT
    #ifndef FFTTWIDCOEFFS_IN_PROGMEM
    FFTComplexIP (LOG2_BLOCK_LENGTH, &sigCmpx[0], &twiddleFactors[0], COEFFS_IN_DATA);
    #else
    if( canal == 0 )
        FFTComplexIP (LOG2_BLOCK_LENGTH, &valCH0[0], (fractcomplex *) __builtin_psvoffset(&twiddleFactors[0]), (int) __builtin_psvpage(&twiddleFactors[0]));
    else if( canal == 1 )
        FFTComplexIP (LOG2_BLOCK_LENGTH, &valCH1[0], (fractcomplex *) __builtin_psvoffset(&twiddleFactors[0]), (int) __builtin_psvpage(&twiddleFactors[0]));
    #endif
    
    //Reordenar los datos de la FFT
    if ( canal == 0 )
        BitReverseComplex (LOG2_BLOCK_LENGTH, &valCH0[0]);
    else if( canal == 1 )
        BitReverseComplex (LOG2_BLOCK_LENGTH, &valCH1[0]);
    
    //Magnitud a la FFT
    if ( canal == 0 )
        SquareMagnitudeCplx(FFT_BLOCK_LENGTH, &valCH0[0], output);
    else if( canal == 1 )
        SquareMagnitudeCplx(FFT_BLOCK_LENGTH, &valCH1[0], output);
    
    
    VectorMax(FFT_BLOCK_LENGTH/2, output, &peakFrequencyBin);
    
    peakFrequency = peakFrequencyBin*(FRECUENCIA_MUESTREO/FFT_BLOCK_LENGTH);
    
    //Acumular el promedio en la banda alfa
    magnitudAlfa = output[8] + output[9] + output[10] + output[11] + output[12];
    //magnitudAlfa /= 5;
    if( canal == 0)
        bandaAlfaCH0 += ((float)magnitudAlfa) / (32768);
    else if( canal == 1 )
        bandaAlfaCH1 += ((float)magnitudAlfa) / (32768);
    //while(1);
    
    return;
}
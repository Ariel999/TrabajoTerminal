#include <xc.h>
#include <dsp.h>
#include "defs.h"

extern fractcomplex sigCmpx[FFT_BLOCK_LENGTH]
__attribute__ ((eds, space(ymemory), aligned (FFT_BLOCK_LENGTH * 2 *2)));

 #ifndef FFTTWIDCOEFFS_IN_PROGMEM
 fractcomplex twiddleFactors[FFT_BLOCK_LENGTH/2] 	
 __attribute__ ((section (".xbss, bss, xmemory"), aligned (FFT_BLOCK_LENGTH*2)));
 #else
 extern const fractcomplex twiddleFactors[FFT_BLOCK_LENGTH/2]	/* Twiddle Factor array in Program memory */
 __attribute__ ((space(prog), aligned (FFT_BLOCK_LENGTH*2)));
 #endif
 
extern fractional valCH0[SAMPLES], valCH1[SAMPLES];
float valCH0Float[SAMPLES], valCH1Float[SAMPLES];

fractional output[FFT_BLOCK_LENGTH/2];
float var;

void procesarMuestras( )
{
    /*
    int i = 0;
    #ifndef FFTTWIDCOEFFS_IN_PROGMEM					
    TwidFactorInit (LOG2_BLOCK_LENGTH, &twiddleFactors[0], 0);	
    #endif
    
    for ( i = 0; i < FFT_BLOCK_LENGTH; i++ )
            sigCmpx[i].real = valCH0[i] >> 1 ;		
            sigCmpx[i].imag = 0;			
    }
    #ifndef FFTTWIDCOEFFS_IN_PROGMEM
    FFTComplexIP (LOG2_BLOCK_LENGTH, &sigCmpx[0], &twiddleFactors[0], COEFFS_IN_DATA);
    #else
    FFTComplexIP (LOG2_BLOCK_LENGTH, &sigCmpx[0], (fractcomplex *) __builtin_psvoffset(&twiddleFactors[0]), (int) __builtin_psvpage(&twiddleFactors[0]));
    #endif
    
    BitReverseComplex (LOG2_BLOCK_LENGTH, &sigCmpx[0]);
    
    SquareMagnitudeCplx(FFT_BLOCK_LENGTH/2, &sigCmpx[0], output);*/
    
    return;
}
void convertirDatos(char canal)
{
    int i = 0;
    for( i = 0; i < SAMPLES; i++ )
    {
        if( canal == 0 )
        {
            if( (valCH0[i] & 0x8000) == 0x8000)
            {
                var = ((~(valCH0[i] & 0x7FFF)) >> 6) & 0x01FF;
                valCH0Float[i] = - var * 0.00322265625;
            }
            else
            {
                var = (valCH0[i] >> 6);
                valCH0Float[i] = var * 0.00322265625;//0.00322265625
            }
        }
        else
        {
            if( (valCH1[i] & 0x8000) == 0x8000)
            {
                var = ((~(valCH1[i] & 0x7FFF)) >> 6) & 0x01FF;
                valCH1Float[i] = - var * 0.00322265625;
            }
            else
            {
                var = (valCH1[i] >> 6);
                valCH1Float[i] = var * 0.00322265625;
            }
            
        }
    }
}

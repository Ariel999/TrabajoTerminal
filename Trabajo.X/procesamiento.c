#include <xc.h>
#include <dsp.h>
#include "defs.h"
 
extern fractional valCH0[SAMPLES], valCH1[SAMPLES];
float valCH0Float[SAMPLES], valCH1Float[SAMPLES];

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
void procesarEPOC( void )
{
    return;
}

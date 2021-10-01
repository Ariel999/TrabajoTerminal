#include <xc.h>
#include <dsp.h>
#include <math.h>
#include "defs.h"
#define M_PI 3.14159265358979323846
 
extern fractional valCH0[MUESTRAS], valCH1[MUESTRAS];
float valCH0Float[MUESTRAS], valCH1Float[MUESTRAS];
float epochs[MUESTRAS];
float var;
const float prueba[] = 
{
    44.346802,0.195400,0.195400,0.195400,0.195400,0.195400,1.758200,0.976800,
    -2.149000,-2.539700,1.758200,5.665400,9.963400,6.446900,-2.930400,
    -14.652000,-21.684999,-22.857100,-22.466400,-25.201500,-21.294300,-13.089100,
    -9.963400,-6.446900,0.976800,4.884000,7.619000,8.009800,9.572600,
    10.744800,11.526300,12.698400,10.354100,6.446900,6.837600,3.321100,
    -0.976800,0.586100,4.102600,1.367500,1.367500,2.149000,0.195400,
    -3.711800,-4.493300,-5.665400,-6.446900,-2.930400,-2.539700,-4.102600,
    -2.149000,2.930400,4.102600,6.056200,10.744800,16.605600,15.042700,
    13.870600,16.214899,18.949900,20.903500,21.294300,17.777800,12.307700,
    9.963400,7.619000,2.539700,-1.758200,-4.493300,-9.572600,-13.870600,
    -9.181900,-3.711800,-1.367500,3.711800,10.354100,15.042700,20.122101,
    24.029301,21.294300,20.903500,22.466400,19.340700,15.042700,14.652000,
    14.261300,10.354100,6.056200,2.930400,-1.367500,-7.619000,-9.963400,
    -8.009800,-4.493300,0.195400,2.149000,0.195400,2.149000,7.228300,
    11.135500,12.307700,16.214899,17.777800,13.089100,9.181900,6.056200,
    2.149000,-0.586100,-2.930400,-4.493300,-8.400500,-11.526300,-14.261300,
    -20.903500,-22.857100,-19.340700,-21.294300,-20.512800,-14.652000,-9.181900,
    -10.354100,-11.917000,-13.870600,-15.824200,-15.042700,-13.089100,-13.479900,
    -15.042700,-16.214899,-21.294300,-25.201500,-23.247900,-17.387100,-16.214899,
    -17.387100,-19.340700,-22.075701,-29.499399,-33.797298,-33.406601,-33.797298,
    -29.890100,-25.201500,-23.247900,-19.731400,-14.652000,-16.996300,-22.466400,
    -23.638599,-22.075701,-22.466400,-22.075701,-22.075701,-24.810699,-31.452999,
    -37.313801,-42.393200,-47.472500,-50.988998,-56.849800,-61.538502,-64.273499,
    -63.492100,-65.445702,-68.180702,-67.790001,-63.492100,-61.147701,-56.459099,
    -53.724098,-50.988998,-54.505501,-58.803398,-62.710602,-63.882801,-62.710602,
    -63.492100,-63.882801,-66.227097,-67.008499,-72.087898,-77.557999,-79.511597,
    -77.557999,-77.948700,-77.167297,-72.869400,-70.134300,-65.054901,-58.021999,
    -51.770500,-46.691101,-41.221001,-40.830299,-43.174599,-42.393200,-36.532398,
    -38.486000,-42.783901,-46.300400,-53.333302,-63.101299,-70.134300,-74.822998,
    -80.683800,-83.028099,-85.372398,-91.233200,-90.451797,-86.935303,-88.888901,
    -89.670303,-87.325996,-83.028099,-80.683800,-78.730202,-74.041496,-71.697197,
    -73.650803,-72.478600,-72.869400,-74.041496,-74.822998,-79.511597,-88.498199,
    -95.531097,-99.829102,-106.862000,-113.894997,-117.411499,-117.020798,-118.583603,
    -115.848602,-109.206299,-101.391899,-97.094002,-91.233200,-86.153801,-81.074501,
    -74.822998,-73.650803,-76.385803,-78.730202,-78.339401,-81.855904,-86.153801,
    -87.716698,-90.842499,-97.875504,-101.782700,-105.689903,-110.769203,-113.504303,
    -116.239304,-120.928001,-121.318703
};
/*const float prueba[] = 
{
    0.000000,0.290285,0.555570,0.773010,0.923880,0.995185,0.980785,0.881921,
    0.707107,0.471397,0.195090,-0.098017,-0.382683,-0.634393,-0.831470,
    -0.956940,-1.000000,-0.956940,-0.831470,-0.634393,-0.382683,-0.098017,
    0.195090,0.471397,0.707107,0.881921,0.980785,0.995185,0.923880,
    0.773010,0.555570,0.290285,0.000000,-0.290285,-0.555570,-0.773010,
    -0.923880,-0.995185,-0.980785,-0.881921,-0.707107,-0.471397,-0.195090,
    0.098017,0.382683,0.634393,0.831470,0.956940,1.000000,0.956940,
    0.831470,0.634393,0.382683,0.098017,-0.195090,-0.471397,-0.707107,
    -0.881921,-0.980785,-0.995185,-0.923880,-0.773010,-0.555570,-0.290285,
    -0.000000,0.290285,0.555570,0.773010,0.923880,0.995185,0.980785,
    0.881921,0.707107,0.471397,0.195090,-0.098017,-0.382683,-0.634393,
    -0.831470,-0.956940,-1.000000,-0.956940,-0.831470,-0.634393,-0.382683,
    -0.098017,0.195090,0.471397,0.707107,0.881921,0.980785,0.995185,
    0.923880,0.773010,0.555570,0.290285,0.000000,-0.290285,-0.555570,
    -0.773010,-0.923880,-0.995185,-0.980785,-0.881921,-0.707107,-0.471397,
    -0.195090,0.098017,0.382683,0.634393,0.831470,0.956940,1.000000,
    0.956940,0.831470,0.634393,0.382683,0.098017,-0.195090,-0.471397,
    -0.707107,-0.881921,-0.980785,-0.995185,-0.923880,-0.773010,-0.555570,
    -0.290285,-0.000000,0.290285,0.555570,0.773010,0.923880,0.995185,
    0.980785,0.881921,0.707107,0.471397,0.195090,-0.098017,-0.382683,
    -0.634393,-0.831470,-0.956940,-1.000000,-0.956940,-0.831470,-0.634393,
    -0.382683,-0.098017,0.195090,0.471397,0.707107,0.881921,0.980785,
    0.995185,0.923880,0.773010,0.555570,0.290285,0.000000,-0.290285,
    -0.555570,-0.773010,-0.923880,-0.995185,-0.980785,-0.881921,-0.707107,
    -0.471397,-0.195090,0.098017,0.382683,0.634393,0.831470,0.956940,
    1.000000,0.956940,0.831470,0.634393,0.382683,0.098017,-0.195090,
    -0.471397,-0.707107,-0.881921,-0.980785,-0.995185,-0.923880,-0.773010,
    -0.555570,-0.290285,-0.000000,0.290285,0.555570,0.773010,0.923880,
    0.995185,0.980785,0.881921,0.707107,0.471397,0.195090,-0.098017,
    -0.382683,-0.634393,-0.831470,-0.956940,-1.000000,-0.956940,-0.831470,
    -0.634393,-0.382683,-0.098017,0.195090,0.471397,0.707107,0.881921,
    0.980785,0.995185,0.923880,0.773010,0.555570,0.290285,-0.000000,
    -0.290285,-0.555570,-0.773010,-0.923880,-0.995185,-0.980785,-0.881921,
    -0.707107,-0.471397,-0.195090,0.098017,0.382683,0.634393,0.831470,
    0.956940,1.000000,0.956940,0.831470,0.634393,0.382683,0.098017,
    -0.195090,-0.471397,-0.707107,-0.881921,-0.980785,-0.995185,-0.923880,
    -0.773010,-0.555570,-0.290285
};*/
const float hamming_coef[] = 
{
    0.080000,0.080140,0.080558,0.081256,0.082232,0.083487,0.085018,0.086825,
    0.088908,0.091264,0.093893,0.096793,0.099962,0.103398,0.107099,0.111063,
    0.115287,0.119769,0.124506,0.129496,0.134734,0.140219,0.145946,0.151913,
    0.158115,0.164549,0.171211,0.178097,0.185203,0.192524,0.200056,0.207794,
    0.215734,0.223871,0.232200,0.240716,0.249413,0.258287,0.267332,0.276542,
    0.285912,0.295437,0.305110,0.314925,0.324878,0.334960,0.345168,0.355493,
    0.365931,0.376474,0.387117,0.397852,0.408674,0.419575,0.430550,0.441591,
    0.452691,0.463845,0.475045,0.486285,0.497557,0.508854,0.520171,0.531500,
    0.542834,0.554166,0.565489,0.576797,0.588083,0.599340,0.610560,0.621738,
    0.632866,0.643938,0.654946,0.665885,0.676747,0.687527,0.698216,0.708810,
    0.719302,0.729684,0.739951,0.750097,0.760115,0.770000,0.779745,0.789345,
    0.798793,0.808084,0.817212,0.826172,0.834958,0.843565,0.851988,0.860222,
    0.868261,0.876100,0.883736,0.891163,0.898377,0.905373,0.912148,0.918696,
    0.925015,0.931100,0.936947,0.942554,0.947916,0.953030,0.957894,0.962504,
    0.966857,0.970952,0.974785,0.978353,0.981656,0.984690,0.987455,0.989948,
    0.992168,0.994113,0.995782,0.997175,0.998290,0.999128,0.999686,0.999965,
    0.999965,0.999686,0.999128,0.998290,0.997175,0.995782,0.994113,0.992168,
    0.989948,0.987455,0.984690,0.981656,0.978353,0.974785,0.970952,0.966857,
    0.962504,0.957894,0.953030,0.947916,0.942554,0.936947,0.931100,0.925015,
    0.918696,0.912148,0.905373,0.898377,0.891163,0.883736,0.876100,0.868261,
    0.860222,0.851988,0.843565,0.834958,0.826172,0.817212,0.808084,0.798793,
    0.789345,0.779745,0.770000,0.760115,0.750097,0.739951,0.729684,0.719302,
    0.708810,0.698216,0.687527,0.676747,0.665885,0.654946,0.643938,0.632866,
    0.621738,0.610560,0.599340,0.588083,0.576797,0.565489,0.554166,0.542834,
    0.531500,0.520171,0.508854,0.497557,0.486285,0.475045,0.463845,0.452691,
    0.441591,0.430550,0.419575,0.408674,0.397852,0.387117,0.376474,0.365931,
    0.355493,0.345168,0.334960,0.324878,0.314925,0.305110,0.295437,0.285912,
    0.276542,0.267332,0.258287,0.249413,0.240716,0.232200,0.223871,0.215734,
    0.207794,0.200056,0.192524,0.185203,0.178097,0.171211,0.164549,0.158115,
    0.151913,0.145946,0.140219,0.134734,0.129496,0.124506,0.119769,0.115287,
    0.111063,0.107099,0.103398,0.099962,0.096793,0.093893,0.091264,0.088908,
    0.086825,0.085018,0.083487,0.082232,0.081256,0.080558,0.080140,0.080000
};

typedef struct{
	float real;
	float imag;
} complejo;
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
    for( i = 0; i < MUESTRAS; i++ )
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
    int i,j;
	for( i=0;i<MUESTRAS;i++)
    {
		//epochs[i] = valCH0Float[i]*hamming_coef[i];
        epochs[i] = prueba[i]*hamming_coef[i];
	}
    complejo fft[MUESTRAS];
    
    for( i=0;i<MUESTRAS;i++)
    {
		fft[i].real=0.0;
		fft[i].imag=0.0;
	}
    
    float var1;
	for(i=0;i<MUESTRAS;i++)
    {
		for(j=0;j<MUESTRAS;j++)
        {
            var1 = 2*M_PI*i*j/MUESTRAS;
			float real = (float)cos((double)var1);
			float imag = (float)sin((double)var1);
			fft[i].real+=(epochs[j]*real);
			fft[i].imag+=(epochs[j]*imag);				
		}
	}
    
    
	for( i=0;i<MUESTRAS;i++)
    {
        float real = fft[i].real/MUESTRAS;
		float imag = fft[i].imag/MUESTRAS;

		epochs[i]=(float)sqrt(pow((double)real,2.0)+pow((double)imag,2.0));	
	}
    
    return;
}

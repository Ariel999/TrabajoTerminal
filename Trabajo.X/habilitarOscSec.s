.ifdef __dsPIC33F
.include "p33fxxxx.inc"
.endif
    .GLOBAL _enLPOSC

    _enLPOSC: ;Se coloca el codigo para acceder al registro OSCCONL
	PUSH	W0
	PUSH	W1
	PUSH	W2

	MOV	#0X46, W0 ; W0 = 0X46
	MOV	#0X57, W1 ; W1 = 0X57
	MOV	#OSCCONL, W2 ; W2 = &OSCCONL Igual a la dirección de OSCCONL
	MOV.B	W0, [W2] ;Mover al contenido de W2.
	MOV.B	W1, [W2]
	BSET	OSCCONL, #LPOSCEN ;Enciende el bit del oscilador secundario/externo 

	POP	W2
	POP	W1
	POP	W0

	RETURN

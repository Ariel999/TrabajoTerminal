.ifdef __dsPIC33F
.include "p33fxxxx.inc"
.endif
    .GLOBAL _retardo15ms

    ;Aprox realiza en ciclo 2x27674 instrucciones + 4 fuera, 1 instru=271ns
    _retardo15ms:
	PUSH	W0
	
	MOV	#27674,	W0
	CICLO1_15ms:	
	DEC	W0,	W0 ;Decrementa variable W0
	BRA	NZ,	CICLO1_15ms ;Si no es cero entonces regresa el ciclo
	
	POP	W0
	RETURN

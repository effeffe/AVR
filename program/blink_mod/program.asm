;program.asm
; final target is to perform sum of 1+2=3 and display it with leds
.nolist
.include "./tn85def.inc"
.list

; define constant
.equ LED_PIN = PB0			; use PB0 as LED pin

; start vector
.org 0x0000
	rjmp	main			; jump to main label

; main program
main:
	sbi	DDRB, LED_PIN		; set LED pin as output
loop:
	sbic	PINB, LED_PIN		; if bit of LED pin is clear, skip next line
 	cbi	PORTB, LED_PIN		; if 1, turn the LED off
	sbis	PINB, LED_PIN		; if bit of LED pin is set, skip next line
 	sbi	PORTB, LED_PIN		; if 0, light the LED up
delay_500ms:
	ldi	r18, 0		; set register, r18 = 128
delay0:
	dec	r18			; decrement register, r18 = r18 - 1
	brne	delay0			; if r18 != 0, jump to label delay0
	rjmp	loop			; if r20 == 0, jump to label loop

/*
 Naslov: MIKROUPRAVLJACI - Programiranje mikrokontrolera AVR familije
 Autor: Zoran Vrhovski
 
 Vje�ba 4.2.2
 */ 

#include "AVR VUB/avrvub.h"
#include <avr/io.h>

void inicijalizacija() {
	
	// PB7,PB6,PB5,i PB4 postavljeni kao izlazni pinovi
	DDRB |= (1 << PB7) | (1 << PB6) | (1 << PB5) | (1 << PB4);
	// PD1 i PD0 postavljeni kao izlazni pinovi
	DDRD &= ~((1 << PD1) | (1 << PD0));
	// PF7 i PF6 postavljeni kao izlazni pinovi
	DDRF &= ~((1 << PF7) | (1 << PF6));
	// pritezni otpornici ukljuceni na pinovima PD1 i PD0
	PORTD |= (1 << PD1) | (1 << PD0);
	// pritezni otpornici ukljuceni na pinovima PF7 i PF6
	PORTF |= (1 << PF7) | (1 << PF6);
}

int main(void) {
	
	inicijalizacija(); // inicijalizacija mikroupravljaca
	
	while (1) {

		if((PIND & (1 << PD0)) == 0x00) {	// ako je pin PD0 u logickoj nuli
			PORTB |= (1 << PB4);			// ukljuci crvenu LED diodu
		}
		else {
			PORTB &= ~(1 << PB4);			// inace je iskljuci
		}
			
		if((PIND & (1 << PD1)) == 0x00) {	// ako je pin PD1 u logickoj nuli
			PORTB |= (1 << PB5);			// ukljuci zutu LED diodu
		}
		else {
			PORTB &= ~(1 << PB5);			// inace je iskljuci
		}		
		
		if((PINF & (1 << PF6)) == 0x00) {	// ako je pin PF6 u logickoj nuli
			PORTB |= (1 << PB6);			// ukljuci ?zelenu LED diodu
		}
		else {
			PORTB &= ~(1 << PB6);			// inace je iskljuci
		}

		if((PINF & (1 << PF7)) == 0x00) {	// ako je pin PF7 u logickoj nuli
			PORTB |= (1 << PB7);			// ukljuci plavu LED diodu
		}
		else {
			PORTB &= ~(1 << PB7);			// inace je iskljuci
		}	
	}
	return 0;
}
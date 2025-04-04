/*
 Naslov: MIKROUPRAVLJACI - Programiranje mikrokontrolera AVR familije
 Autor: Zoran Vrhovski
 
 Vježba 5.1.2
 */ 

#include "AVR VUB/avrvub.h"
#include "LCD/lcd.h"
#include "DigitalIO/DigitalIO.h"
#include <avr/io.h>
#include <util/delay.h>

void inicijalizacija() {
	
	lcd_init(); // inicijalizacija lcd displeja
	
}

int main(void) {
	
	inicijalizacija();
	
	DigitalInput tipkalo(D0);
	tipkalo.pullup_on();
	
	// deklaracija podataka
	uint8_t brojac = 0;
	
	while (1) {
		if (tipkalo.isFalling_edge() == true) {
			brojac++;
			lcd_clrscr();
			lcd_home();
			
			lcd_print("Brojac: %u", brojac);
		}
	
	}
	return 0;	
}
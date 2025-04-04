/*
 Naslov: MIKROUPRAVLJACI - Programiranje mikrokontrolera AVR familije
 Autor: Zoran Vrhovski
 
 Vje�ba 5.1.4
 */ 

#include "AVR VUB/avrvub.h"
#include "LCD/lcd.h"
#include <avr/io.h>
#include <util/delay.h>
#include <math.h>

#define PI 3.14159

void inicijalizacija() {
	
	lcd_init(); // inicijalizacija lcd displeja
}

int main(void) {
	
	inicijalizacija();
	
	uint8_t kut = 0;
	
	while (1) {
		lcd_clrscr();
		lcd_home();
		
		//ispis kuta i sinusa kuta (223 je simbol ?);
		lcd_print("%d%c", kut, 223);
		lcd_gotoxy(1,0);
		lcd_print("Sinus kuta: %.3f", sin((PI*kut)/180));
		
		_delay_ms(1000);
		
		if(++kut >= 180) {
			kut = 0;
		}		
	}
	return 0;
}



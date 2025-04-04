/*
 Naslov: MIKROUPRAVLJACI - Programiranje mikrokontrolera AVR familije
 Autor: Zoran Vrhovski
 
 Vježba 5.1.7
 */ 

#include "AVR VUB/avrvub.h"
#include "LCD/lcd.h"
#include <avr/io.h>
#include <util/delay.h>

void inicijalizacija() {
	
	lcd_init(); // inicijalizacija lcd displeja
	lcd_define_char(); //definiranje novih znakova
}

int main(void) {
	
	inicijalizacija();
	
	while (1) {
		lcd_clrscr();
		lcd_home();
		lcd_print("Veleu%cili%cte u\nBjelovaru", 0x05, 0x02);
		_delay_ms(2000);
		
		lcd_clrscr();
		lcd_home();
		lcd_print("Stru%cni studij\nmehatronika", 0x05);
		_delay_ms(2000);
		
		lcd_clrscr();
		lcd_home();
		lcd_print("Stru%cni studij\nra%cunarstvo", 0x05, 0x05);
		_delay_ms(2000);
	}
	return 0;
}
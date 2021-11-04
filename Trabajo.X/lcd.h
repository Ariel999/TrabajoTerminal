/* 
 * File:   lcd.h
 * Author: mendo
 *
 * Created on 31 de octubre de 2021, 12:09 AM
 */
void ini_lcd(void);
void comando_lcd(short comando);
void dato_lcd(short dato);
void bf_lcd(void);
void string_lcd(char cadena[]);
void limpiar_lcd(void);
void comando_lcdNoBF(short comando);

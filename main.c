/********************************************************************************
* main.c: Implementering av ett inbyggt system inneh�llande tv� lysdioder 
*         anslutna till pin 9 - 10 (PORTB1 - PORTB2) samt tv� tryckknappar
*         anslutna till pin 2 - 3 (PORTB2 - PORTB3). Externa avbrott INT0 - INT1
*         aktiveras p� tryckknapparnas pinnar f�r att toggla en given lysdiod.
*         Vid nedtryckning av tryckknappen BUTTON1 ansluten till pin 2 togglas
*         lysdioden LED1 ansluten till pin 9. Vid uppsl�ppning av tryckknappen
*         BUTTON2 ansluten till pin 3 togglas lysdioden LED2 ansluten till
*         pin 10.
********************************************************************************/
#include "header.h"

/********************************************************************************
* main: Initierar mikrodatorn vid start. Resterande del av programmet �r
*       kontrollerat via externa avbrott, s� programmet h�lls bara ig�ng.
********************************************************************************/
int main(void)
{
   setup();

   while (1) 
   {
   }

   return 0;
}


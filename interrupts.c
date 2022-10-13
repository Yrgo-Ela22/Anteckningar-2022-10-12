/********************************************************************************
* interrupts.c: Implementering av avbrottsrutiner, vilket �r funktioner p�
*               designerade adresser i programminnet, skrivna enligt nedan:
*
*               ISR (avbrottsvektor)
*               {
*                  H�r placeras programkod f�r att hantera avbrottet, dvs.
*                  styra vad som skall ske n�r avbrottsrutinen anropas.
*               }
*
*               ISR st�r f�r Interrupt Service Routine, dvs. avbrottsrutin.
*
*               Avbrottsvektorn f�r ett givet avbrott kan hittas i databladet.
*               Dessa �r dock definierade via makron som avslutas p� vect, 
*               s�som INT0_vect f�r avbrott INT0 och INT1_vect f�r avbrott INT1.
*               Dessa makron �r definierade i biblioteket avr/interrupt.h.
********************************************************************************/
#include "header.h"

/********************************************************************************
* INT0_vect: Avbrottsrutin som �ger rum vid nedtryckning av BUTTON1 ansluten
*            till pin 2. Vid nedtryckning s� togglas LED1.
********************************************************************************/
ISR (INT0_vect)
{
   led_toggle(LED1);
   return;
}

/********************************************************************************
* INT1_vect: Avbrottsrutin som �ger rum vid uppsl�ppning av BUTTON2 ansluten
*            till pin 3. Vid nedtryckning s� togglas LED2.
********************************************************************************/
ISR (INT1_vect)
{
   led_toggle(LED2);
   return;
}
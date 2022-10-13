/********************************************************************************
* interrupts.c: Implementering av avbrottsrutiner, vilket är funktioner på
*               designerade adresser i programminnet, skrivna enligt nedan:
*
*               ISR (avbrottsvektor)
*               {
*                  Här placeras programkod för att hantera avbrottet, dvs.
*                  styra vad som skall ske när avbrottsrutinen anropas.
*               }
*
*               ISR står för Interrupt Service Routine, dvs. avbrottsrutin.
*
*               Avbrottsvektorn för ett givet avbrott kan hittas i databladet.
*               Dessa är dock definierade via makron som avslutas på vect, 
*               såsom INT0_vect för avbrott INT0 och INT1_vect för avbrott INT1.
*               Dessa makron är definierade i biblioteket avr/interrupt.h.
********************************************************************************/
#include "header.h"

/********************************************************************************
* INT0_vect: Avbrottsrutin som äger rum vid nedtryckning av BUTTON1 ansluten
*            till pin 2. Vid nedtryckning så togglas LED1.
********************************************************************************/
ISR (INT0_vect)
{
   led_toggle(LED1);
   return;
}

/********************************************************************************
* INT1_vect: Avbrottsrutin som äger rum vid uppsläppning av BUTTON2 ansluten
*            till pin 3. Vid nedtryckning så togglas LED2.
********************************************************************************/
ISR (INT1_vect)
{
   led_toggle(LED2);
   return;
}
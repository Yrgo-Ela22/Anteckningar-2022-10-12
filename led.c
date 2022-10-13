/********************************************************************************
* led.c: Funktionsdefinitioner f�r styrning av lysdioderna.
********************************************************************************/
#include "header.h"

/********************************************************************************
* led_toggle: Togglar angiven lysdiod p� I/O-port B. uint8_t �r en osignerad
*             8-bitars heltalsdatatyp, som kan lagra heltal 0 - 255, vilket �r
*             samma som 0000 0000 - 1111 1111. De lokala enable-variablerna
*             s�tts till statiska f�r att lagra i RAM-minnet, s� att minnet
*             f�r dem kvarst�r hela programmet.
*
*             - pin: Lysdiodens pin-nummer p� I/O-port B.
********************************************************************************/
void led_toggle(const uint8_t pin)
{
   static bool led1_enabled = false;
   static bool led2_enabled = false;

   if (pin == LED1)
   {
      led1_enabled = !led1_enabled;

      if (led1_enabled) LED1_ON;
      else LED1_OFF;
   }
   else if (pin == LED2)
   {
      led2_enabled = !led2_enabled;

      if (led2_enabled) LED2_ON;
      else LED2_OFF;
   }

   return;
}

#include <xc.h>
#include "timers.h"

void init_timer2(void)
{
  
    // no of ticks in PR2 PRELOAD THE REGISTER
    PR2 = 250;

    // enable timer2 interrupt IS ENABLED
    TMR2IE = 1;

    // switching ON the timer2
    TMR2ON = 0;
}

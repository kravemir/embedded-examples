#include "Arduino.h"

#define BLINK_N 3
#define BLINK_TIME 100
#define BLINK_DELAY 100
#define BLINK_PAUSE 1000

int main(void)
{
    /* Arduino init */
    init();

    /* INIT */
    pinMode(13,OUTPUT);

    /* MAIN LOOP */
    while(1){
        for(int i = 0; i < BLINK_N; i++) {
            digitalWrite(13,HIGH);
            delay(BLINK_TIME);
            digitalWrite(13,LOW);
            delay(BLINK_DELAY);
        }
        delay(BLINK_PAUSE - BLINK_DELAY);
    }

    return 0;
}


#include <arduino.h>

#include "Gbits.h"

Gbits bits(32, 0xffffffff);

void setup() {
    Serial.begin(9600);
    Serial.println("Starting bits...");
    delay(2000);
    Serial.println(bits.header());
    Serial.println(bits.valueToBitString(true));
    delay(2000);
}

void loop() {
    bits.setValue(bits.getValue() + 1); //increment value
    Serial.println(bits.valueToBitString(true));
    delay(1000);

}

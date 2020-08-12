#ifndef UNIT_TEST

#include <Arduino.h>
#include "debug/trace.h"

void setup() {
#ifdef DEBUG
    Serial.begin(115200);
    // Wait for serial port UART to connect.
    // Without this delay initial writes to the serial port are not captured.
    delay(2000);
#endif

    DEBUG_TRACE("setup() start")

    DEBUG_TRACE("setup() end")
}

void loop() {}

#endif

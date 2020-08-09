#ifndef UNIT_TEST

#include <Arduino.h>
#include "debug/trace.h"

#ifndef X55B_WIFI_SSID
#error 'Environment variable X55B_WIFI_SSID is not defined'
#endif

#ifndef X55B_WIFI_PASS
#error 'Environment variable X55B_WIFI_PASS is not defined'
#endif

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

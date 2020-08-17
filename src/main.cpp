#ifndef UNIT_TEST

#include <Arduino.h>
#include <BluetoothSerial.h>
#include "debug/trace.h"
#include "freematics_one_plus/pin_assignments.h"

#ifdef DEBUG
BluetoothSerial SerialBT;
#endif

void setup() {
#ifdef DEBUG
    Serial.begin(115200);
    SerialBT.begin("55b ONE+ debug");
    // Wait for serial port UART to connect.
    // Without this delay initial writes to the serial port are not captured.
    delay(2000);
#endif

    DEBUG_TRACE("setup() start")

    pinMode(PIN_LED_BUILTIN, OUTPUT);
    digitalWrite(PIN_LED_BUILTIN, LOW);

    DEBUG_TRACE("setup() end")
}

void loop() {}

#endif

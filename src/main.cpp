#ifndef UNIT_TEST

#include <Arduino.h>
#include <BluetoothSerial.h>
#include "Debug/Trace.h"
#include "FreematicsOnePlus/PinAssignments.h"

#ifdef DEBUG
BluetoothSerial SerialBT;
#endif

void setup() {
    pinMode(PIN_LED_BUILTIN, OUTPUT);
    digitalWrite(PIN_LED_BUILTIN, LOW);

#ifdef DEBUG
    digitalWrite(PIN_LED_BUILTIN, HIGH);

    Serial.begin(115200);
    SerialBT.begin("55b ONE+ debug");
    // Wait for serial port UART to connect.
    // Without this delay initial writes to the serial port are not captured.
    delay(2000);

    digitalWrite(PIN_LED_BUILTIN, LOW);
#endif

    DEBUG_TRACE("[DEBUG] setup() start")

    DEBUG_TRACE("[DEBUG] setup() end")
}

void loop() {}

#endif

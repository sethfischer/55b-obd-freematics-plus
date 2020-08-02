#if defined(ARDUINO) && defined(UNIT_TEST)

#include <Arduino.h>
#include "unity.h"

#define LED_BUILTIN 4

void test_led_builtin_pin_number(void) { TEST_ASSERT_EQUAL(4, LED_BUILTIN); }

void test_led_state_high(void) {
    digitalWrite(LED_BUILTIN, HIGH);
    TEST_ASSERT_EQUAL(HIGH, digitalRead(LED_BUILTIN));
}

void test_led_state_low(void) {
    digitalWrite(LED_BUILTIN, LOW);
    TEST_ASSERT_EQUAL(LOW, digitalRead(LED_BUILTIN));
}

void setup() {
    UNITY_BEGIN();

    RUN_TEST(test_led_builtin_pin_number);

    pinMode(LED_BUILTIN, OUTPUT);
}

uint8_t i = 0;
uint8_t blink_count = 5;

void loop() {
    if (i < blink_count) {
        RUN_TEST(test_led_state_high);
        delay(500);
        RUN_TEST(test_led_state_low);
        delay(500);
        i++;
    } else if (i == blink_count) {
        UNITY_END();
    }
}

#endif

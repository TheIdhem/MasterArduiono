#include <Arduino.h>
#include "unity.h"
#include "Floor0.h"
#include "rtwtypes.h"

class FloorModel
{
    // public data and function members
public:
    // External inputs
    ExtU rtU;

    // External outputs
    ExtY rtY;
};

static FloorModel rtObj;

void InterruptSrevicesHandlerRead(char data, int pol)
{
    switch (pol)
    {
    case 0:
        rtObj.rtY.l1 = data ? true : false;
        digitalWrite(LED1, rtObj.rtY.l1 == true ? HIGH : LOW);
        break;

    case 1:
        rtObj.rtY.l2 = data ? true : false;
        digitalWrite(LED2, rtObj.rtY.l2 == true ? HIGH : LOW);
        break;
    case 2:
        rtObj.rtY.l3 = data ? true : false;
        digitalWrite(LED3, rtObj.rtY.l3 == true ? HIGH : LOW);
        break;
    case 3:
        rtObj.rtY.l4 = data ? true : false;
        digitalWrite(LED4, rtObj.rtY.l4 == true ? HIGH : LOW);
        break;

    default:
        break;
    }
}

void syncWithSlave(char data)
{
    InterruptSrevicesHandlerRead((data & 0b00000001) >> 0, 0);
    InterruptSrevicesHandlerRead((data & 0b00000010) >> 1, 1);
    InterruptSrevicesHandlerRead((data & 0b00000100) >> 2, 2);
    InterruptSrevicesHandlerRead((data & 0b00001000) >> 3, 3);
}

void readDataFromBus(char received[3])
{
    if (received[0] == 1)
    {
        switch (received[1])
        {
        case 1:
            InterruptSrevicesHandlerRead(received[2], 0);
            break;
        case 2:
            InterruptSrevicesHandlerRead(received[2], 1);
            break;
        case 3:
            InterruptSrevicesHandlerRead(received[2], 2);
            break;
        case 4:
            InterruptSrevicesHandlerRead(received[2], 3);
            break;

        case -128:
            Serial.println(received[2]);
            syncWithSlave(received[2]);
            break;
        default:
            break;
        }
    }
}

void test_led_builtin_pin_number(void)
{
    InterruptSrevicesHandlerRead((0b00001000 & 0b00001000) >> 3, 3);
    InterruptSrevicesHandlerRead((0b00000100 & 0b00000100) >> 2, 2);
    InterruptSrevicesHandlerRead((0b00000010 & 0b00000010) >> 1, 1);
    InterruptSrevicesHandlerRead((0b00000001 & 0b00000001) >> 0, 0);
    TEST_ASSERT_EQUAL(true, rtObj.rtY.l4);
    TEST_ASSERT_EQUAL(true, rtObj.rtY.l3);
    TEST_ASSERT_EQUAL(true, rtObj.rtY.l2);
    TEST_ASSERT_EQUAL(true, rtObj.rtY.l1);
}

void test_with_button(void)
{
    digitalWrite(BUTTON3, HIGH);
    delay(100);
    digitalWrite(BUTTON3, HIGH);
    if (digitalRead(BUTTON3))
        InterruptSrevicesHandlerRead((0b00000100 & 0b00000100) >> 2, 2);
    TEST_ASSERT_EQUAL(true, rtObj.rtY.l3);
}

void test_with_data_read_from_slave(void)
{
    char received[3];
    received[0] = 0b00000001;
    received[1] = 0b10000000;
    received[2] = 0b00001010;

    readDataFromBus(received);
    TEST_ASSERT_EQUAL(false, rtObj.rtY.l1);
    TEST_ASSERT_EQUAL(true, rtObj.rtY.l2);
    TEST_ASSERT_EQUAL(false, rtObj.rtY.l3);
    TEST_ASSERT_EQUAL(true, rtObj.rtY.l4);
}

void runTest()
{
    UNITY_BEGIN();
    RUN_TEST(test_led_builtin_pin_number);
    RUN_TEST(test_with_button);
    RUN_TEST(test_with_data_read_from_slave);
    UNITY_END();
}

void setup()
{

    delay(2000);
    runTest();
}

void loop()
{
}
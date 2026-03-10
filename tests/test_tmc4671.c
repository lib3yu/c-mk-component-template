#include "unity.h"
#include "TMC4671.h"

void setUp(void) {}
void tearDown(void) {}

void test_ic0_register_read_write(void)
{
    tmc4671_writeRegister(0, 0x68, 12345);
    TEST_ASSERT_EQUAL_INT32(12345, tmc4671_readRegister(0, 0x68));
}

void test_ic1_register_read_write(void)
{
    tmc4671_writeRegister(1, 0x68, 67890);
    TEST_ASSERT_EQUAL_INT32(67890, tmc4671_readRegister(1, 0x68));
}

void test_ic0_target_velocity(void)
{
    tmc4671_setTargetVelocity(0, 5000);
    TEST_ASSERT_EQUAL_INT32(5000, tmc4671_getTargetVelocity(0));
}

void test_ic1_target_velocity(void)
{
    tmc4671_setTargetVelocity(1, 8000);
    TEST_ASSERT_EQUAL_INT32(8000, tmc4671_getTargetVelocity(1));
}

void test_ic0_target_position(void)
{
    tmc4671_setAbsolutTargetPosition(0, 10000);
    TEST_ASSERT_EQUAL_INT32(10000, tmc4671_getTargetPosition(0));
}

void test_ic1_target_position(void)
{
    tmc4671_setAbsolutTargetPosition(1, 20000);
    TEST_ASSERT_EQUAL_INT32(20000, tmc4671_getTargetPosition(1));
}

void test_two_ic_isolation(void)
{
    tmc4671_writeRegister(0, 0x20, 0xAAAAAAAA);
    tmc4671_writeRegister(1, 0x20, 0x55555555);
    TEST_ASSERT_EQUAL_HEX32(0xAAAAAAAA, tmc4671_readRegister(0, 0x20));
    TEST_ASSERT_EQUAL_HEX32(0x55555555, tmc4671_readRegister(1, 0x20));
}

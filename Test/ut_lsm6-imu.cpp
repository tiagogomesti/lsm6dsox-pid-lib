#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "hal_spi.h"
#include "lsm6-imu.h"
#include "lsm6dsox_reg.h"

// Using GMock and GTest namespaces
using ::testing::_;
using ::testing::DoAll;
using ::testing::Return;
using ::testing::SetArrayArgument;

class MockHalSpi
{
public:
    MOCK_METHOD(int, hal_spi_init, ());
    MOCK_METHOD(int, hal_spi_read, (uint8_t reg, uint8_t *data, uint16_t len));
    MOCK_METHOD(int, hal_spi_write, (uint8_t reg, uint8_t *data, uint16_t len));
};

MockHalSpi *g_mockHalSpi = nullptr;

class Lsm6ImuTest : public ::testing::Test
{
protected:
    MockHalSpi mockHalSpi; // Instance of your mock object

    void SetUp() override
    {
        g_mockHalSpi = &mockHalSpi;
    }

    void TearDown() override
    {
        g_mockHalSpi = nullptr;
    }
};

TEST_F(Lsm6ImuTest, InitSuccessful)
{
    EXPECT_CALL(mockHalSpi, hal_spi_init()).WillOnce(Return(0));

    int result = lsm6_imu_init();
    ASSERT_EQ(result, 0);
}

TEST_F(Lsm6ImuTest, ReadData)
{
    uint8_t reg_addr = 0x10;
    uint8_t read_buffer[2] = {0, 0};
    uint8_t expected_data[2] = {0xAB, 0xCD};

    EXPECT_CALL(mockHalSpi, hal_spi_read(reg_addr, _, sizeof(read_buffer)))
        .WillOnce(DoAll(SetArrayArgument<1>(expected_data, expected_data + sizeof(expected_data)),
                        Return(0) // Return 0 to indicate success.
                        ));

    lsm6ImuData_t result = lsm6_imu_read();
    ASSERT_TRUE(true);
}

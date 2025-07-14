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
    MOCK_METHOD(HalErrorType_t, hal_spi_init, ());
    MOCK_METHOD(int32_t, hal_spi_read, (void *optData, uint8_t reg, uint8_t *data, uint16_t len));
    MOCK_METHOD(int32_t, hal_spi_write, (void *optData, uint8_t reg, const uint8_t *data, uint16_t len));
};

MockHalSpi *g_mockHalSpi = nullptr;

HalErrorType_t hal_spi_init(void)
{
    return g_mockHalSpi->hal_spi_init();
}

int32_t hal_spi_read(void *optData, uint8_t reg, uint8_t *data, uint16_t len)
{
    return g_mockHalSpi->hal_spi_read(optData, reg, data, len);
}

int32_t hal_spi_write(void *optData, uint8_t reg, const uint8_t *data, uint16_t len)
{
    return g_mockHalSpi->hal_spi_write(optData, reg, data, len);
}

class MockLsm6dsoxReg
{
public:
    MOCK_METHOD(int32_t, lsm6dsox_i3c_disable_set, (const stmdev_ctx_t *ctx, lsm6dsox_i3c_disable_t val));
    MOCK_METHOD(int32_t, lsm6dsox_auto_increment_set, (const stmdev_ctx_t *ctx, uint8_t val));
    MOCK_METHOD(int32_t, lsm6dsox_block_data_update_set, (const stmdev_ctx_t *ctx, uint8_t val));
    MOCK_METHOD(int32_t, lsm6dsox_fifo_mode_set, (const stmdev_ctx_t *ctx, lsm6dsox_fifo_mode_t val));
    MOCK_METHOD(int32_t, lsm6dsox_xl_data_rate_set, (const stmdev_ctx_t *ctx, lsm6dsox_odr_xl_t val));
    MOCK_METHOD(int32_t, lsm6dsox_xl_full_scale_set, (const stmdev_ctx_t *ctx, lsm6dsox_fs_xl_t val));
    MOCK_METHOD(int32_t, lsm6dsox_gy_data_rate_set, (const stmdev_ctx_t *ctx, lsm6dsox_odr_g_t val));
    MOCK_METHOD(int32_t, lsm6dsox_gy_full_scale_set, (const stmdev_ctx_t *ctx, lsm6dsox_fs_g_t val));
    MOCK_METHOD(int32_t, lsm6dsox_xl_flag_data_ready_get, (const stmdev_ctx_t *ctx, uint8_t *val));
    MOCK_METHOD(int32_t, lsm6dsox_acceleration_raw_get, (const stmdev_ctx_t *ctx, int16_t *val));
    MOCK_METHOD(int32_t, lsm6dsox_xl_full_scale_get, (const stmdev_ctx_t *ctx, lsm6dsox_fs_xl_t *val));
    MOCK_METHOD(int32_t, lsm6dsox_gy_flag_data_ready_get, (const stmdev_ctx_t *ctx, uint8_t *val));
    MOCK_METHOD(int32_t, lsm6dsox_angular_rate_raw_get, (const stmdev_ctx_t *ctx, int16_t *val));
    MOCK_METHOD(int32_t, lsm6dsox_gy_full_scale_get, (const stmdev_ctx_t *ctx, lsm6dsox_fs_g_t *val));
};

MockLsm6dsoxReg *g_mockLsm6dsoxReg = nullptr;

int32_t lsm6dsox_i3c_disable_set(const stmdev_ctx_t *ctx, lsm6dsox_i3c_disable_t val)
{
    return g_mockLsm6dsoxReg->lsm6dsox_i3c_disable_set(ctx, val);
}

int32_t lsm6dsox_auto_increment_set(const stmdev_ctx_t *ctx, uint8_t val)
{
    return g_mockLsm6dsoxReg->lsm6dsox_auto_increment_set(ctx, val);
}

int32_t lsm6dsox_block_data_update_set(const stmdev_ctx_t *ctx, uint8_t val)
{
    return g_mockLsm6dsoxReg->lsm6dsox_block_data_update_set(ctx, val);
}

int32_t lsm6dsox_fifo_mode_set(const stmdev_ctx_t *ctx, lsm6dsox_fifo_mode_t val)
{
    return g_mockLsm6dsoxReg->lsm6dsox_fifo_mode_set(ctx, val);
}

int32_t lsm6dsox_xl_data_rate_set(const stmdev_ctx_t *ctx, lsm6dsox_odr_xl_t val)
{
    return g_mockLsm6dsoxReg->lsm6dsox_xl_data_rate_set(ctx, val);
}

int32_t lsm6dsox_xl_full_scale_set(const stmdev_ctx_t *ctx, lsm6dsox_fs_xl_t val)
{
    return g_mockLsm6dsoxReg->lsm6dsox_xl_full_scale_set(ctx, val);
}

int32_t lsm6dsox_gy_data_rate_set(const stmdev_ctx_t *ctx, lsm6dsox_odr_g_t val)
{
    return g_mockLsm6dsoxReg->lsm6dsox_gy_data_rate_set(ctx, val);
}

int32_t lsm6dsox_gy_full_scale_set(const stmdev_ctx_t *ctx, lsm6dsox_fs_g_t val)
{
    return g_mockLsm6dsoxReg->lsm6dsox_gy_full_scale_set(ctx, val);
}

int32_t lsm6dsox_xl_flag_data_ready_get(const stmdev_ctx_t *ctx, uint8_t *val)
{
    return g_mockLsm6dsoxReg->lsm6dsox_xl_flag_data_ready_get(ctx, val);
}

int32_t lsm6dsox_acceleration_raw_get(const stmdev_ctx_t *ctx, int16_t *val)
{
    return g_mockLsm6dsoxReg->lsm6dsox_acceleration_raw_get(ctx, val);
}

int32_t lsm6dsox_xl_full_scale_get(const stmdev_ctx_t *ctx, lsm6dsox_fs_xl_t *val)
{
    return g_mockLsm6dsoxReg->lsm6dsox_xl_full_scale_get(ctx, val);
}

int32_t lsm6dsox_gy_flag_data_ready_get(const stmdev_ctx_t *ctx, uint8_t *val)
{
    return g_mockLsm6dsoxReg->lsm6dsox_gy_flag_data_ready_get(ctx, val);
}

int32_t lsm6dsox_angular_rate_raw_get(const stmdev_ctx_t *ctx, int16_t *val)
{
    return g_mockLsm6dsoxReg->lsm6dsox_angular_rate_raw_get(ctx, val);
}

int32_t lsm6dsox_gy_full_scale_get(const stmdev_ctx_t *ctx, lsm6dsox_fs_g_t *val)
{
    return g_mockLsm6dsoxReg->lsm6dsox_gy_full_scale_get(ctx, val);
}

class Lsm6ImuTest : public ::testing::Test
{
protected:
    MockHalSpi mockHalSpi;           // Instance of your mock object
    MockLsm6dsoxReg mockLsm6dsoxReg; // Instance of your mock object

    void SetUp() override
    {
        g_mockHalSpi = &mockHalSpi;
        g_mockLsm6dsoxReg = &mockLsm6dsoxReg;
    }

    void TearDown() override
    {
        g_mockHalSpi = nullptr;
        g_mockLsm6dsoxReg = nullptr;
    }
};

TEST_F(Lsm6ImuTest, InitFail_halInitializationFailed)
{
    EXPECT_CALL(mockHalSpi, hal_spi_init()).WillOnce(Return(HAL_ERROR));
    ASSERT_FALSE(lsm6_imu_init());
}

TEST_F(Lsm6ImuTest, InitFail_failToDisableI3c)
{
    EXPECT_CALL(mockHalSpi, hal_spi_init()).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_i3c_disable_set(_, _)).WillOnce(Return(HAL_ERROR));

    ASSERT_FALSE(lsm6_imu_init());
}

TEST_F(Lsm6ImuTest, InitFail_failToSetAutoIncrement)
{
    EXPECT_CALL(mockHalSpi, hal_spi_init()).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_i3c_disable_set(_, _)).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_auto_increment_set(_, _)).WillOnce(Return(HAL_ERROR));

    ASSERT_FALSE(lsm6_imu_init());
}

TEST_F(Lsm6ImuTest, InitFail_failToSetBlockData)
{
    EXPECT_CALL(mockHalSpi, hal_spi_init()).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_i3c_disable_set(_, _)).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_auto_increment_set(_, _)).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_block_data_update_set(_, _)).WillOnce(Return(HAL_ERROR));

    ASSERT_FALSE(lsm6_imu_init());
}

TEST_F(Lsm6ImuTest, InitFail_failToSetFifoMode)
{
    EXPECT_CALL(mockHalSpi, hal_spi_init()).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_i3c_disable_set(_, _)).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_auto_increment_set(_, _)).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_block_data_update_set(_, _)).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_fifo_mode_set(_, _)).WillOnce(Return(HAL_ERROR));

    ASSERT_FALSE(lsm6_imu_init());
}

TEST_F(Lsm6ImuTest, InitFail_failToSetAccelerometerDataRate)
{
    EXPECT_CALL(mockHalSpi, hal_spi_init()).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_i3c_disable_set(_, _)).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_auto_increment_set(_, _)).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_block_data_update_set(_, _)).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_fifo_mode_set(_, _)).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_xl_data_rate_set(_, _)).WillOnce(Return(HAL_ERROR));

    ASSERT_FALSE(lsm6_imu_init());
}

TEST_F(Lsm6ImuTest, InitFail_failToSetAccelerometerFullScale)
{
    EXPECT_CALL(mockHalSpi, hal_spi_init()).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_i3c_disable_set(_, _)).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_auto_increment_set(_, _)).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_block_data_update_set(_, _)).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_fifo_mode_set(_, _)).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_xl_data_rate_set(_, _)).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_xl_full_scale_set(_, _)).WillOnce(Return(HAL_ERROR));

    ASSERT_FALSE(lsm6_imu_init());
}

TEST_F(Lsm6ImuTest, InitFail_failToSetGyroscopeDataRate)
{
    EXPECT_CALL(mockHalSpi, hal_spi_init()).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_i3c_disable_set(_, _)).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_auto_increment_set(_, _)).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_block_data_update_set(_, _)).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_fifo_mode_set(_, _)).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_xl_data_rate_set(_, _)).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_xl_full_scale_set(_, _)).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_gy_data_rate_set(_, _)).WillOnce(Return(HAL_ERROR));

    ASSERT_FALSE(lsm6_imu_init());
}

TEST_F(Lsm6ImuTest, InitFail_failToSetGyroscopeFullScale)
{
    EXPECT_CALL(mockHalSpi, hal_spi_init()).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_i3c_disable_set(_, _)).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_auto_increment_set(_, _)).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_block_data_update_set(_, _)).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_fifo_mode_set(_, _)).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_xl_data_rate_set(_, _)).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_xl_full_scale_set(_, _)).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_gy_data_rate_set(_, _)).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_gy_full_scale_set(_, _)).WillOnce(Return(HAL_ERROR));

    ASSERT_FALSE(lsm6_imu_init());
}

TEST_F(Lsm6ImuTest, InitFail_failToEnableAcceleromter)
{
    EXPECT_CALL(mockHalSpi, hal_spi_init()).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_i3c_disable_set(_, _)).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_auto_increment_set(_, _)).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_block_data_update_set(_, _)).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_fifo_mode_set(_, _)).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_xl_data_rate_set(_, _))
        .WillOnce(Return(HAL_NO_ERROR))
        .WillOnce(Return(HAL_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_xl_full_scale_set(_, _)).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_gy_data_rate_set(_, _)).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_gy_full_scale_set(_, _)).WillOnce(Return(HAL_NO_ERROR));

    ASSERT_FALSE(lsm6_imu_init());
}

TEST_F(Lsm6ImuTest, InitFail_failToEnableGyroscope)
{
    EXPECT_CALL(mockHalSpi, hal_spi_init()).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_i3c_disable_set(_, _)).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_auto_increment_set(_, _)).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_block_data_update_set(_, _)).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_fifo_mode_set(_, _)).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_xl_data_rate_set(_, _))
        .WillOnce(Return(HAL_NO_ERROR))
        .WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_xl_full_scale_set(_, _)).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_gy_data_rate_set(_, _))
        .WillOnce(Return(HAL_NO_ERROR))
        .WillOnce(Return(HAL_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_gy_full_scale_set(_, _)).WillOnce(Return(HAL_NO_ERROR));

    ASSERT_FALSE(lsm6_imu_init());
}

TEST_F(Lsm6ImuTest, InitSuccess)
{
    EXPECT_CALL(mockHalSpi, hal_spi_init()).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_i3c_disable_set(_, _)).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_auto_increment_set(_, _)).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_block_data_update_set(_, _)).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_fifo_mode_set(_, _)).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_xl_data_rate_set(_, _))
        .WillOnce(Return(HAL_NO_ERROR))
        .WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_xl_full_scale_set(_, _)).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_gy_data_rate_set(_, _))
        .WillOnce(Return(HAL_NO_ERROR))
        .WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_gy_full_scale_set(_, _)).WillOnce(Return(HAL_NO_ERROR));

    ASSERT_TRUE(lsm6_imu_init());
}

TEST_F(Lsm6ImuTest, ReadData_FailReadAcceleration_DataNotReady)
{
    EXPECT_CALL(mockHalSpi, hal_spi_init()).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_i3c_disable_set(_, _)).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_auto_increment_set(_, _)).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_block_data_update_set(_, _)).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_fifo_mode_set(_, _)).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_xl_data_rate_set(_, _))
        .WillOnce(Return(HAL_NO_ERROR))
        .WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_xl_full_scale_set(_, _)).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_gy_data_rate_set(_, _))
        .WillOnce(Return(HAL_NO_ERROR))
        .WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_gy_full_scale_set(_, _)).WillOnce(Return(HAL_NO_ERROR));

    ASSERT_TRUE(lsm6_imu_init());

    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_xl_flag_data_ready_get(_, _)).WillOnce(Return(HAL_ERROR));

    lsm6ImuData_t data = lsm6_imu_read();

    ASSERT_EQ(data.acceleration.x, 0);
    ASSERT_EQ(data.acceleration.y, 0);
    ASSERT_EQ(data.acceleration.z, 0);
}

TEST_F(Lsm6ImuTest, ReadData_FailReadAngularVelocity_DataNotReady)
{
    EXPECT_CALL(mockHalSpi, hal_spi_init()).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_i3c_disable_set(_, _)).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_auto_increment_set(_, _)).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_block_data_update_set(_, _)).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_fifo_mode_set(_, _)).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_xl_data_rate_set(_, _))
        .WillOnce(Return(HAL_NO_ERROR))
        .WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_xl_full_scale_set(_, _)).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_gy_data_rate_set(_, _))
        .WillOnce(Return(HAL_NO_ERROR))
        .WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_gy_full_scale_set(_, _)).WillOnce(Return(HAL_NO_ERROR));

    ASSERT_TRUE(lsm6_imu_init());

    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_gy_flag_data_ready_get(_, _)).WillOnce(Return(HAL_ERROR));

    lsm6ImuData_t data = lsm6_imu_read();

    ASSERT_EQ(data.angularVelocity.x, 0);
    ASSERT_EQ(data.angularVelocity.y, 0);
    ASSERT_EQ(data.angularVelocity.z, 0);
}

TEST_F(Lsm6ImuTest, ReadData_Sucess)
{
    EXPECT_CALL(mockHalSpi, hal_spi_init()).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_i3c_disable_set(_, _)).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_auto_increment_set(_, _)).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_block_data_update_set(_, _)).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_fifo_mode_set(_, _)).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_xl_data_rate_set(_, _))
        .WillOnce(Return(HAL_NO_ERROR))
        .WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_xl_full_scale_set(_, _)).WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_gy_data_rate_set(_, _))
        .WillOnce(Return(HAL_NO_ERROR))
        .WillOnce(Return(HAL_NO_ERROR));
    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_gy_full_scale_set(_, _)).WillOnce(Return(HAL_NO_ERROR));

    ASSERT_TRUE(lsm6_imu_init());

    uint8_t status = 1;
    lsm6dsox_fs_xl_t acceleration_scale = LSM6DSOX_2g;
    float acceleration_scale_out = LSM6DSOX_ACC_SENSITIVITY_FS_2G;
    uint8_t expected_accelation[3] = {10, 20, 30};
    lsm6dsox_fs_g_t angular_velocity_scale = LSM6DSOX_125dps;
    float angular_velocity_scale_out = LSM6DSOX_GYRO_SENSITIVITY_FS_125DPS;
    uint8_t expected_angular_velocity[3] = {20, 40, 60};

    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_xl_flag_data_ready_get(_, testing::NotNull()))
        .WillOnce(testing::DoAll(testing::SetArgPointee<1>(status), testing::Return(HAL_NO_ERROR)));

    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_acceleration_raw_get(_, testing::NotNull()))
        .WillOnce(testing::DoAll(testing::SetArrayArgument<1>(expected_accelation, expected_accelation + 3),
                                 testing::Return(HAL_NO_ERROR)));

    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_xl_full_scale_get(_, testing::NotNull()))
        .WillOnce(testing::DoAll(testing::SetArgPointee<1>(acceleration_scale), testing::Return(HAL_NO_ERROR)));

    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_gy_flag_data_ready_get(_, testing::NotNull()))
        .WillOnce(testing::DoAll(testing::SetArgPointee<1>(status), testing::Return(HAL_NO_ERROR)));

    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_angular_rate_raw_get(_, testing::NotNull()))
        .WillOnce(testing::DoAll(testing::SetArrayArgument<1>(expected_angular_velocity, expected_angular_velocity + 3),
                                 testing::Return(HAL_NO_ERROR)));

    EXPECT_CALL(mockLsm6dsoxReg, lsm6dsox_gy_full_scale_get(_, testing::NotNull()))
        .WillOnce(testing::DoAll(testing::SetArgPointee<1>(angular_velocity_scale), testing::Return(HAL_NO_ERROR)));

    lsm6ImuData_t data = lsm6_imu_read();

    ASSERT_EQ(data.acceleration.x, (int32_t)(expected_accelation[0] * acceleration_scale_out));
    ASSERT_EQ(data.acceleration.y, (int32_t)(expected_accelation[1] * acceleration_scale_out));
    ASSERT_EQ(data.acceleration.z, (int32_t)(expected_accelation[2] * acceleration_scale_out));

    ASSERT_EQ(data.angularVelocity.x, (int32_t)(expected_angular_velocity[0] * angular_velocity_scale_out));
    ASSERT_EQ(data.angularVelocity.y, (int32_t)(expected_angular_velocity[1] * angular_velocity_scale_out));
    ASSERT_EQ(data.angularVelocity.z, (int32_t)(expected_angular_velocity[2] * angular_velocity_scale_out));
}
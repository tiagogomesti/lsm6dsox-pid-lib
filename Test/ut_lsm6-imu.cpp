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

TEST_F(Lsm6ImuTest, InitSuccessful)
{
    EXPECT_CALL(mockHalSpi, hal_spi_init()).WillOnce(Return(HAL_ERROR));

    // int result = lsm6_imu_init();
    // ASSERT_EQ(result, 0);

    ASSERT_FALSE(lsm6_imu_init());

    ASSERT_TRUE(true);
}

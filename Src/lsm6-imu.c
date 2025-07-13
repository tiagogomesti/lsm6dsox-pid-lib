#include "lsm6-imu.h"

#include "hal_spi.h"
#include "lsm6dsox_reg.h"

#define LSM6DSOX_OK 0
#define LSM6DSOX_NOK 1

#define LSM6DSOX_ACC_SENSITIVITY_FS_2G 0.061f
#define LSM6DSOX_ACC_SENSITIVITY_FS_4G 0.122f
#define LSM6DSOX_ACC_SENSITIVITY_FS_8G 0.244f
#define LSM6DSOX_ACC_SENSITIVITY_FS_16G 0.488f

#define LSM6DSOX_GYRO_SENSITIVITY_FS_125DPS 4.375f
#define LSM6DSOX_GYRO_SENSITIVITY_FS_250DPS 8.750f
#define LSM6DSOX_GYRO_SENSITIVITY_FS_500DPS 17.500f
#define LSM6DSOX_GYRO_SENSITIVITY_FS_1000DPS 35.000f
#define LSM6DSOX_GYRO_SENSITIVITY_FS_2000DPS 70.000f

typedef union
{
    uint16_t u16Data[3];
    uint8_t u8Data[6];
} u8U16Union_t;

static acceleration_t read_acceleration();
static int32_t get_accelaration_sensitivity(float *sensitivity_out);
static angularVelocity_t read_angular_velocity();
static int32_t get_angular_velocity_sensitivity(float *sensitivity_out);

static stmdev_ctx_t g_stmdevCtx = {};

bool lsm6_imu_init(void)
{
    if (hal_spi_init() != HAL_NO_ERROR)
    {
        return false;
    }

    g_stmdevCtx.read_reg = hal_spi_read;
    g_stmdevCtx.write_reg = hal_spi_write;
    g_stmdevCtx.handle = NULL;

    if (lsm6dsox_i3c_disable_set(&g_stmdevCtx, LSM6DSOX_I3C_DISABLE) != LSM6DSOX_OK)
    {
        return false;
    }

    if (lsm6dsox_auto_increment_set(&g_stmdevCtx, PROPERTY_ENABLE) != LSM6DSOX_OK)
    {
        return false;
    }

    if (lsm6dsox_block_data_update_set(&g_stmdevCtx, PROPERTY_ENABLE) != LSM6DSOX_OK)
    {
        return false;
    }

    if (lsm6dsox_fifo_mode_set(&g_stmdevCtx, LSM6DSOX_BYPASS_MODE) != LSM6DSOX_OK)
    {
        return false;
    }

    if (lsm6dsox_xl_data_rate_set(&g_stmdevCtx, LSM6DSOX_XL_ODR_OFF) != LSM6DSOX_OK)
    {
        return false;
    }

    if (lsm6dsox_xl_full_scale_set(&g_stmdevCtx, LSM6DSOX_2g) != LSM6DSOX_OK)
    {
        return false;
    }

    if (lsm6dsox_gy_data_rate_set(&g_stmdevCtx, LSM6DSOX_GY_ODR_OFF) != LSM6DSOX_OK)
    {
        return false;
    }

    if (lsm6dsox_gy_full_scale_set(&g_stmdevCtx, LSM6DSOX_2000dps) != LSM6DSOX_OK)
    {
        return false;
    }

    // Enable acceloremeter and gyroscope
    if ((lsm6dsox_xl_data_rate_set(&g_stmdevCtx, LSM6DSOX_XL_ODR_104Hz) != LSM6DSOX_OK) ||
        (lsm6dsox_gy_data_rate_set(&g_stmdevCtx, LSM6DSOX_GY_ODR_104Hz) != LSM6DSOX_OK))
    {
        return false;
    }

    return true;
}

lsm6ImuData_t lsm6_imu_read(void)
{
    lsm6ImuData_t data;

    data.acceleration = read_acceleration();
    data.angularVelocity = read_angular_velocity();

    return data;
}

static acceleration_t read_acceleration()
{
    uint8_t status;
    acceleration_t accelaration = {0};
    u8U16Union_t accelarationU8Union = {0};
    float sensitivity = 0.0f;

    if ((lsm6dsox_xl_flag_data_ready_get(&g_stmdevCtx, &status) == LSM6DSOX_OK) && (status == 1) &&
        (lsm6dsox_acceleration_raw_get(&g_stmdevCtx, accelarationU8Union.u16Data) == LSM6DSOX_OK) &&
        (get_accelaration_sensitivity(&sensitivity) == LSM6DSOX_OK))
    {
        accelaration.x = (int32_t)((float)((float)accelarationU8Union.u16Data[0] * sensitivity));
        accelaration.y = (int32_t)((float)((float)accelarationU8Union.u16Data[1] * sensitivity));
        accelaration.z = (int32_t)((float)((float)accelarationU8Union.u16Data[2] * sensitivity));
    }

    return accelaration;
}

static int32_t get_accelaration_sensitivity(float *sensitivity_out)
{
    lsm6dsox_fs_xl_t full_scale;
    int32_t ret = LSM6DSOX_OK;

    if (lsm6dsox_xl_full_scale_get(&g_stmdevCtx, &full_scale) != LSM6DSOX_OK)
    {
        return LSM6DSOX_NOK;
    }

    /* Store the Sensitivity based on actual full scale. */
    switch (full_scale)
    {
    case LSM6DSOX_2g:
        *sensitivity_out = LSM6DSOX_ACC_SENSITIVITY_FS_2G;
        break;

    case LSM6DSOX_4g:
        *sensitivity_out = LSM6DSOX_ACC_SENSITIVITY_FS_4G;
        break;

    case LSM6DSOX_8g:
        *sensitivity_out = LSM6DSOX_ACC_SENSITIVITY_FS_8G;
        break;

    case LSM6DSOX_16g:
        *sensitivity_out = LSM6DSOX_ACC_SENSITIVITY_FS_16G;
        break;

    default:
        ret = LSM6DSOX_NOK;
        break;
    }

    return ret;
}

static angularVelocity_t read_angular_velocity()
{
    uint8_t status;
    angularVelocity_t angularVelocity = {0};
    u8U16Union_t angularVelocityU8Union = {0};
    float sensitivity = 0.0f;

    if ((lsm6dsox_gy_flag_data_ready_get(&g_stmdevCtx, &status) == LSM6DSOX_OK) && (status == 1) &&
        (lsm6dsox_angular_rate_raw_get(&g_stmdevCtx, angularVelocityU8Union.u16Data) == LSM6DSOX_OK) &&
        (get_angular_velocity_sensitivity(&sensitivity) == LSM6DSOX_OK))
    {
        angularVelocity.x = (int32_t)((float)((float)angularVelocityU8Union.u16Data[0] * sensitivity));
        angularVelocity.y = (int32_t)((float)((float)angularVelocityU8Union.u16Data[1] * sensitivity));
        angularVelocity.z = (int32_t)((float)((float)angularVelocityU8Union.u16Data[2] * sensitivity));
    }

    return angularVelocity;
}

static int32_t get_angular_velocity_sensitivity(float *sensitivity_out)
{
    lsm6dsox_fs_g_t full_scale;
    int32_t ret = LSM6DSOX_OK;

    if (lsm6dsox_gy_full_scale_get(&g_stmdevCtx, &full_scale) != LSM6DSOX_OK)
    {
        return LSM6DSOX_NOK;
    }

    switch (full_scale)
    {
    case LSM6DSOX_125dps:
        *sensitivity_out = LSM6DSOX_GYRO_SENSITIVITY_FS_125DPS;
        break;

    case LSM6DSOX_250dps:
        *sensitivity_out = LSM6DSOX_GYRO_SENSITIVITY_FS_250DPS;
        break;

    case LSM6DSOX_500dps:
        *sensitivity_out = LSM6DSOX_GYRO_SENSITIVITY_FS_500DPS;
        break;

    case LSM6DSOX_1000dps:
        *sensitivity_out = LSM6DSOX_GYRO_SENSITIVITY_FS_1000DPS;
        break;

    case LSM6DSOX_2000dps:
        *sensitivity_out = LSM6DSOX_GYRO_SENSITIVITY_FS_2000DPS;
        break;

    default:
        ret = LSM6DSOX_NOK;
        break;
    }

    return ret;
}
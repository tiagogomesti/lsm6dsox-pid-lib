#ifndef LSM6_IMU_H
#define LSM6_IMU_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdint.h>

#define LSM6DSOX_ACC_SENSITIVITY_FS_2G 0.061f
#define LSM6DSOX_ACC_SENSITIVITY_FS_4G 0.122f
#define LSM6DSOX_ACC_SENSITIVITY_FS_8G 0.244f
#define LSM6DSOX_ACC_SENSITIVITY_FS_16G 0.488f

#define LSM6DSOX_GYRO_SENSITIVITY_FS_125DPS 4.375f
#define LSM6DSOX_GYRO_SENSITIVITY_FS_250DPS 8.750f
#define LSM6DSOX_GYRO_SENSITIVITY_FS_500DPS 17.500f
#define LSM6DSOX_GYRO_SENSITIVITY_FS_1000DPS 35.000f
#define LSM6DSOX_GYRO_SENSITIVITY_FS_2000DPS 70.000f

typedef struct
{
    int32_t x;
    int32_t y;
    int32_t z;
} acceleration_t;

typedef struct
{
    int32_t x;
    int32_t y;
    int32_t z;
} angularVelocity_t;

typedef struct
{
    acceleration_t acceleration;
    angularVelocity_t angularVelocity;
} lsm6ImuData_t;

bool lsm6_imu_init(void);
lsm6ImuData_t lsm6_imu_read(void);

#ifdef __cplusplus
}
#endif

#endif /* LSM6_IMU_H */
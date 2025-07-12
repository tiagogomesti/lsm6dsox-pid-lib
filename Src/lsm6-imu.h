#ifndef LSM6_IMU_H
#define LSM6_IMU_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdint.h>

typedef struct
{
    uint16_t acceleration;
    uint16_t angularVelocity;
} lsm6ImuData_t;

bool lsm6_imu_init(void);
lsm6ImuData_t lsm6_imu_read(void);

#ifdef __cplusplus
}
#endif

#endif /* LSM6_IMU_H */
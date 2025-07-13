#ifndef HAL_SPI_H
#define HAL_SPI_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdint.h>

typedef enum
{
    HAL_NO_ERROR = 0,
    HAL_ERROR
} HalErrorType_t;

HalErrorType_t hal_spi_init(void);
int32_t hal_spi_read(void *optData, uint8_t reg, uint8_t *data, uint16_t len);
int32_t hal_spi_write(void *optData, uint8_t reg, const uint8_t *data, uint16_t len);

#ifdef __cplusplus
}
#endif

#endif /* HAL_SPI_H */
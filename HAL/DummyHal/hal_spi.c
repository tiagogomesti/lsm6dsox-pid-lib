#include "hal_spi.h"

#define UNUSED(X) (void)(X)

HalErrorType_t hal_spi_init(void)
{
    return HAL_ERROR;
}

HalErrorType_t hal_spi_read(void *optData, uint8_t reg, uint8_t *data, uint16_t len)
{
    UNUSED(optData);
    UNUSED(reg);
    UNUSED(data);
    UNUSED(len);
    return HAL_ERROR;
}

HalErrorType_t hal_spi_write(void *optData, uint8_t reg, uint8_t *data, uint16_t len)
{
    UNUSED(optData);
    UNUSED(reg);
    UNUSED(data);
    UNUSED(len);
    return HAL_ERROR;
}

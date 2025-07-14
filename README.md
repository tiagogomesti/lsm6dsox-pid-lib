# API to read accelerometer and gyroscope data from LSM6DSOX device

## Important Info
- This API uses a generic HAL, so to use it on specific HW, it's necessary:
  - Add a folder inside HAL folder and reference this folder on cmake configuration command
  - The folder must contain the files hal_spi.h and hal_spi.c and contains the below functions declared/defined:
    ```C
    HalErrorType_t hal_spi_init(void);
    int32_t hal_spi_read(void *optData, uint8_t reg, uint8_t *data, uint16_t len);
    int32_t hal_spi_write(void *optData, uint8_t reg, const uint8_t *data, uint16_t len);
    ```

## How to compile

### Requirement
- GCC installed
- CMake installed

### Compilation
Execute the command below to compile this project
```sh
# Go to project root folder

# Fetch the submodule used
git submodule update --init --recursive

# Create build folder
mkdir build && cd build

# If you didn't define your HAL folder
cmake ../

# If you defined your HAL folder
cmake -DHAL_TYPE=<NAME_OF_YOUR_HAL_FOLDER> ../

# Compile the project
make

# Run the unit tests
./Test/ut_lsm6-imu

```
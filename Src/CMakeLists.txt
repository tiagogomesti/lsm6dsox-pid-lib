# Add the current directory (Src) to the include directories to ensure lsm6-imu.h is found
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Add the lsm6-imu library
add_library(lsm6-imu STATIC
    lsm6-imu.c
)

# Link the lsm6-imu library with the HAL and Lib interfaces
target_link_libraries(lsm6-imu
    PUBLIC HAL_Interface
    PUBLIC Lib_Interface
)

# Ensure that the include directories of the HAL and Lib interfaces are propagated to anyone using lsm6-imu
target_include_directories(lsm6-imu PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
)
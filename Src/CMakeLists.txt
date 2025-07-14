include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_library(lsm6-imu STATIC
    lsm6-imu.c
)

target_link_libraries(lsm6-imu
    PUBLIC HAL_Interface
    PUBLIC Lib_Interface
)

target_include_directories(lsm6-imu PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
)
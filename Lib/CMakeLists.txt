add_library(Lib_Interface INTERFACE)

target_sources(Lib_Interface INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/lsm6dsox-pid/lsm6dsox_reg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/lsm6dsox-pid/lsm6dsox_reg.h
)

target_include_directories(Lib_Interface INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/lsm6dsox-pid>
    $<INSTALL_INTERFACE:include>
)
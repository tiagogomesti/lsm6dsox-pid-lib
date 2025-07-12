# Create an interface library for the Lib
add_library(Lib_Interface INTERFACE)

# Add lsm6dsox_reg.c and lsm6dsox_reg.h to the interface
target_sources(Lib_Interface INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/lsm6dsox-pid/lsm6dsox_reg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/lsm6dsox-pid/lsm6dsox_reg.h
)

# Add the lsm6dsox-pid directory as a public include directory for the interface
target_include_directories(Lib_Interface INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/lsm6dsox-pid>
    $<INSTALL_INTERFACE:include>
)
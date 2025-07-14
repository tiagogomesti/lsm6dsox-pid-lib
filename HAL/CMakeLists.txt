if(NOT DEFINED HAL_TYPE)
    set(HAL_TYPE "DummyHal")
    message(WARNING "HAL_TYPE not defined. Using 'DummyHal' as default.")
endif()

set(HAL_DIR "${CMAKE_CURRENT_SOURCE_DIR}/${HAL_TYPE}")

if(NOT IS_DIRECTORY ${HAL_DIR})
    message(FATAL_ERROR "The HAL directory '${HAL_DIR}' does not exist. Please check HAL_TYPE.")
endif()

include_directories(${HAL_DIR})

add_library(HAL_Interface INTERFACE)

target_sources(HAL_Interface INTERFACE
    ${HAL_DIR}/hal_spi.c
    ${HAL_DIR}/hal_spi.h
)

target_include_directories(HAL_Interface INTERFACE
    $<BUILD_INTERFACE:${HAL_DIR}>
    $<INSTALL_INTERFACE:include>
)
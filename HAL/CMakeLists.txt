# Define the HAL directory variable, defaulting to DummyHal if HAL_TYPE is not defined
if(NOT DEFINED HAL_TYPE)
    set(HAL_TYPE "DummyHal")
    message(WARNING "HAL_TYPE not defined. Using 'DummyHal' as default.")
endif()

# Construct the full path to the HAL directory
set(HAL_DIR "${CMAKE_CURRENT_SOURCE_DIR}/${HAL_TYPE}")

# Check if the HAL_TYPE directory exists
if(NOT IS_DIRECTORY ${HAL_DIR})
    message(FATAL_ERROR "The HAL directory '${HAL_DIR}' does not exist. Please check HAL_TYPE.")
endif()

# Add the selected HAL directory to the include directories
include_directories(${HAL_DIR})

# Create an interface library for the HAL
add_library(HAL_Interface INTERFACE)

# Add hal_spi.c and hal_spi.h from the selected HAL to the interface
target_sources(HAL_Interface INTERFACE
    ${HAL_DIR}/hal_spi.c
    ${HAL_DIR}/hal_spi.h
)

# Add the selected HAL directory as a public include directory for the interface
target_include_directories(HAL_Interface INTERFACE
    $<BUILD_INTERFACE:${HAL_DIR}>
    $<INSTALL_INTERFACE:include> # For when you install the project
)
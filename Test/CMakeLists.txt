include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
  DOWNLOAD_EXTRACT_TIMESTAMP true
  GIT_PROGRESS TRUE
)

FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
    FetchContent_Populate(googletest)
endif()

set(GOOGLETEST_BINARY_DIR "${CMAKE_CURRENT_BINARY_DIR}/_googletest_build") 
add_subdirectory(${googletest_SOURCE_DIR} ${GOOGLETEST_BINARY_DIR} EXCLUDE_FROM_ALL)

add_executable(
    ut_lsm6-imu
        ../Src/lsm6-imu.c
        ut_lsm6-imu.cpp
)

target_link_libraries(
    ut_lsm6-imu
    PRIVATE
        gtest_main 
        gmock      
)

target_include_directories(ut_lsm6-imu PRIVATE
    ${googletest_SOURCE_DIR}/googletest/include
    ${googletest_SOURCE_DIR}/googlemock/include
    ../HAL/DummyHal
    ../Lib/lsm6dsox-pid
    ../Src
)



enable_testing()

add_test(NAME ut_lsm6-imu_gtest COMMAND ut_lsm6-imu)
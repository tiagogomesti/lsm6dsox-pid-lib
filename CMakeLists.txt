cmake_minimum_required(VERSION 3.10.0)
project(lsm6-imu VERSION 0.1.0 LANGUAGES C CXX)

# Add subdirectories
add_subdirectory(HAL)
add_subdirectory(Lib)
add_subdirectory(Src)
add_subdirectory(Test)

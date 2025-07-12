# LSM6 IMU Driver Implementation & Testing

## Driver library

- Write a small, reusable **C / C++** library for an ST **LSM6** IMU (any recent variant).
- The API must allow a user to
    - initialize the device,
    - read accelerometer and gyroscope data and return acceleration and angular velocity

## Unit tests with mocks

- Add a test suite with unit test for the driver without the real hardware (mock the I²C/SPI transactions).

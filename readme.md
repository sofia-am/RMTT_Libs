# RMTT_Libs
OpenSource library that programs the Expansion Module of Robomaster's Tello TT drone.

## RMTT_Protocol
This class defines an interface to control the drone using Tello's commands. It contains various methods for sending different commands to the drone, along with callback functions to handle responses. The communication is done via the interface `Serial1` that connects the Expansion Module to the Drone. 
## RMTT_RGB
This class contains functions used for controlling the Expansion Module's RGB LED using the LEDC (LED Controller) module on its microcontroller. It includes methods to initialize the LEDC, set individual color components (Red, Green, Blue), and set an RGB color.
## RMTT_TOF
Functions that provide a high-level interface to the VL53L0X sensor, abstracting many low-level details of I2C communication and sensor configuration. Users can interact with the sensor and configure its behavior using these provided methods.
## RMTT_Shell
Provides functionality for handling and processing commands received over some communication channel. It includes several functions and data structures to manage and process these commands. 
## RMTT_Matrix
Defines a class and related functions for controlling LED matrices using the IS31FL3733 driver. It provides a high-level interface for initializing, configuring, and controlling the LEDs on the matrix, as well as low-level I2C communication functions for interfacing with the IS31FL3733 driver.
## RMTT_GamesirT1d
Primarily focuses on initializing the BLE communication with the Gamesir T1d controller and handling data received from it. Additionally, it supports MAC filtering for improved security.

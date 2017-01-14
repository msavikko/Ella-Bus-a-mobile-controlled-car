# The Ella Buss

This project has been developed under the tutalage of the "System Development" course within the Software Engineering and Management course, Gothenburg University.

It is a smartCar controlled by a mobile application. Components:

# 1. The SmartCar
- A smartCar controlled through DC motor, and several Arduino boards.
- The Arduino boards are in charge of the steering of the car, and "plate number" display.
- The car implemenents a form of a warning if any object is found in front of it.
- The car implemenets a camera which the user can use in order to see on the EllaBuss application the surroundings of the car.
- The car implements a form of steering control in the case in which the camera is about to collide (back and front rear).

# 2. Mobile Application
- The user (intended for children) is able to steer the car through joystick or a button menu on the application.
- The user can see the live streaming of the camera found on the car.
- The application has a "drawing" functionality as well.

# 3. Raspberry Pi - Camera Module
- streams real time the environment of the camera.

# 4. Others
- The steering is done through a Bluetooth module.
- The streaming is done through a Wifi module found on the Raspberry Pi.

# ServoDistanceScale
This is a simple arduino servo based distance scale, where the ultrasonic sensor measures the distance of the near target and the servo points at it

Materials: 
          Hardware:
          1. Arduino UNO Board
          2. Ultrasonic Sensor HC-SR04
          3. Servo Motor
          4. Wires
          5. Ruler, Compass, Solid target
          6. BreadBoard
          Software:
          1. Arduino IDE (Make sure it has servo library installed in it)
          
 
 Functioning: When we know the speed of sound, and we can determine the ping time by using pulseIn() function with the echopin. when we have the two variables, we can easily account for the distance variable.
 Now for the servo, we need to perform different calculations, according to the scale of our desire. the calculations of the servo position are enclosed in this repository as a separate file.
 

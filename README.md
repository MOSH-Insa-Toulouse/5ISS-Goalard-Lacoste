# Microcontrollers & Open Source Hardware (M&OSH)
This repository contains all the work and related documents realised by Rémi and David as part of the "Microcontroller & Open Source Hardware" major.  
Here is what you can find in this file :
* Course objectives
* Project description
* Technical realisation
* Delivery
* Conclusion
  

## Course objectives
The main objective of this class is to provide a transversal perspective of the creation of an IoT system. From the solution proposal to the end of system design, we take a look at all the conception steps, trying to merge both the hardware and software requirements.

## Project desciption
This project is a multidisciplinary work built around the use of a gas sensor. The idea is the following : we conceived a gas sensor to monitor air quality, and now want to integrate it in on an electronic card to collect data from its environment, then send them over a low speed network. As it is multidisciplinary, we divided the project in various steps : 
* Gas sensor conception
* Data communication via LoRa
* Hardware & PCB design

## Technical realisation
Let's look at the different steps of the project through the technical realisation point of view.

### Gas sensor conception
The gas sensor designed for monitoring air quality is composed of two sensing elements. Both are based on a combinaison of silicon substrate with tungsten trioxide nanoparticles, and allow to detect gas concentration regarding the variation of their conductivity. The sensor also integrate a temperature sensor, and only need a few mA to work.   

The sensor parts are described in the following schema :  

![Local Image](image1.png)

The gas sensor was conceived in AIME in october, but we will use a commercial sensor in the next steps of the project for simplicity reasons. 

### Data communication via LoRa
Now we have a working sensor, we want to be able to send the retrieved data. To do so, we will use LoRa protocol and the gateway accessible at INSA via ChirpStack.
In order to achieve the communication, we need a few elements :
* Electonical card (Arduino UNO)
* LoRa communication module (RN2483), plugged to the UNO
* Gas sensor (MQ2), plugged to the UNO
  
First, we use the RN2483 datasheet and choose the pins to use to connect it to the Arduino UNO :

![Local Image](image2.png)

The chosen pins are welded,  then the module is connected to the arduino using wires and a breadboard :

<img src="image3.jpg" alt="Description" width="300"/>

![Local Image](image4.jpg)

#### 

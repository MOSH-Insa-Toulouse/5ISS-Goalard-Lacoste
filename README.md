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
* Online data retrieving
* Harware & PCB design

## Technical realisation
Let's look at the different steps of the project through the technical realisation point of view.

### Gas sensor conception
The gas sensor designed for monitoring air uality is composed of two sensing elements. Both are based on a combinaison of silicon substrate with tungsten trioxide nanoparticles, and allow to detect gas concentration regarding the variation of their conductivity. The sensor also integrate a temperature sensor, and only need a few mA to work.   

The sensor parts are described in the following schema :  

![Local Image](image1.png)

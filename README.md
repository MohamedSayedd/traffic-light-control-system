# Traffic Light Control System

## Introduction
This project involves designing and implementing a traffic light control system for a four-way intersection, including pedestrian crossing features. The system is built using an STM32F103 microcontroller to ensure safe and efficient traffic and pedestrian flow.

## Objectives
- Implement a traffic light control system using an STM32F103 microcontroller.
- Manage traffic lights for North-South and East-West directions.
- Include pedestrian crossing signals and handle pedestrian requests.
- Utilize a finite state machine (FSM) for managing state transitions.

## Hardware Setup

### Components List
- **Microcontroller**: STM32F103
- **LEDs**: Red, Yellow, Green for both NS and EW directions
- **Pedestrian Signals**: Walk, Don't Walk for both NS and EW directions
- **Buttons**: Pedestrian request buttons for NS and EW
- **Resistors**: Current-limiting resistors for LEDs

### Circuit Diagram
![cct](https://github.com/user-attachments/assets/ab40c315-b730-4e52-8882-505f6083b1af)

*Figure 1: Complete circuit schematic of the traffic light system*

### Hardware Implementation
![photo_2025-01-04_23-29-09](https://github.com/user-attachments/assets/f58d1912-bb16-4f79-baa3-c2d4566d0361)

*Figure 2: Physical implementation of the system*

## Software Design

### Code Structure
- **main.c**: Contains the main loop and system initialization.
- **traffic_control.c**: Manages traffic light and pedestrian signal states.
- **System_Init.c**: Handles system initialization, including clocks and GPIOs.

### Function Descriptions
- `updateTrafficState()`: Updates the traffic light and pedestrian signal states.
- `configureTrafficLights()`: Configures the traffic lights for both NS and EW directions.
- `configurePedestrianSignals()`: Configures the pedestrian signals for both NS and EW directions.
- `processPedestrianRequest()`: Processes pedestrian requests and transitions to the appropriate crossing state.

## State Machine Diagram
![STATE_MACHINE drawio](https://github.com/user-attachments/assets/cf5489a9-6592-4e35-888f-90d6ad4ddbf9)

*Figure 3:The state machine diagram shows the logical flow of the traffic light control system, detailing the different states and transitions based on timing and pedestrian requests*



# **Washing Machine Controller using PIC16F877A**

### Embedded Systems Internship Project – Emertxe (May–June 2025)

### Author: Shreyas R. Kamble, Walchand College of Engineering, Sangli

---

## **1. Introduction**

This project implements a complete washing machine control system using the PIC16F877A microcontroller.
It simulates real-world washing machine operations such as program selection, water level selection, timing control, and stage transitions (Wash → Rinse → Spin).

The system is developed entirely in Embedded C using MPLAB X IDE and XC8 compiler, and tested on PICSimLab without requiring physical hardware.
It demonstrates state-machine based design, peripheral interfacing, timing accuracy, and real-time embedded system control.

Project Demo Video

Watch the full working simulation of the washing-machine controller here:
https://www.youtube.com/watch?v=qscuplNj33k

---

## **2. Project Objectives**

* Develop a complete washing machine controller using PIC16F877A
* Implement user interaction through digital keypad
* Interface LCD, buzzer, fan (motor simulation), and timers
* Simulate wash, rinse, and spin stages
* Demonstrate real-time control using timers and interrupts
* Build and test the project using PICSimLab

---

## **3. Key Features**

### **Program Selection**

* Quick Wash
* Normal Wash
* Heavy Wash
* Wash Only
* Spin Only

### **Water Level Options**

* Low
* Medium
* High
* Maximum

### **Functional Features**

* LCD displays all stages and messages
* Buzzer used for completion and alerts
* Fan simulates drum motor
* Time durations vary based on selected mode & water level
* State-machine based transitions
* Short and long key-press detection

---

## **4. Tools and Technologies**

### **Hardware (Simulated)**

* PIC16F877A microcontroller
* 6-key digital keypad
* 16x4 character LCD
* Buzzer
* Motor/Fan simulation

### **Software**

* MPLAB X IDE
* XC8 Compiler
* PICSimLab Simulator

---

## **5. System Block Diagram**

```
                     +--------------------------------------------+
 Inputs              |               PIC16F877A MCU               |             Outputs
-------------------->|                                            |------------------------------->
 Digital Keypad      |   • State Machine Controller               |   LCD Display (16x4)
 (SW4, SW5, SW6)     |   • Program Selection Logic                |   Process Status & Timers
                     |   • Water Level Selection Logic            |
                     |                                            |------------------------------->
 Timer2 (Internal)   |   • Timer-Based Cycle Control              |   Motor / Fan (Drum Simulation)
 (Wash/Rinse/Spin)   |   • Delay Generation                       |   Wash / Rinse / Spin Control
                     |                                            |
-------------------->|                                            |------------------------------->
 Start/Stop Inputs   |   • Keypad Interface                       |   Buzzer Alerts
 (User Controls)     |   • Short/Long Press Detection             |   Cycle Completion / Errors
                     |                                            |
-------------------->|                                            |------------------------------->
 Optional Sensors    |   • GPIO Ports                             |   Indicators / LEDs (Optional)
 (Water Level / Temp)|   • ADC / I2C / UART Support (Future)      |   Debug / Status Indicators
                     +--------------------------------------------+
```

---

## **6. Washing Machine Workflow**

```
                     +---------------------------------------------+
 User Actions        |            Washing Machine Workflow          |        System Actions
-------------------->|                                              |------------------------------->
 Power On (SW5)      |   • Initialize System                        |   LCD: Welcome Animation
                     |   • Enter PROGRAM_SELECT state               |
                     +---------------------------------------------+
                                      |
                                      v
                     +---------------------------------------------+
 Program Selection   |   • Scroll Programs (SW4 Short Press)        |   LCD: Show Program Options
-------------------->|   • Select Program (SW4 Long Press)          |------------------------------->
                     +---------------------------------------------+
                                      |
                                      v
                     +---------------------------------------------+
 Water Level Select  |   • Scroll Water Levels (SW4 Short Press)    |   LCD: Display Levels
-------------------->|   • Confirm Level (SW4 Long Press)           |------------------------------->
                     +---------------------------------------------+
                                      |
                                      v
                     +---------------------------------------------+
 Start / Stop Screen |   • Start Cycle (SW5)                        |   Initialize Timers
-------------------->|   • Go Back (SW6)                            |------------------------------->
                     +---------------------------------------------+
                                      |
                                      v
+------------------------------------------------------------------------------------------------+
|                                      RUN CYCLE                                                 |
+------------------------------------------------------------------------------------------------+
                                      |
       -----------------------------------------------------------------------------------------
       |                                      |                                      |
       v                                      v                                      v
+---------------------+            +----------------------+               +----------------------+
|      WASH Phase     |            |    RINSE Phase       |               |     SPIN Phase       |
|---------------------|            |----------------------|               |----------------------|
| • Motor ON          |            | • Motor Toggle       |               | • Motor ON           |
| • Timer2 Delay      |            | • Timer2 Delay       |               | • Timer2 Delay       |
| • LCD: "Washing"    |            | • LCD: "Rinsing"     |               | • LCD: "Spinning"    |
+---------------------+            +----------------------+               +----------------------+
                                      |
                                      |
                                      v
                     +---------------------------------------------+
 Completion          |   • Stop Motor                               |   LCD: "Cycle Completed"
-------------------->|   • Activate Buzzer                          |------------------------------->
                     +---------------------------------------------+
                                      |
                                      v
                     +----------------------------------------------+
 System Reset        |   • Return to Program Selection              |   System Ready for New Cycle
-------------------->|                                              |------------------------------->
                     +----------------------------------------------+
```

---

## **7. Key Implementation Details**

### **Power-On Screen**

LCD displays startup animation and welcome messages.

### **Keypad Input Handling**

* Counter-based short/long press detection
* Software debouncing for stability

### **State Transitions**

* Each screen has defined enter/exit conditions
* Transitions occur only on valid inputs

### **Timer Control**

* Timer2 generates calibrated delays
* Durations vary by program & water level

### **Motor & Buzzer Control**

* Motor ON/OFF during wash phases
* Buzzer ON during completion

---

## **8. Real-Time Workflow (Explanation)**

1. Power On → LCD animation
2. Program selection using SW4
3. Water level selection
4. Start cycle using SW5
5. Wash → Rinse → Spin sequence
6. Completion message + buzzer

---

## **9. Challenges and Solutions**

| Challenge                       | Solution                                 |
| ------------------------------- | ---------------------------------------- |
| Keypad bouncing                 | Added software debouncing                |
| Short/long press identification | Counter-based detection                  |
| Timing inaccuracies             | Calibrated Timer2                        |
| Incorrect screen transitions    | Corrected state flags and edge detection |
| Long power-on delay             | Optimized delay values                   |

---

## **10. Testing and Simulation**

Verified on PICSimLab:

* Power-on animation
* Program scroll
* Water-level screen
* Start/Stop control
* Wash–Rinse–Spin timing
* Completion

Outputs tested:

* Motor (fan simulation)
* Buzzer
* LCD display updates

---

## **11. Repository Structure**

```
Internship_project.X/
│
├── nbproject/                 # MPLAB X project configuration files
├── main.c                     # Main application logic
├── clcd.c                     # LCD driver source file
├── clcd.h                     # LCD driver header
├── digital_keypad.c           # Keypad interface logic
├── digital_keypad.h           # Keypad interface header
├── timers.c                   # Timer2 delay generator
├── timers.h                   # Timer module header
├── isr.c                      # Interrupt service routines (if used)
├── washing_machine_header.h   # Central header file for globals/config
├── washiing_machine_function_def.c   # Washing machine state functions
├── washiing_machine_function_def.h   # Header for washing machine functions
├── .gitignore                 # Ignore auto-generated files
├── Makefile                   # Build configuration
└── README.md                  # Project documentation

```

---

## **12. How to Build and Run**

### **Step 1 — Clone the repository**

```
git clone https://github.com/ShreyasRKamble/Washing-machine-controller.git
```

### **Step 2 — Open in MPLAB X**

File → Open Project → Select `Internship_project.X`

### **Step 3 — Build**

Use “Clean and Build”.

### **Step 4 — Simulate**

Load `.hex` file in PICSimLab
Use SW4, SW5, SW6 to interact with the system.

---

## **13. Learning Outcomes**

* PIC16F877A architecture
* Embedded C programming
* LCD, keypad, buzzer, motor interfacing
* Timer & interrupt usage
* State-machine based design
* Simulation & debugging on PICSimLab
* End-to-end embedded development process

---

## **14. Future Enhancements**

* Automatic water-level sensing
* Child lock & safety interlocks
* Temperature-based wash (LM35)
* EEPROM program memory
* UART debugging/logging
* More wash modes

---

## **15. Author**

**Shreyas R. Kamble**
Electronics Engineering
Walchand College of Engineering, Sangli

---






Local Hardware Controller & Component Testing Framework
A modular, lightweight C++ framework built to isolate, initialize, and run local diagnostic tests on hardware sensors and system components. Designed with an object-oriented architecture to evaluate hardware component health in an isolated local environment without external network or server dependencies.
Key Features
Object-Oriented Design (OOP): Utilizes abstract base classes, inheritance, and virtual functions for modular hardware component integration.
Smart Memory Management: Employs modern C++ (C++17) standard features, including std::unique_ptr and std::move semantics, preventing memory leaks during component instantiation and execution.
Strict Local Isolation: Executes sensor diagnostics in a standalone environment, eliminating latency, external API credentials, or network routing bottlenecks.
Extensible Architecture: Easily scalable to support physical microcontrollers, serial communication interfaces, or custom silicon test harnesses.
Architecture Overview
       [ LocalTestEnvironment ]
                   |
     +-------------+-------------+
     |                           |
[ TemperatureSensor ]    [ LightSensor ]
  (HardwareComponent)     (HardwareComponent)


HardwareComponent (Abstract Base Class): Defines the standard lifecycle interfaces (initialize(), runLocalTest()) for all supported sensors.
TemperatureSensor / LightSensor (Derived Classes): Concrete implementations simulating/reading specific sensor inputs locally.
LocalTestEnvironment (Controller): Manages component registration and executes automated system-wide diagnostics.
Prerequisites & Dependencies
Language Standard: C++17 or higher
Compiler: g++ (GCC) or clang++
Build System (Optional): CMake 3.10+
Build and Run Instructions
Option 1: Direct Compilation via g++
Clone the repository and compile directly using the C++17 flag:
# Clone the repository
git clone https://github.com/MiguelEnrique1/local-hardware-controller.git
cd local-hardware-controller

# Compile the project
g++ -std=c++17 main.cpp -o local_hardware_test

# Run the executable
./local_hardware_test


Option 2: Build using CMake
# Create build directory
mkdir build && cd build

# Generate build files and compile
cmake ..
make

# Run the executable
./local_hardware_test


Sample Execution Output
============================================
 INICIANDO DIAGNÓSTICO LOCAL DE HARDWARE
 (Entorno aislado sin dependencias externas)
============================================

[INIT] Sensor de Temperatura (Temp_Sensor_Zone1) listo en puerto local.
[TEST OK] Temp_Sensor_Zone1 -> Lectura local: 25 C
--------------------------------------------
[INIT] Sensor de Luz (Light_Sensor_MainRoom) listo en puerto local.
[TEST OK] Light_Sensor_MainRoom -> Lectura local: 400 LUX
--------------------------------------------


Future Roadmap
[ ] Add Linux /sys/class file system interaction for real Linux system metrics profiling.
[ ] Integrate low-level bitwise register masks for direct memory-mapped IO simulation.
[ ] Implement automated unit testing suite using GoogleTest (gtest).
Author
Miguel Enrique Cazares Rivera
GitHub: @MiguelEnrique1


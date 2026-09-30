# Local Hardware Controller & Diagnostic Framework

A modular, low-level C++ framework designed to isolate, configure, and test hardware components in a strictly local execution environment without external network dependencies or remote API server routing.

## Key Features

- **Object-Oriented Component Abstraction:** Polymorphic `HardwareComponent` base class for modular sensor integration.
- **Strictly Local Test Execution:** Zero network calls or external server overhead for latency-free unit diagnostics.
- **Smart Pointer Memory Management:** Efficient utilization of `std::unique_ptr` for safe automatic memory cleanup.
- **Cross-Platform C++17 Compliance:** Standard C++ implementation compatible with Linux, macOS, and Windows.

## System Architecture

```text
[ LocalTestEnvironment ]
          |
   +------+------+
   |             |
[TempSensor] [LightSensor]
````
How to Build and Run
Prerequisites

C++17 Compatible Compiler (g++, clang++, or MSVC)

CMake 3.10+ (Optional)

Option 1: Direct Build with g++
```text
g++ -std=c++17 main.cpp -o local_hardware_test
./local_hardware_test
```
Option 2: Build using CMake
```text
mkdir build && cd build
cmake ..
make
./local_hardware_test
```
Sample Execution Output
```text
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
```
Future Roadmap

[ ] Add Linux /sys/class file system interaction for real Linux system metrics profiling.

[ ] Integrate low-level bitwise register masks for direct memory-mapped IO simulation.

[ ] Implement automated unit testing suite using GoogleTest (gtest).

Author: Miguel Enrique Cazares Rivera

GitHub: @MiguelEnrique1


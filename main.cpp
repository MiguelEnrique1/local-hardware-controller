#include <iostream>
#include <vector>
#include <memory>
#include <string>


class HardwareComponent {
protected:
    std::string componentName;
    bool isInitialized;

public:
    HardwareComponent(const std::string& name) 
        : componentName(name), isInitialized(false) {}

    virtual ~HardwareComponent() = default;

    virtual bool initialize() = 0;
    virtual void runLocalTest() = 0;

    std::string getName() const { return componentName; }
    bool getStatus() const { return isInitialized; }
};


class TemperatureSensor : public HardwareComponent {
private:
    float currentTemperature;

public:
    TemperatureSensor(const std::string& name) 
        : HardwareComponent(name), currentTemperature(24.5f) {}

    bool initialize() override {
        
        isInitialized = true;
        std::cout << "[INIT] Sensor de Temperatura (" << componentName << ") listo en puerto local.\n";
        return true;
    }

    void runLocalTest() override {
        if (!isInitialized) {
            std::cout << "[ERROR] " << componentName << " no está inicializado.\n";
            return;
        }
      
        currentTemperature += 0.5f; 
        std::cout << "[TEST OK] " << componentName << " -> Lectura local: " 
                  << currentTemperature << " °C\n";
    }
};

class LightSensor : public HardwareComponent {
private:
    int lightIntensityLux;

public:
    LightSensor(const std::string& name) 
        : HardwareComponent(name), lightIntensityLux(400) {}

    bool initialize() override {
        isInitialized = true;
        std::cout << "[INIT] Sensor de Luz (" << componentName << ") listo en puerto local.\n";
        return true;
    }

    void runLocalTest() override {
        if (!isInitialized) {
            std::cout << "[ERROR] " << componentName << " no está inicializado.\n";
            return;
        }
        std::cout << "[TEST OK] " << componentName << " -> Lectura local: " 
                  << lightIntensityLux << " LUX\n";
    }
};


class LocalTestEnvironment {
private:
    std::vector<std::unique_ptr<HardwareComponent>> components;

public:
    void registerComponent(std::unique_ptr<HardwareComponent> component) {
        components.push_back(std::move(component));
    }

    void runAllDiagnostics() {
        std::cout << "\n============================================\n";
        std::cout << " INICIANDO DIAGNÓSTICO LOCAL DE HARDWARE\n";
        std::cout << " (Entorno aislado sin dependencias externas)\n";
        std::cout << "============================================\n\n";

        for (const auto& comp : components) {
            if (comp->initialize()) {
                comp->runLocalTest();
            }
            std::cout << "--------------------------------------------\n";
        }
    }
};

int main() {
    LocalTestEnvironment testRunner;


    testRunner.registerComponent(std::make_unique<TemperatureSensor>("Temp_Sensor_Zone1"));
    testRunner.registerComponent(std::make_unique<LightSensor>("Light_Sensor_MainRoom"));

   
    testRunner.runAllDiagnostics();

    return 0;
}
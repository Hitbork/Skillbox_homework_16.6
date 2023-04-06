#include <iostream>
#include <sstream>

enum switches
{
    LIGHTS_INSIDE = 1,
    LIGHTS_OUTSIDE = 2,
    HEATERS = 4,
    WATER_PIPE_HEATING = 8,
    CONDITIONER = 16
};

int main() {
    // Greetings
    std::cout << "\n Smart house\n\n";

    int day = 1, hours = 0;

    int temperatureInside, temperatureOutside;

    bool movementOutside, isLightTurnedOn;

    int switches_state = 0;

    int colorOfTemperature = 5000;

    while (day <= 2) {
        hours = 0;
        while (hours <= 23) {
            // Input information
            std::cout << "Current day: " << day << std::endl;
            std::cout << "Current time: ";
            if (hours < 10) {
                std::cout << "0";
            }
            std::cout << hours << ":00\n\n";

            std::cout << "Insert info about:\n temperature outside;\n temperature inside;\n is there movement outside" <<
                         " (insert number, if it is not 0 there is no movement);\n is lights turned on (same as movement).\n";

            std::string stringOfInfo;

            std::getline(std::cin, stringOfInfo);

            std::stringstream temp_stream(stringOfInfo);

            std::string tempOutsideStr, tempInsideStr, movementOutsideStr, lightsTurnedOnStr;

            temp_stream >> tempOutsideStr >> tempInsideStr >> movementOutsideStr >> lightsTurnedOnStr;

            temperatureOutside = std::stoi(tempOutsideStr);
            temperatureInside = std::stoi(tempInsideStr);

            std::cout << "\n";

            if (std::stoi(movementOutsideStr) != 0) {
                movementOutside = true;
            } else {
                movementOutside = false;
            }

            if (std::stoi(lightsTurnedOnStr) != 0) {
                isLightTurnedOn = true;
            } else {
                isLightTurnedOn = false;
            }


            // Conditions for water pipe heating
            if ((temperatureOutside < 0) && !(switches_state & WATER_PIPE_HEATING)) {
                std::cout << "Water pipe heating turned on!\n\n";
                switches_state |= WATER_PIPE_HEATING;
            }

            if ((temperatureOutside > 5) && (switches_state & WATER_PIPE_HEATING)) {
                std::cout << "Water pipe heating turned off!\n\n";
                switches_state &= ~WATER_PIPE_HEATING;
            }

            // Conditions for lights outside
            if (((hours > 16) || (hours < 5)) && (movementOutside) && !(switches_state & LIGHTS_OUTSIDE)) {
                std::cout << "Lights outside turned on!\n\n";
                switches_state |= LIGHTS_OUTSIDE;
            }

            if (((hours >= 5) && (hours <= 16) && (switches_state & LIGHTS_OUTSIDE)) ||
                    (((hours > 16) || (hours < 5)) && (!movementOutside) && (switches_state & LIGHTS_OUTSIDE))) {
                std::cout << "Lights outside turned off!\n\n";
                switches_state &= ~LIGHTS_OUTSIDE;
            }

            // Conditions for heaters
            if ((temperatureInside < 22) && !(switches_state & HEATERS)) {
                std::cout << "Heaters turned on!\n\n";
                switches_state |= HEATERS;
            }

            if ((temperatureInside >= 25) && (switches_state & HEATERS)) {
                std::cout << "Heaters tuned off!\n\n";
                switches_state &= ~HEATERS;
            }

            // Conditions for conditioner
            if ((temperatureInside >= 30) && !(switches_state & CONDITIONER)) {
                std::cout << "Conditioner turned on!\n\n";
                switches_state |= CONDITIONER;
            }

            if ((temperatureInside <= 25) && (switches_state & CONDITIONER)) {
                std::cout << "Conditioner turned off!\n\n";
                switches_state &= ~CONDITIONER;
            }

            // Conditions for light inside
            if ((isLightTurnedOn) && !(switches_state & LIGHTS_INSIDE)) {
                std::cout << "Lights inside turned on!\n\n";
                switches_state |= LIGHTS_INSIDE;
            }

            if ((!isLightTurnedOn) && (switches_state & LIGHTS_INSIDE)) {
                std::cout << "Lights inside turned off!\n\n";
                switches_state &= ~LIGHTS_INSIDE;
            }

            // Conditions for lights
            if ((hours > 16) && (hours <= 20)) {
                colorOfTemperature -= 575;
            }

            if ((hours > 0) && (hours <= 16)) {
                colorOfTemperature = 5000;
            }

            if ((switches_state & LIGHTS_OUTSIDE) || (switches_state & LIGHTS_INSIDE)) {
                std::cout << "Color of temperature: " << colorOfTemperature << "K\n\n";
            }

            std::cout << "\n";
            hours++;
        }
        day++;
    }

    std::cout << "Smart house ended work!\n";
    return 0;
}

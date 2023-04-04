#include <iostream>

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

    while (day <= 2) {
        while (hours <= 24) {
            std::cout << "Current time: ";
            if (hours < 10) {
                std::cout << "0";
            }
            std::cout << hours << ":00\n";

            std::cout << "Insert info about temperature outside, temperature outside, is there movement outside" <<
                         "(insert number, if it is not 0 there is no movement), is lights turned on (same as movement)\n";

            std::string stringOfInfo;

            std::getline(std::cin, stringOfInfo);



            hours++;
        }
        day++;
    }

    return 0;
}

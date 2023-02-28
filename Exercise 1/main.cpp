#include <iostream>


// Function to check with certain accuracy
bool is_equal_to_zero(float number, float accuracy) {
    return ((number - accuracy <= 0) && (0 <= number + accuracy)) || (number < 0);
}


// Function to check if speed more than max speed
bool is_speed_max(float speed, float accuracy) {
    return (speed >= 150 - accuracy) || ((speed - accuracy <= 150) && (speed + accuracy >= 150));
}

int main() {
    // Greetings
    std::cout << "\n Speedometer\n\n\n";


    // Creating var and requesting data
    float speed = 0, delta;

    do {
        std::cout << "Insert delta of speed:\n";
        std::cin >> delta;
        std::cout << "\n";

        speed += delta;

        if (is_speed_max(speed, 0.01)) {
            speed = 150;
        }

        if (is_equal_to_zero(speed, 0.01)) {
            std::cout << "Current speed is: 0" << "\n\n\n";
        } else {
            char buffer[5];
            std::sprintf(buffer, "%.1f", speed);
            std::cout << "Current speed is: " << buffer << "\n\n\n";
        }

    } while (!is_equal_to_zero(speed, 0.01));

    std::cout << "Car stopped!\n";
}
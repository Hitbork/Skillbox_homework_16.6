#include <iostream>

int main() {
    // Greetings
    std::cout << "\n Speedometer\n\n\n";


    // Creating var and requesting data
    float speed = 0, delta;

    do {
        std::cout << "Current speed is " << speed << "\n\n";
        std::cout << "Insert delta of speed:\n";
        std::cin >> delta;
        std::cout << "\n";
    } while (speed > 0);
}

#include <iostream>


int main() {
    // Greetings
    std::cout << "\nFractional slitcher\n\n\n";


    // Creating vars and requesting data
    std::string firstPart, secondPart;
    std::cout << "Insert whole part of number:\n";
    std::cin >> firstPart;

    std::cout << "\nInsert fractional part of number:\n";
    std::cin >> secondPart;
    std::cout << "\n\n";

    double number = std::stod(firstPart + "." + secondPart);

    std::cout << "Number is: " << number << "\n";
}

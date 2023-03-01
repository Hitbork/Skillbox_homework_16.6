#include <iostream>
#include <sstream>
#include <cassert>

// Function to calculate expression
void calculating_result(std::stringstream &buffer_stream, double &result) {
    double number1, number2;
    char action;

    buffer_stream >> number1 >> action >> number2;

    switch (action) {
        case '+':
            result = number1 + number2;
            break;
        case '-':
            result = number1 - number2;
            break;
        case '*':
            result = number1 * number2;
            break;
        case '/':
            result = number1 / number2;
            break;
        default:
            std::cout << "Wrong input!\n";
            assert(false);
    }
}


int main() {
    // Greetings
    std::cout << "\nMini-calculator\n\n\n";


    // Creating string stream to input data from string
    std::string buffer;

    std::cout << "Insert expression:\n";
    std::cin >> buffer;
    std::cout << "\n\n";

    std::stringstream buffer_stream(buffer);

    double result;
    calculating_result(buffer_stream, result);

    std::cout << "Result: " << result << "\n";
}

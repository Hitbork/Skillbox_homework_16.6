#include <iostream>

int main() {
    // Greetings
    std::cout << "\nMechanical piano\n\n\n";


    // Creating array of notes
    std::string notes[7] = {"DO", "RE", "MI", "FA", "SOL", "LA", "SI"};

    // Creating var for melody
    std::string melody[12];

    std::cout << "Insert the melody:\n";

    for (int i = 0; i < 12; i++) {
        std::cin >> melody[i];
    }


    // Playing the melody
    std::cout << "\nPlaying the melody:\n";

    for (int i = 0; i < 12; i++) {
        std::string str = melody[i];
        for (int j = 0; j < str.length(); j++) {
            std::cout << notes[(int)str[j] - 48];
        }
        std::cout << "\n";
    }

}

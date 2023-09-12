#include <iostream>
#include <cstdlib>
#include <ctime>

// Function to generate a random password
std::string generatePassword(int length) {
    const std::string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    const int charCount = characters.length();
    std::string password;

    for (int i = 0; i < length; i++) {
        int randomIndex = rand() % charCount;
        password += characters[randomIndex];
    }

    return password;
}

int main() {
    int length = 12; // Default password length
    srand(static_cast<unsigned int>(time(nullptr)));

    while (true) {
        std::cout << "Lavia: A Super Simple Password Generator" << std::endl;
        std::cout << "Length: " << length << std::endl;
        std::cout << "Password: " << generatePassword(length) << std::endl;
        std::cout << "Press 'q' to quit, '+' to increase length, or '-' to decrease length: ";

        char ch;
        std::cin >> ch;

        if (ch == 'q') {
            break;
        } else if (ch == '+') {
            length++;
        } else if (ch == '-' && length > 1) {
            length--;
        }
    }

    return 0;
}

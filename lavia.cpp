#include <iostream>
#include <cstdlib>
#include <ctime>

std::string generatePassword(int length, bool includeAmbiguous) 
{
    const std::string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    const std::string specialCharacters = "!@#$%^&*()_+";
    const std::string ambiguousCharacters = "l1O0"; // Ambiguous characters
    const int charCount = characters.length();
    const int specialCharCount = specialCharacters.length();
    const int ambiguousCharCount = ambiguousCharacters.length();
    std::string password;

    for (int i = 0; i < length; i++) {
        int randomIndex;

        if (!includeAmbiguous) {
            randomIndex = rand() % (charCount + specialCharCount);
            if (randomIndex >= charCount) {
                password += specialCharacters[randomIndex - charCount];
            } else {
                password += characters[randomIndex];
            }
        } else {
            randomIndex = rand() % (charCount + specialCharCount + ambiguousCharCount);
            if (randomIndex < charCount) {
                password += characters[randomIndex];
            } else if (randomIndex < charCount + specialCharCount) {
                password += specialCharacters[randomIndex - charCount];
            } else {
                password += ambiguousCharacters[randomIndex - charCount - specialCharCount];
            }
        }
    }

    return password;
}

int main() {
    int length;
    bool includeAmbiguous = true;
    
    srand(static_cast<unsigned int>(time(nullptr)));

    std::cout << "Lavia: A Super Simple Password Generator" << std::endl;
    
    std::cout << "Enter a password length, in numbers (19, not nineteen): ";
    std::cin >> length;

    std::cout << "Include ambiguous characters such as 0 and O? (y/n): ";
    char choice;
    std::cin >> choice;
    if (choice == 'n' || choice == 'N') {
        includeAmbiguous = false;
    }

    // Generate and print the password
    std::cout << "Length: " << length << std::endl;
    std::cout << "Password: " << generatePassword(length, includeAmbiguous) << std::endl;

    return 0;} // Code to indicate a successful program termination

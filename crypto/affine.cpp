#include <iostream>
#include <string>
#include <cctype>

// Function to encrypt the message using the Affine Cipher
std::string encrypt(const std::string& message, int a, int b) {
    std::string encryptedMessage;
    for (char ch : message) {
        if (std::isalpha(ch)) {
            char encryptedChar = (a * (std::toupper(ch) - 'A') + b) % 26 + 'A';
            encryptedMessage += encryptedChar;
        } else {
            encryptedMessage += ch;
        }
    }
    return encryptedMessage;
}

// Function to decrypt the message using the Affine Cipher
std::string decrypt(const std::string& message, int a, int b) {
    // Calculate the multiplicative inverse of 'a' (mod 26)
    int aInverse = -1;
    for (int i = 0; i < 26; ++i) {
        if ((a * i) % 26 == 1) {
            aInverse = i;
            break;
        }
    }

    if (aInverse == -1) {
        std::cout << "Invalid value of 'a'. It must be coprime with 26." << std::endl;
        return "";
    }

    std::string decryptedMessage;
    for (char ch : message) {
        if (std::isalpha(ch)) {
            char decryptedChar = (aInverse * (std::toupper(ch) - 'A' - b + 26)) % 26 + 'A';
            decryptedMessage += decryptedChar;
        } else {
            decryptedMessage += ch;
        }
    }
    return decryptedMessage;
}

int main() {
    std::string message;
    int a, b;

    // Get the message to encrypt or decrypt
    std::cout << "Enter the message: ";
    std::getline(std::cin, message);

    // Get the values of 'a' and 'b'
    std::cout << "Enter the value of 'a': ";
    std::cin >> a;
    std::cout << "Enter the value of 'b': ";
    std::cin >> b;

    // Encrypt the message
    std::string encryptedMessage = encrypt(message, a, b);
    std::cout << "Encrypted message: " << encryptedMessage << std::endl;

    // Decrypt the message
    std::string decryptedMessage = decrypt(encryptedMessage, a, b);
    std::cout << "Decrypted message: " << decryptedMessage << std::endl;

    return 0;
}
```

// In this implementation, the `encrypt` function takes a message, along with the values of 'a' and 'b', and returns the encrypted message. The `decrypt` function takes an encrypted message, along with the values of 'a' and 'b', and returns the decrypted message.

// The main function prompts the user to enter a message, the values of 'a' and 'b', and then performs encryption and decryption on the message using the provided values. Finally, it displays the encrypted and decrypted messages.

// Please note that the values of 'a' must be coprime with 26 for the decryption to work correctly. Otherwise, the program will display an error message.
#include <iostream>

int main() {
    // Loop through ASCII values from 0 to 127 (standard ASCII range)
    for (int i = 0; i <= 127; ++i) {
        // Cast the integer ASCII value to a character
        char asciiChar = static_cast<char>(i); 

        // Print the ASCII value and its corresponding character
        // Note: Some characters (e.g., control characters below 32) might not be printable
        std::cout << "ASCII Value: " << i << ", Character: " << asciiChar << std::endl;
    }
    return 0;
}
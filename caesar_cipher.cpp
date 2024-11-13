#include <iostream>
#include <string>
using namespace std;

// Function to encrypt the text using Caesar Cipher
string caesarCipherEncrypt(const string& text, int shift) {
    string result = "";

    for (char ch : text) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            // Shift the character and wrap around within alphabet range
            result += char(int(base + (ch - base + shift) % 26));
        } else {
            // Non-alphabetic characters remain the same
            result += ch;
        }
    }
    return result;
}

// Function to decrypt the text using Caesar Cipher
string caesarCipherDecrypt(const string& text, int shift) {
    return caesarCipherEncrypt(text, 26 - shift);
}

int main() {
    string text;
    int shift;

    cout << "Enter text to encrypt: ";
    getline(cin, text);
    cout << "Enter shift amount: ";
    cin >> shift;

    string encryptedText = caesarCipherEncrypt(text, shift);
    cout << "Encrypted Text: " << encryptedText << endl;

    string decryptedText = caesarCipherDecrypt(encryptedText, shift);
    cout << "Decrypted Text: " << decryptedText << endl;

    return 0;
}

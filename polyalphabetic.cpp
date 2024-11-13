#include <iostream>
#include <string>
using namespace std;

// Function to encrypt text using a Polyalphabetic Cipher
string polyalphabeticCipherEncrypt(const string& text, const string& keyword) {
    string encryptedText;
    int keywordLength = keyword.size();

    for (int i = 0; i < text.size(); i++) {
        char ch = text[i];
        if (isalpha(ch)) {
            // Determine the shift based on the corresponding keyword character
            char shift = (isupper(keyword[i % keywordLength]) ? keyword[i % keywordLength] - 'A' : keyword[i % keywordLength] - 'a');
            // Encrypt the character based on whether it's uppercase or lowercase
            if (isupper(ch))
                encryptedText += char((ch - 'A' + shift) % 26 + 'A');
            else
                encryptedText += char((ch - 'a' + shift) % 26 + 'a');
        } else {
            // Non-alphabetic characters are added as they are
            encryptedText += ch;
        }
    }
    return encryptedText;
}

// Function to decrypt text using a Polyalphabetic Cipher
string polyalphabeticCipherDecrypt(const string& text, const string& keyword) {
    string decryptedText;
    int keywordLength = keyword.size();

    for (int i = 0; i < text.size(); i++) {
        char ch = text[i];
        if (isalpha(ch)) {
            // Determine the shift based on the corresponding keyword character
            char shift = (isupper(keyword[i % keywordLength]) ? keyword[i % keywordLength] - 'A' : keyword[i % keywordLength] - 'a');
            // Decrypt the character based on whether it's uppercase or lowercase
            if (isupper(ch))
                decryptedText += char((ch - 'A' - shift + 26) % 26 + 'A');
            else
                decryptedText += char((ch - 'a' - shift + 26) % 26 + 'a');
        } else {
            // Non-alphabetic characters are added as they are
            decryptedText += ch;
        }
    }
    return decryptedText;
}

int main() {
    string text, keyword;
    
    cout << "Enter text to encrypt: ";
    getline(cin, text);
    cout << "Enter keyword: ";
    cin >> keyword;

    string encryptedText = polyalphabeticCipherEncrypt(text, keyword);
    cout << "Encrypted Text: " << encryptedText << endl;

    string decryptedText = polyalphabeticCipherDecrypt(encryptedText, keyword);
    cout << "Decrypted Text: " << decryptedText << endl;

    return 0;
}

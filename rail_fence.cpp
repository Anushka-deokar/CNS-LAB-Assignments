#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to encrypt the text using the Rail Fence technique
string railFenceEncrypt(const string& text, int key) {
    vector<string> rail(key);
    bool down = false;
    int row = 0;

    // Place characters in a zigzag pattern across the rails
    for (char ch : text) {
        rail[row].push_back(ch);
        if (row == 0 || row == key - 1) down = !down;
        row += down ? 1 : -1;
    }

    // Concatenate rows to get the encrypted text
    string encryptedText;
    for (const string& r : rail) {
        encryptedText += r;
    }
    return encryptedText;
}

// Function to decrypt the text using the Rail Fence technique
string railFenceDecrypt(const string& cipherText, int key) {
    vector<string> rail(key);
    bool down = false;
    int row = 0;

    // Create an empty zigzag pattern to identify character placement
    vector<vector<bool>> mark(cipherText.length(), vector<bool>(key, false));
    for (int i = 0; i < cipherText.length(); i++) {
        mark[i][row] = true;
        if (row == 0 || row == key - 1) down = !down;
        row += down ? 1 : -1;
    }

    // Fill in the characters in the zigzag pattern from the cipher text
    int index = 0;
    for (int r = 0; r < key; r++) {
        for (int i = 0; i < cipherText.length(); i++) {
            if (mark[i][r] && index < cipherText.length()) {
                rail[r].push_back(cipherText[index++]);
            }
        }
    }

    // Read the zigzag pattern row by row to decrypt
    string decryptedText;
    row = 0;
    down = false;
    for (int i = 0; i < cipherText.length(); i++) {
        decryptedText.push_back(rail[row].front());
        rail[row].erase(rail[row].begin());
        if (row == 0 || row == key - 1) down = !down;
        row += down ? 1 : -1;
    }
    return decryptedText;
}

int main() {
    string text;
    int key;

    cout << "Enter text to encrypt: ";
    getline(cin, text);
    cout << "Enter number of rails (key): ";
    cin >> key;

    // Encrypt the text
    string encryptedText = railFenceEncrypt(text, key);
    cout << "Encrypted Text: " << encryptedText << endl;

    // Decrypt the text
    string decryptedText = railFenceDecrypt(encryptedText, key);
    cout << "Decrypted Text: " << decryptedText << endl;

    return 0;
}

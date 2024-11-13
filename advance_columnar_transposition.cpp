#include <iostream> 
#include <algorithm> 
#include <vector> 
using namespace std; 
// Function to reorder columns based on the key 
vector<int> getColumnOrder(string key) { 
int len = key.length(); 
vector<pair<char, int>> keyIndex(len); 
// Store each character and its index 
for (int i = 0; i < len; i++) { 
keyIndex[i] = make_pair(key[i], i); 
} 
// Sort based on key characters 
sort(keyIndex.begin(), keyIndex.end()); 
// Store the column order 
vector<int> order(len); 
for (int i = 0; i < len; i++) { 
order[i] = keyIndex[i].second; 
} 
return order; 
} 
// Function to encrypt the plain text using Advanced Columnar Transposition 
string encrypt(string plainText, string key) { 
int columns = key.length(); 
int rows = (plainText.length() + columns - 1) / columns; // Number of rows required 
vector<vector<char>> matrix(rows, vector<char>(columns, 'X')); // 'X' for padding 
// Fill the matrix row-wise with the plaintext 
for (int i = 0; i < plainText.length(); i++) { 
matrix[i / columns][i % columns] = plainText[i]; 
} 
// Get the column order based on the key 
vector<int> columnOrder = getColumnOrder(key); 
    // Read the matrix column-wise based on the new column order 
    string cipherText = ""; 
    for (int i = 0; i < columns; i++) { 
        int col = columnOrder[i]; 
        for (int j = 0; j < rows; j++) { 
            cipherText += matrix[j][col]; 
        } 
    } 
 
    return cipherText; 
} 
 
// Function to decrypt the cipher text 
string decrypt(string cipherText, string key) { 
    int columns = key.length(); 
    int rows = (cipherText.length() + columns - 1) / columns; // Number of rows required 
 
    vector<vector<char>> matrix(rows, vector<char>(columns)); 
 
    // Get the column order based on the key 
    vector<int> columnOrder = getColumnOrder(key); 
 
    // Fill the matrix column-wise using the cipher text 
    int k = 0; 
    for (int i = 0; i < columns; i++) { 
        int col = columnOrder[i]; 
        for (int j = 0; j < rows; j++) { 
            matrix[j][col] = cipherText[k++]; 
        } 
    } 
 
    // Read the matrix row-wise to get the plaintext 
    string plainText = ""; 
    for (int i = 0; i < rows * columns; i++) { 
        char c = matrix[i / columns][i % columns]; 
        if (c != 'X') { // Skip padding characters 
            plainText += c; 
        } 
    } 
 
    return plainText; 
} 
 
int main() { 
    string plainText, key; 
 
cout << "Enter the plain text: "; 
getline(cin, plainText); 
cout << "Enter the key: "; 
getline(cin, key); 
// Encrypt the plain text 
string cipherText = encrypt(plainText, key); 
cout << "Cipher Text: " << cipherText << endl; 
// Decrypt the cipher text 
string decryptedText = decrypt(cipherText, key); 
cout << "Decrypted Text: " << decryptedText << endl; 
return 0; 
}
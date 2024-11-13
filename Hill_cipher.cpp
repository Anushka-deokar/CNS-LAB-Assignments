#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

const int MATRIX_SIZE = 2;  // Size of the key matrix (2x2 matrix in this example)

// Function to calculate modular inverse of a number under modulo 26
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) return x;
    }
    return -1;
}

// Function to calculate the determinant of a 2x2 matrix and its modulo 26 inverse
int calculateDeterminant(const vector<vector<int>>& matrix) {
    int determinant = (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]) % 26;
    if (determinant < 0) determinant += 26;  // Ensure positive determinant
    return determinant;
}

// Function to find the inverse of a 2x2 matrix under modulo 26
vector<vector<int>> findMatrixInverse(const vector<vector<int>>& matrix) {
    int determinant = calculateDeterminant(matrix);
    int inverseDet = modInverse(determinant, 26);

    vector<vector<int>> inverseMatrix(MATRIX_SIZE, vector<int>(MATRIX_SIZE));
    inverseMatrix[0][0] = (matrix[1][1] * inverseDet) % 26;
    inverseMatrix[1][1] = (matrix[0][0] * inverseDet) % 26;
    inverseMatrix[0][1] = (-matrix[0][1] * inverseDet) % 26;
    inverseMatrix[1][0] = (-matrix[1][0] * inverseDet) % 26;

    // Ensure all elements are positive
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            if (inverseMatrix[i][j] < 0) inverseMatrix[i][j] += 26;
        }
    }
    return inverseMatrix;
}

// Function to multiply a matrix by a vector (mod 26)
vector<int> matrixMultiply(const vector<vector<int>>& matrix, const vector<int>& vec) {
    vector<int> result(MATRIX_SIZE, 0);
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            result[i] = (result[i] + matrix[i][j] * vec[j]) % 26;
        }
    }
    return result;
}

// Function to encrypt plaintext using the Hill cipher
string hillCipherEncrypt(const string& plaintext, const vector<vector<int>>& keyMatrix) {
    string ciphertext;
    for (size_t i = 0; i < plaintext.length(); i += MATRIX_SIZE) {
        vector<int> block(MATRIX_SIZE);
        for (int j = 0; j < MATRIX_SIZE; j++) {
            block[j] = plaintext[i + j] - 'A';
        }
        vector<int> encryptedBlock = matrixMultiply(keyMatrix, block);
        for (int val : encryptedBlock) {
            ciphertext += (val + 'A');
        }
    }
    return ciphertext;
}

// Function to decrypt ciphertext using the Hill cipher
string hillCipherDecrypt(const string& ciphertext, const vector<vector<int>>& inverseKeyMatrix) {
    string decryptedText;
    for (size_t i = 0; i < ciphertext.length(); i += MATRIX_SIZE) {
        vector<int> block(MATRIX_SIZE);
        for (int j = 0; j < MATRIX_SIZE; j++) {
            block[j] = ciphertext[i + j] - 'A';
        }
        vector<int> decryptedBlock = matrixMultiply(inverseKeyMatrix, block);
        for (int val : decryptedBlock) {
            decryptedText += (val + 'A');
        }
    }
    return decryptedText;
}

int main() {
    // Define a 2x2 key matrix for the Hill cipher
    vector<vector<int>> keyMatrix = {{3, 3}, {2, 5}};  // Example matrix

    // Calculate the inverse of the key matrix
    vector<vector<int>> inverseKeyMatrix = findMatrixInverse(keyMatrix);

    string plaintext;
    cout << "Enter plaintext (must have even length): ";
    getline(cin, plaintext);

    // Ensure plaintext is in uppercase and length is even
    for (char& ch : plaintext) ch = toupper(ch);
    if (plaintext.length() % MATRIX_SIZE != 0) plaintext += 'X';  // Padding with 'X' if needed

    // Encrypt the plaintext
    string ciphertext = hillCipherEncrypt(plaintext, keyMatrix);
    cout << "Encrypted Text: " << ciphertext << endl;

    // Decrypt the ciphertext
    string decryptedText = hillCipherDecrypt(ciphertext, inverseKeyMatrix);
    cout << "Decrypted Text: " << decryptedText << endl;

    return 0;
}

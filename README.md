# CNS Lab Assignments

This repository contains implementations of various cryptographic algorithms for the Computer Network Security (CNS) lab assignments. Each program demonstrates core concepts in encryption, decryption, and key exchange. Explore the assignments to understand different encryption techniques and their implementations in C++.

---

## Assignments

### 1. Caesar Cipher
**Description:** The Caesar Cipher is a substitution cipher that shifts each letter in the plaintext by a fixed number of positions down the alphabet. This is one of the simplest encryption techniques and is useful for understanding basic substitution ciphers.
- **Objective:** Implement encryption and decryption with a fixed shift key.


### 2. Playfair Cipher
**Description:** The Playfair Cipher encrypts digraphs (pairs of letters) using a 5x5 grid and a specific keyword. For this implementation, the key used is `ldrp`.
- **Objective:** Encrypt and decrypt messages using the Playfair technique and a keyword to generate the matrix.

### 3. Polyalphabetic Cipher
**Description:** The Polyalphabetic Cipher is an extension of the Caesar Cipher. It uses multiple shift values determined by a keyword, resulting in a more complex and secure encryption method.
- **Objective:** Implement a polyalphabetic cipher using a keyword to generate shifting values for each letter.


### 4. Hill Cipher
**Description:** The Hill Cipher is a polygraphic substitution cipher based on linear algebra. This assignment requires a custom matrix for encryption and finding its inverse for decryption.
- **Objective:** Implement encryption and decryption using a chosen matrix, ensuring correct decryption by calculating the matrix inverse.


### 5. Rail Fence Technique
**Description:** The Rail Fence Cipher is a transposition cipher that writes plaintext in a zigzag pattern across multiple "rails." This pattern is then read row-by-row to form the ciphertext.
- **Objective:** Implement encryption and decryption using the rail fence pattern with a variable number of rails.


### 6. Simple Columnar Transposition Technique
**Description:** The Simple Columnar Transposition Cipher rearranges plaintext letters into columns based on a fixed number of columns, then reads the letters column by column to form the ciphertext.
- **Objective:** Write code to encrypt and decrypt messages by arranging text in columns and transposing based on column order.


### 7. Advanced Columnar Transposition Technique
**Description:** This is a more complex version of the columnar transposition cipher, often involving multiple passes or shuffling based on a key for more security.
- **Objective:** Implement a multi-pass columnar transposition for enhanced security, based on a specific keyword for column arrangement.


### 8. Simplified DES Implementation
**Description:** Simplified DES (S-DES) is a smaller version of the Data Encryption Standard, designed to illustrate the fundamental principles of the DES algorithm without excessive complexity.
- **Objective:** Implement S-DES, using a simplified 10-bit key and focusing on core DES functions like expansion, substitution, and permutation.


### 9. Simplified AES Implementation
**Description:** Simplified AES (S-AES) is a compact version of the Advanced Encryption Standard, making it easier to understand core AES operations like substitution, shifting, and mixing.
- **Objective:** Implement S-AES with a smaller key size, focusing on the essential AES functions like S-box substitutions and MixColumns.


### 10. Diffie-Hellman Key Exchange Algorithm
**Description:** The Diffie-Hellman algorithm is a method for securely exchanging cryptographic keys over a public channel. It is a foundational technique for public-key cryptography.
- **Objective:** Demonstrate key exchange between two parties, each generating a shared secret key.


### 11. RSA Algorithm (Simple)
**Description:** RSA is a widely used public-key encryption algorithm that uses large prime numbers for secure encryption and decryption. This simplified version uses smaller numbers for demonstration.
- **Objective:** Implement RSA with small prime numbers to illustrate encryption and decryption, focusing on the modular arithmetic involved.


---

## Getting Started

Each program is written in **C++**. To compile and run any of the programs:
1. Clone this repository.
2. Open a terminal and navigate to the folder containing the desired program.
3. Compile the program:
   ```bash
   g++ program_name.cpp -o program_name


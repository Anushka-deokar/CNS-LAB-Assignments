#include <iostream>
#include <cmath>
using namespace std;

// Returns gcd of a and b
int gcd(int a, int h) {
    int temp;
    while (1) {
        temp = a % h;
        if (temp == 0)
            return h;
        a = h;
        h = temp;
    }
}

// Function to perform modular exponentiation (base^exp % mod)
long long modExp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) // If exp is odd, multiply base with result
            result = (result * base) % mod;
        exp = exp >> 1; // exp = exp / 2
        base = (base * base) % mod; // base = base^2 % mod
    }
    return result;
}

// RSA algorithm demonstration
int main() {
    // Two prime numbers
    int p = 3;
    int q = 7;

    // Calculating modulus n
    int n = p * q;

    // Calculating Euler's totient function phi(n)
    int phi = (p - 1) * (q - 1);

    // Finding an integer e such that 1 < e < phi(n) and gcd(e, phi) = 1
    int e = 2;
    while (e < phi) {
        if (gcd(e, phi) == 1)
            break;
        else
            e++;
    }

    // Calculating private key d such that (d * e) % phi(n) = 1
    int k = 1;
    int d = (1 + (k * phi)) / e;

    // Message to be encrypted
    int msg = 12;
    cout << "Message data: " << msg << endl;

    // Encryption: c = (msg ^ e) % n
    long long c = modExp(msg, e, n);
    cout << "Encrypted data: " << c << endl;

    // Decryption: m = (c ^ d) % n
    long long m = modExp(c, d, n);
    cout << "Original Message Sent: " << m << endl;

    return 0;
}

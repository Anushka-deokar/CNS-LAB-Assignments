/* This program calculates the Key for two persons 
using the Diffie-Hellman Key exchange algorithm using C++ */

#include <iostream>
#include <cmath>
using namespace std;

// Power function to return value of a^b mod P
long long int power(long long int a, long long int b, long long int P) {
    long long int result = 1;
    a = a % P;  // Update a if it is more than or equal to P

    while (b > 0) {
        // If b is odd, multiply a with the result
        if (b % 2 == 1) {
            result = (result * a) % P;
        }
        
        // b must be even now
        b = b >> 1;  // b = b / 2
        a = (a * a) % P;  // Change a to a^2
    }
    return result;
}

// Driver program
int main() {
    long long int P, G, x, a, y, b, ka, kb;

    // Both persons will agree on the public keys G and P
    P = 23; // A prime number P is chosen
    cout << "The value of P: " << P << endl;
    
    G = 9; // A primitive root for P, G is chosen
    cout << "The value of G: " << G << endl;

    // Alice chooses the private key a
    a = 4; // a is Alice's chosen private key
    cout << "The private key a for Alice: " << a << endl;
    x = power(G, a, P); // Generates Alice's public key

    // Bob chooses the private key b
    b = 3; // b is Bob's chosen private key
    cout << "The private key b for Bob: " << b << endl;
    y = power(G, b, P); // Generates Bob's public key

    // Generating the secret key after the exchange of public keys
    ka = power(y, a, P); // Secret key for Alice
    kb = power(x, b, P); // Secret key for Bob

    cout << "Secret key for Alice is: " << ka << endl;
    cout << "Secret key for Bob is: " << kb << endl;

    return 0;
}

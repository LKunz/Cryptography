#include <iostream>
#include <string.h>
#include "algo.hpp"

using namespace std;

/* Caesar Cipher using printable ASCII chars [32 (space) to 126 (~)] */
string caesar_encrypt(string message, int key) {
    
    string cipher("");

    for(int i=0;i<message.size();i++){

        int asciiNumber = int(message[i]) - 32;
        asciiNumber = (asciiNumber + key) % 95;
        asciiNumber += 32;

        cipher.push_back(char(asciiNumber));
        
    }

    return cipher;
}

string caesar_decrypt(string cipher, int key) {

    string message("");

    for(int i=0;i<cipher.size();i++){

        // Multiplier to avoid negative numbers
        int multiplier = key/95 + 1;
        int asciiNumber = int(cipher[i]) - 32;
        asciiNumber += multiplier*95;
        asciiNumber = (asciiNumber - key) % 95;
        asciiNumber += 32;

        message.push_back(char(asciiNumber));
    }

    return message;
}
/* END: Caesar Cipher */

/* VIGENERE Cipher using ASCII Chars. Mod is 95 */
string vigenere_encrypt(string message, string key) {
    
    string cipher("");

    int const keyLen = key.size();

    int j(0);

    for(int i=0;i<message.size();i++){

        int asciiNumber = int(message[i]) - 32;
        int asciiNumberKey = int(key[j]) - 32;

        asciiNumber = (asciiNumber + asciiNumberKey) % 95;
        asciiNumber += 32;

        cipher.push_back(char(asciiNumber));

        j += 1;
        j = j % keyLen;
        
    }

    return cipher;
}


string vigenere_decrypt(string cipher, string key) {

    string message("");

    int const keyLen = key.size();

    int j(0);

    for(int i=0;i<cipher.size();i++){

        int multiplier = key[j]/95 + 1;
        int asciiNumber = int(cipher[i]) - 32;
        int asciiNumberKey = int(key[j]) - 32;

        asciiNumber += multiplier*95;
        asciiNumber = (asciiNumber - asciiNumberKey) % 95;
        asciiNumber += 32;

        message.push_back(char(asciiNumber));

        j += 1;
        j = j % keyLen;
        
    }

    return message;
}
/* END: VIGENERE Cipher */


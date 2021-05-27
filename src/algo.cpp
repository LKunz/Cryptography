#include <iostream>
#include <string.h>
#include "algo.hpp"

using namespace std;

/* Caesar Cipher */
string caesar(string message, int key) {
    
    string cipher("");

    for(int i=0;i<message.size();i++){
        cipher += (message[i] - 'A'+key)%26+'A';
    }

    return cipher;
}

string caesar_decrypt(string cipher, int key) {

    string message("");

    for(int i=0;i<cipher.size();i++){
        message += (cipher[i]-'A'-key+26)%26+'A';
    }

    return message;

}




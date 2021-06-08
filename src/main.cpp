#include <iostream>
#include <fstream>
#include "algo.hpp"
#include "crack.hpp"
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <cstdlib>

using namespace std;

int main()
{   
    ifstream file("./python/sample.txt");

    string line;
    string text;

    if (file) {

        while (getline(file, line)) {
            text += line;
        }

    } else {
        cout << "ERROR!" << endl;
    }
    
    string cipher = vigenere_encrypt(text, "CIPHER");
    string decode = vigenere_decrypt(cipher, "CIPHER");

    //cout << text << endl;
    //cout << cipher << endl;
    //cout << decode << endl;

    text = "AAA!salut";


    // RSA    
    string m = rsa_encrypt(text, 17, 31);
    
    return 0;
}
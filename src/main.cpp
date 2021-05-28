#include <iostream>
#include <fstream>
#include "algo.hpp"
#include "crack.hpp"
#include <string>
#include <cmath>

using namespace std;

int main()
{
    string text("Nous partons dans 15 minutes.");
    //string cipher1 = caesar_encrypt(text, 1);
    string cipher = vigenere_encrypt(text, "CIPHER");
    string decode = vigenere_decrypt(cipher, "CIPHER");

    cout << text << endl;
    cout << cipher << endl;
    cout << decode << endl;


    return 0;
}
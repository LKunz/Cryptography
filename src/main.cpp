#include <iostream>
#include <fstream>
#include "algo.hpp"
#include "crack.hpp"
#include <string>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    string text("Nous partons dans 15 minutes.~iiiiiiiiiiiiiiiiiiii");
    //string cipher1 = caesar_encrypt(text, 1);
    string cipher = vigenere_encrypt(text, "CIPHER");
    string decode = vigenere_decrypt(cipher, "CIPHER");

    cout << text << endl;
    cout << cipher << endl;
    cout << decode << endl;

    vector<double> freq = frequencies(text, true, true);

    return 0;
}
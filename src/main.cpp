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
    /*
    string cipher = vigenere_encrypt(text, "CIPHER");
    string decode = vigenere_decrypt(cipher, "CIPHER");

    cout << text << endl;
    cout << cipher << endl;
    cout << decode << endl;

    Crack test(text);

    test.frequenciesAnalysis();

    map<char, double> freq = test.getFrequencies();

    for (pair<char, double> entry : freq)
    {
        cout << entry.first << "\t" << entry.second << endl;
    }

    cout << freq[' '] << endl;
    */
    
    pair<int, int> rsa_key (17, 31);
    string m = rsa_encrypt(text, rsa_key);
    
    return 0;
}
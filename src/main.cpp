#include <iostream>
#include <fstream>
#include "algo.hpp"
#include "crack.hpp"
#include <string>
#include <cmath>
#include <vector>
#include <map>

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

    Crack test(text);

    test.frequenciesAnalysis();

    map<char, double> freq = test.getFrequencies();

    for (auto itr = freq.begin(); itr != freq.end(); ++itr) {
		cout << itr->first << '\t' << itr->second << '\n';
	}

    cout << freq[" "] << endl;

    return 0;
}
#include <iostream>
#include <fstream>
#include "algo.hpp"
#include <string>
#include <cmath>

using namespace std;

int main()
{
    string text = "test ~";
    string cipher = vigenere_encrypt(text, "Aa ~abc");


    return 0;
}
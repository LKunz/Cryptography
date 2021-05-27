#include <iostream>
#include <fstream>
#include "algo.hpp"
#include <string.h>

using namespace std;

int main() {

string text("HELLO, BONJOUR, hello, bonjour,         123456789");

string cipher = caesar(text, 4);

cout << cipher << endl;

string m = caesar_decrypt(cipher, 4);

cout << m << endl;


return 0;

}
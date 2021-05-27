#include <iostream>

#ifndef ALGO_H_INCLUDED
#define ALGO_H_INCLUDED

#include <string.h>
using namespace std;

/* Caesar cipher*/
string caesar(string message, int key);
string caesar_decrypt(string cipher, int key);

#endif // ALGO_H_INCLUDED
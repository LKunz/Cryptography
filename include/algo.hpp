#include <iostream>

#ifndef ALGO_H_INCLUDED
#define ALGO_H_INCLUDED

#include <string.h>

/* Caesar cipher using ASCII number. Mod is 95*/
std::string caesar_encrypt(std::string message, int key);
std::string caesar_decrypt(std::string cipher, int key);

#endif // ALGO_H_INCLUDED
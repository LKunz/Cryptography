#include <iostream>

#ifndef ALGO_H_INCLUDED
#define ALGO_H_INCLUDED

#include <string.h>

/* Caesar cipher using ASCII number. Mod is 95*/
std::string caesar_encrypt(std::string message, int key);
std::string caesar_decrypt(std::string cipher, int key);

/* vigenere cipher using ASCII number. Mod is 95*/
std::string vigenere_encrypt(std::string message, std::string key);

#endif // ALGO_H_INCLUDED
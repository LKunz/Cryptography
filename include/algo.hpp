#include <iostream>

#ifndef ALGO_H_INCLUDED
#define ALGO_H_INCLUDED

#include <string.h>

/* Caesar cipher using ASCII number. Mod is 95*/
std::string caesar_encrypt(std::string message, int key);
std::string caesar_decrypt(std::string cipher, int key);

/* vigenere cipher using ASCII number. Mod is 95*/
std::string vigenere_encrypt(std::string message, std::string key);
std::string vigenere_decrypt(std::string message, std::string key);

/* RSA */
std::string rsa_encrypt(std::string message, int p, int q);

#endif // ALGO_H_INCLUDED
#include <iostream>
#include <string.h>
#include "algo.hpp"
#include <vector>
#include <cmath>
#include <cstdlib>
#include <time.h>

using namespace std;

/* Caesar Cipher using printable ASCII chars [32 (space) to 126 (~)] */
string caesar_encrypt(string message, int key) {
    
    string cipher("");

    for(int i=0;i<message.size();i++){

        int asciiNumber = int(message[i]) - 32;
        asciiNumber = (asciiNumber + key) % 95;
        asciiNumber += 32;

        cipher.push_back(char(asciiNumber));
        
    }

    return cipher;
}

string caesar_decrypt(string cipher, int key) {

    string message("");

    for(int i=0;i<cipher.size();i++){

        // Multiplier to avoid negative numbers
        int multiplier = key/95 + 1;
        int asciiNumber = int(cipher[i]) - 32;
        asciiNumber += multiplier*95;
        asciiNumber = (asciiNumber - key) % 95;
        asciiNumber += 32;

        message.push_back(char(asciiNumber));
    }

    return message;
}
/* END: Caesar Cipher */

/* VIGENERE Cipher using ASCII Chars. Mod is 95 */
string vigenere_encrypt(string message, string key) {
    
    string cipher("");

    int const keyLen = key.size();

    int j(0);

    for(int i=0;i<message.size();i++){

        int asciiNumber = int(message[i]) - 32;
        int asciiNumberKey = int(key[j]) - 32;

        asciiNumber = (asciiNumber + asciiNumberKey) % 95;
        asciiNumber += 32;

        cipher.push_back(char(asciiNumber));

        j += 1;
        j = j % keyLen;
        
    }

    return cipher;
}


string vigenere_decrypt(string cipher, string key) {

    string message("");

    int const keyLen = key.size();

    int j(0);

    for(int i=0;i<cipher.size();i++){

        int multiplier = key[j]/95 + 1;
        int asciiNumber = int(cipher[i]) - 32;
        int asciiNumberKey = int(key[j]) - 32;

        asciiNumber += multiplier*95;
        asciiNumber = (asciiNumber - asciiNumberKey) % 95;
        asciiNumber += 32;

        message.push_back(char(asciiNumber));

        j += 1;
        j = j % keyLen;
        
    }

    return message;
}
/* END: VIGENERE Cipher */

/* RSA */
int make_block(string text) {
    
    for (int i=0; i<text.size(); i++) {
        int asciiLetter = int(text[i]);
        cout << asciiLetter << endl;
        
    }
    return 0;
}

int gcd(int a, int b)  
 {  
   
    if (a == 0 || b == 0)  
        return 0;  
   
       
    if (a == b)  
        return a;  
   
   
    if (a > b)  
        return gcd(a-b, b);  
    return gcd(a, b-a);  
 } 

int lcm(int a, int b)  
 {  
    return (a*b)/gcd(a, b);  
 }  


int isPrime(int n){
  int flag = 1;
  for(int i=2;i<=sqrt(n);i++)
  {
      if(n%i==0)
      {
          flag = 0;
          return flag;
      }
  }
  return flag;
}

string rsa_encrypt(string message, pair<int, int> key) {
    
    srand (time(NULL));
    string cipher;
    int p = key.first;
    int q = key.second;
    // check if p and q are prime

    // compute n and e
    int n = p*q;
    int phi = (p-1)*(q-1);

    int lambda = lcm(p-1,q-1);
    int e;
    vector<int> tot;
    for(int i=3;i<lambda;i++)
    {
        
        if(gcd(i,lambda) == 1){
            tot.push_back(i);
            
        }
    }
    int size = tot.size();
    int ran = rand() % size;
    e = tot[ran];

    cout << "The public key is (n, e): (" << n << ", " << e << ")" << endl;

    int t = make_block(message);
    
    //cipher = modular(message, e, n);

    cout << cipher << endl;


    return cipher;
}

/* END: RSA*/
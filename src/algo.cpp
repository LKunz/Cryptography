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
vector<int> make_block(string text, int size) {
    
    string letterNum;
    string textNum = "";
    vector<int> blocs;
    
    
    for (int i=0; i<text.size(); i++) {
        letterNum = to_string(int(text[i]));
        if (letterNum.size() == 2) {
            letterNum = "0" + letterNum;
        }
        textNum += letterNum;
    }

    for (int i=0;i<textNum.size()/size+1;i++) {
        blocs.push_back(stoi(textNum.substr(size*i, size)));
    }

    cout << textNum << endl;

    return blocs;
}


string make_text(vector<int> blocs, int size) {

    string text = "";
    string textNum = "";
    string letterNum;

    for (int i=0; i<blocs.size(); i++) {

        letterNum = to_string(blocs[i]);
        while (letterNum.size() != size && i==0) {
            letterNum = "0" + letterNum;
        }

        textNum += letterNum;

    }

    cout << textNum << endl;

    for (int i=0; i<textNum.size()/3; i++) {
        text += stoi(textNum.substr(3*i, 3));
    }

    return text;
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

pair<int, int> generate_public_key(int p, int q) {

    // check if p and q are prime
    //...

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

    pair<int, int> key;
    key.first = n;
    key.second = e;

   return key;
}

string rsa_encrypt(string message, int p, int q) {
    
    srand (time(NULL));

    // Generate public key
    pair<int, int> public_key = generate_public_key(p, q);
    int n = public_key.first;
    int e = public_key.second;
    cout << n << "  " << e << endl;
    
    // Make blocs
    vector<int> blocs = make_block(message, 4);

    // Encrypt
    string cipher = "";

    for (int i=0; i<blocs.size(); i++) {
        cipher += to_string(pow(blocs[i], e) % n); // ICIICI
    }

    //string cipher = make_text(t, 4);


    cout << cipher << endl;


    return cipher;
}

/* END: RSA*/
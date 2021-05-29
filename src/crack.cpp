#include <iostream>
#include <string>
#include "crack.hpp"
#include <vector>

using namespace std;
// faire une class avec methods different algo de craquage?
// ou simplement des functions?

// frequency analysis using ASCII printable numbers
vector<double> frequencies(string text, bool normalize, bool afficher)
{
    int const lenAscii(95); // number of ascii printable chars

    vector<double> asciiLetters(lenAscii,0.);

    for (int i=0; i<text.size(); i++) {

        if (normalize) {
            asciiLetters[int(text[i])-32] += 1./text.size();
        } else {
            asciiLetters[int(text[i])-32] += 1.;
        }

    }

    if (afficher) {

        for (int j=0; j<lenAscii; j++) {
            cout << char(j+32) << "  " << asciiLetters[j] << endl;
        }

    }

    return asciiLetters;

}
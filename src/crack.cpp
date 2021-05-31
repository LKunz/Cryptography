#include <iostream>
#include <string>
#include "crack.hpp"
#include <vector>
#include <map>

using namespace std;

Crack::Crack(string message) : m_message(message), m_frequencies()
{

}

Crack::~Crack()
{

}

map<char, double> Crack::getFrequencies() const {
    return m_frequencies;
}

void Crack::frequenciesAnalysis() {

    int const n(95);
    vector<double> asciiLetters(n);

    
    for (int i=0; i<m_message.size(); i++) {
        asciiLetters[int(m_message[i])-32] += 1./m_message.size();
    }

    map<char, double> freq;

    for (int i=0; i<asciiLetters.size(); i++) {
        
        freq.insert(make_pair(char(i+32), asciiLetters[i]));
    }

    m_frequencies = freq;

}
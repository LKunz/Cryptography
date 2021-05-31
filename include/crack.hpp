#include <iostream>

#ifndef CRACK_H_INCLUDED
#define CRACK_H_INCLUDED

#include <string.h>
#include <vector>
#include <map>

class Crack
{
    public:

    Crack(std::string message);
    ~Crack();
    void frequenciesAnalysis();
    std::map<char, double> getFrequencies() const;


    private:

    std::string m_message;
    std::map<char, double> m_frequencies;
};

#endif
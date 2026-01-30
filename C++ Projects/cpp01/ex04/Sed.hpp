#ifndef SED_HPP
#define SED_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

class Sed {
public:
    Sed(std::string filename);
    ~Sed();

    void replace(std::string s1, std::string s2);

private:
    std::string _filename;
};

#endif

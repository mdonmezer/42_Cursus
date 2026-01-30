#include "Sed.hpp"

Sed::Sed(std::string filename) : _filename(filename) {
}

Sed::~Sed() {
}

void Sed::replace(std::string s1, std::string s2) {
    if (this->_filename.empty() || s1.empty()) {
        std::cerr << "Error: Filename and search string cannot be empty." << std::endl;
        return;
    }

    std::ifstream inFile(this->_filename.c_str());
    if (!inFile.is_open()) {
        std::cerr << "Error: Unable to open input file '" << this->_filename << "'." << std::endl;
        return;
    }

    std::string content;
    std::string line;
    while (std::getline(inFile, line)) {
        content += line;
        if (!inFile.eof())
            content += "\n";
    }
    inFile.close();

    std::ofstream outFile((this->_filename + ".replace").c_str());
    if (!outFile.is_open()) {
        std::cerr << "Error: Unable to create output file '" << this->_filename << ".replace'." << std::endl;
        return;
    }

    size_t pos = 0;
    size_t prev = 0;
    while ((pos = content.find(s1, prev)) != std::string::npos) {
        outFile << content.substr(prev, pos - prev);
        outFile << s2;
        prev = pos + s1.length();
    }
    outFile << content.substr(prev);

    outFile.close();
}

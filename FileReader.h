#ifndef FILEREADER_H
#define FILEREADER_H

#include <fstream>
#include <cstring>

class FileReader {
public:
    FileReader(const char* filename);
    ~FileReader();
    bool isOpen();
    char* getNextLine();

private:
    std::ifstream file;
};

#endif

#include <iostream>
#include <fstream>
#include <C:/NEwProject/zlibprog/Project1/zlib-1.3.1/zlib.h>

int main() {
    const char* inputFileName = "input_file.txt";
    const char* outputFileName = "output_file.txt.gz";

    std::ifstream inputFile(inputFileName, std::ios::binary);
    gzFile outputFile = gzopen(outputFileName, "wb");

    if (!inputFile.is_open() || outputFile == nullptr) {
        std::cerr << "Error opening files!" << std::endl;
        return -1;
    }

    char buffer[1024];
    int bytesRead = 0;

    while (inputFile.read(buffer, sizeof(buffer)) || inputFile.gcount()) {
        bytesRead = inputFile.gcount();
        if (gzwrite(outputFile, buffer, bytesRead) == 0) {
            std::cerr << "Error compressing data!" << std::endl;
            return -1;
        }
    }

    inputFile.close();
    gzclose(outputFile);

    std::cout << "File compressed successfully!" << std::endl;

    return 0;
}

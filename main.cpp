#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::getline;
using std::cin;
using std::endl;
using std::cerr;
using std::ifstream;
using std::string;




int main(int argc, char* argv[]) {
    string line;
    ifstream inputFile("data.txt");
    int lines = 0;
    while (getline(inputFile, line)){
        cout << ++lines << "\t" << line << endl;
    }
    inputFile.close();

    return 0;
}
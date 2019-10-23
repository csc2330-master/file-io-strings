#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>

using std::cout;
using std::getline;
using std::cin;
using std::endl;
using std::cerr;
using std::ifstream;
using std::string;
using std::setw;
using std::left;
using std::right;
using std::vector;


// How can we count words?
// How can we count how many "of" inside that file?
// How to add all the different words inside a vector?

bool AddToVector(vector<string>&, const string&);

int main(int argc, char* argv[]) {
    string line, currentWord;
    ifstream inputFile("data.txt");
    int lines = 0, from, words, pos, allWords = 0, ofCount = 0;
    vector<string> myWords;
    while (getline(inputFile, line)){
        words = 1;
        from = 0;
        pos = line.find(" ", from);
        while (pos != string::npos){
            words++;
            currentWord = line.substr(from, pos - from);
            if (AddToVector(myWords, currentWord)){
                cout << currentWord << " Added" << endl;
            }
            from = pos + 1;
            pos = line.find(" ", from);
        }
        currentWord = line.substr(from, line.length() - from);
        if (AddToVector(myWords, currentWord)){
            cout << currentWord << " Added" << endl;
        }
        for (from = 0; (pos = line.find("of", from)) != string::npos ; from = pos + 1) {
            ofCount++;
        }

        allWords += words;
        cout << setw(3) << ++lines << " " << left << setw(55) << line << right << setw(3) << words << endl;
//        for (int i = 0; i < line.length(); ++i) {
//            cout << line[i] << "\t";
//        }
        //cout << endl;
    }
    inputFile.close();
    cout << "Different Words:" << endl;
    for (int i = 0; i < myWords.size(); ++i) {
        cout << myWords.at(i) << endl;
    }
    cout << "File has: " << endl
         << "Lines: " << lines << endl
         << "Words: " << allWords << endl
         << "of appears: " << ofCount << " times" << endl;

    return 0;
}

bool AddToVector(vector<string>& words, const string& word){
    for (int i = 0; i < words.size(); ++i) {
        if (words[i] == word)
            return false;
    }
    words.push_back(word);
    return true;
}
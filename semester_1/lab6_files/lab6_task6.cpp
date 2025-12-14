#include <iostream>
#include <fstream>
#include <string> 
#include <vector>

void checkingIsInputFileEmpty(const std::string& file) {
    std::ifstream in(file);
    if (in.peek() == EOF) {
        std::cout << "File is empty" << std::endl;
        exit(0);
    }
}
void checkingIsInputFileOpened(const std::string& file) {
    std::ifstream in(file);
        if (in.is_open()) {
            std::cout << "File is opened" << std::endl;
        }
        else {
            std::cout << "Can't open the file" << std::endl;
            exit(0);
        }

}
void linesCounter(int &lineCounter , const std::string& file) {
    std::string line;
    std::ifstream in(file);
        while (std::getline(in, line)) {
            ++lineCounter;
    }
}
void findingBiggestUnderLine(std::string line , std::string &biggestUnderline) {
    int firstIndex = 0 , lastIndex = 0 , biggestLastIndex = 0, biggestFirstIndex = 0;
    for (int i = firstIndex; i < line.length(); ++i) {
        firstIndex = lastIndex;
        while (line[firstIndex] == ' ' && firstIndex < line.length()) {
            ++firstIndex;
        }
        lastIndex = firstIndex;
        while (line[lastIndex] != ' ' && lastIndex < line.length()) {
            ++lastIndex;
        }
        if ((lastIndex - firstIndex) > (biggestLastIndex - biggestFirstIndex)) {
            biggestFirstIndex = firstIndex;
            biggestLastIndex = lastIndex;
        }
    }
    biggestUnderline = "";
    for ( int j = biggestFirstIndex; j < biggestLastIndex ; ++j ){
        biggestUnderline  = biggestUnderline + line[j];
    }
}
void findingLineWithBiggestUnderline(int  lineCounter, const std::string& file, int &lineWithBiggestUnderline , std::string &biggestUnderline) {
    std::string curentMax ;
    std::ifstream in(file);
    std::string line;
    int a = 0;
    for (int i = 0; i < lineCounter; ++i) {
        std::getline(in, line);
        curentMax = "";
        findingBiggestUnderLine(line , curentMax);
        if (curentMax.length() > biggestUnderline.length()) {
            biggestUnderline = curentMax;
            lineWithBiggestUnderline = i+1;
        }
    }
}
void findingLinesWithSameBiggestUnderline(const std::string& file , int lineCount , std::string biggestUnderline , std::vector<std::string> &linesWithBiggestUnderlines){
    std::string curentMax = "";
    std::ifstream in(file);
    std::string line;
    for (int i = 0; i < lineCount; ++i) {
        std::getline(in, line);
            findingBiggestUnderLine(line, curentMax);
            if (curentMax.length() == biggestUnderline.length()) {
                linesWithBiggestUnderlines.push_back(line);
            }
    }
}

void outputtingLinesWithBiggestUnderlines(std::vector<std::string>& linesWithBiggestUnderlines) {
    std::cout << "Lines , which includes the longest underlines : " << std::endl;
    for (int i = 0; i < linesWithBiggestUnderlines.size(); ++i) {
        std::cout << linesWithBiggestUnderlines[i] << std::endl;
    }
}

int main()
{
    std::vector<std::string> linesWithBiggestUnderlines;
    std::string line;
    int lineCounter = 0;
    int lineWithBiggestUnderline = 1;
    std::string biggestUnderline ="";
    std::ifstream in("input.txt");
    in.open("input.txt");
    checkingIsInputFileOpened("input.txt");
    checkingIsInputFileEmpty("input.txt");
    linesCounter(lineCounter, "input.txt");
    findingLineWithBiggestUnderline(lineCounter, "input.txt", lineWithBiggestUnderline, biggestUnderline);
    findingLinesWithSameBiggestUnderline("input.txt", lineCounter, biggestUnderline, linesWithBiggestUnderlines);
    outputtingLinesWithBiggestUnderlines(linesWithBiggestUnderlines);
    in.close();
    std::cout << "File is closed , task completed" << std::endl;

}

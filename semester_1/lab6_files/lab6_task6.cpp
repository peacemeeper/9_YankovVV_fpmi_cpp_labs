#include <iostream>
#include <fstream>
#include <string> 
 
int main()
{   
    int lineCount = 1 , maxLineNumber = 0 , maxLineLength = 0;
    std::string line;
    std::ifstream in("hello.txt"); 
    while(std::getline(in,line)){
        if(maxLineLength < line.length()){
            maxLineLength = line.length();
            maxLineNumber = lineCount;
        }
        lineCount++;
    } 
    std::cout<<maxLineNumber<<std::endl;
    std::cout<<maxLineLength<<std::endl;
    std::cout<<lineCount<<std::endl;
    
}

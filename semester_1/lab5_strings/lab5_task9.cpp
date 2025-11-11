
#include <iostream>
#include <iostream>
#include <cctype>

int main() {
    std::string text;
    std::cout<<"Введите строку: ";
    getline(std::cin, text);
    for ( int i = 0; i < text.length() ; ++i){
        if(std::isalpha(text[i])){
            text[i] = std::toupper(text[i]);
        }
        if(text[i] == ' '){
            text[i] = '+';
        }
    }
    std::cout<<text;
    return 0;
}

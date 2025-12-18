#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cctype>

void enteringString(std::string& text) {
    std::cout << "Введите строку: ";
    getline(std::cin, text);
}

void isContainOnlySpaces(std::string text) {
    int index = 0;
    while (text[index] == ' ') {
        ++index;
    }
    if (index == text.length()) {
        std::cout << "Your string contain only spaces" << std::endl;
        exit(0);
    }
}

void isEmpty(std::string text) {
    if (text.empty()) {
        std::cout << "Your string is empty" << std::endl;
        exit(0);
    }
}

void changingString(std::string& text, std::vector<std::string> words) {
    int lastIndex = 0;
    int firstIndex = 0;
    int  i = 0;

    while (lastIndex < text.length() && firstIndex < text.length()) {
        firstIndex = lastIndex;
        while (text[firstIndex] == ' ' && firstIndex < text.length()) {
            ++firstIndex;
        }
        lastIndex = firstIndex;
        while (text[lastIndex] != ' ' && lastIndex < text.length()) {
            ++lastIndex;
        }
        if (firstIndex < text.length() && i < words.size()) {
            text.replace(firstIndex, (lastIndex - firstIndex), words[i]);
            lastIndex = firstIndex + words[i].length();
            ++i;
        }
    }
}

void findingWords(std::string text, std::vector<std::string>& words) {
    int lastIndex = 0;
    int firstIndex = 0;
    while (lastIndex < text.length() && firstIndex < text.length()) {
        firstIndex = lastIndex;
        while (text[firstIndex] == ' ' && firstIndex < text.length()) {
            ++firstIndex;
        }
        lastIndex = firstIndex;
        while (text[lastIndex] != ' ' && lastIndex < text.length()) {
            ++lastIndex;
        }
        if (firstIndex < lastIndex) {
            words.push_back(text.substr(firstIndex, (lastIndex - firstIndex)));
        }
    }
}

void changingLatinToUpper(std::string& text) {
    for (int i = 0; i < text.length(); ++i) {
        if (std::isalpha(text[i])) {
            text[i] = std::toupper(text[i]);
        }
    }
}

void changingSpacesToPluses(std::string& text) {
    for (int i = 0; i < text.length(); ++i) {
        if (text[i] == ' ') {
            text[i] = '+';
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::vector<std::string> words;
    std::string text;
    enteringString(text);
    isEmpty(text);
    isContainOnlySpaces(text);
    findingWords(text, words);
    std::sort(words.rbegin(), words.rend());
    changingString(text, words);
    changingLatinToUpper(text);
    changingSpacesToPluses(text);
    std::cout << text;
    return 0;
}

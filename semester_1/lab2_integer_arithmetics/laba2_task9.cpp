#include <iostream>

bool isPalindrome(int number) {
    if (number < 10) {
        return false;
    }

    int original = number;
    int reversed = 0;

    while (number > 0) {
        int digit = number % 10;
        reversed = reversed * 10 + digit;
        number = number / 10;
    }

    return original == reversed;
}

int main() {
    setlocale(LC_ALL,"Russian");
    int a, b, l, a1, reversed, ost;
    std::cout << "Введите целое натуральное число a, с которого начинается множество чисел"<< std::endl;
    if (!(std::cin >> a)) {
        std::cout << "Неверный симовл"<< std::endl;
        return 0;
    }
    std::cout << "Введите целое натуральное число b, с которого начинается множество чисел"<< std::endl;
    if (!(std::cin >> b)) {
        std::cout << "Неверный символ" << std::endl;
        return 0;
    }
    if (a > b) {
        std::cout << "Число а должно быть больше числа b" << std::endl;
    }
    for ( int i = a ; i <= b ;  ++i ) {
            if(isPalindrome(i)){
                    std::cout<<i<<std::endl;
            }

    return 0;
}

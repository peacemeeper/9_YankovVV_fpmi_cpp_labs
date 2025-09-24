#include <iostream>

int main() {
    setlocale(LC_ALL, "Russian");
    int a, b, l, a1, reversed, ost;
    std::cout << "Введите целое натуральное число a, с которого начинается "
                 "множество чисел"
              << std::endl;
    if (!(std::cin >> a)) {
        std::cout << "Неверный симовл" << std::endl;
        return 0;
    }
    std::cout << "Введите целое натуральное число b, с которого начинается "
                 "множество чисел"
              << std::endl;
    if (!(std::cin >> b)) {
        std::cout << "Неверный символ" << std::endl;
        return 0;
    }
    if (a > b) {
        std::cout << "Число а должно быть больше числа b" << std::endl;
    }
    while (a <= b) {
        reversed = 0; // Перевернутое число
        ost = 0;      // Остаток от деления на 10
        a1 = a;       // Повторение числа а
        while (a1 > 0) {
            ost = a1 % 10;
            a1 = a1 / 10;
            reversed = reversed * 10 + ost;
            if (reversed == a && reversed > 10) {
                std::cout << a << std::endl;
            }
        }
        a++;
    }
    return 0;
}

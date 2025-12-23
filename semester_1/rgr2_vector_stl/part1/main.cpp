#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

void inputVector(std::vector<int>& vector) {
    std::cout << "Вводите целые числа в промежутке от -2147483648 до 2147483647" << std::endl;
    std::cout << "Если хотите остановить ввод чисел, то просто введите любой символ кроме пробела и числа" << std::endl;
    std::cout << "Также для остановки цикла можно ввести число, которое не входит в промежуток, указанный в первой строке" << std::endl;
    std::cout << "Ввод: ";
    int num;
    while (std::cin >> num) {
        vector.push_back(num);
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void outputVector(const std::vector<int>& vector) {
    std::cout << "Полученный вектор: ";
    for (size_t i = 0; i < vector.size(); ++i) {
        std::cout << vector[i] << " ";
    }
    std::cout << std::endl;
}

void sizeOfVector(const std::vector<int>& vector) {
    std::cout << "Размер вашего вектора: " << vector.size() << std::endl;
}

void isBiggerThan(const std::vector<int>& vector) {
    int digit;
    std::cout << "Введите число, больше которого должны быть элементы вектора: ";
    std::cin >> digit;
    std::cout << "Элементы вектора, большие заданного: ";
    for (size_t i = 0; i < vector.size(); ++i) {
        if (vector[i] > digit) {
            std::cout << vector[i] << " ";
        }
    }
    std::cout << std::endl;
}

void averageValueInVector(std::vector<int> vector, int& average) {
    int sum = 0;
    for (int i = 0; i < vector.size(); ++i) {
        sum += vector[i];
    }
    average = sum / vector.size();
}

void changingZeroesOnAverage(std::vector<int>& vector, int average) {
    for (size_t i = 0; i < vector.size(); ++i) {
        if (vector[i] == 0) {
            vector[i] = average;
        }
    }
}

void givingInterval(int& numberFirstElement, int& numberLastElement) {
    std::cout << "Введите номер элемента вектора , с которого начентся промежуток суммирования (Натуральное число) : ";
    if (!(std::cin >> numberFirstElement)) {
        std::cout << "Введите коррекнтнок число" << std::endl;
        exit(0);
    }
    std::cout << "Введите номер элемента вектора , которым закончется промежуток суммирования (Натуральное число) : ";
    if (!(std::cin >> numberLastElement)) {
        std::cout << "Введите коррекнтнок число" << std::endl;
        exit(0);
    }
}

int findingMin(const std::vector<int>& vector) {
    if (vector.empty()) return 0;

    int min = vector[0];
    for (size_t i = 1; i < vector.size(); ++i) {
        if (vector[i] < min) {
            min = vector[i];
        }
    }
    return min;
}

int findingMax(const std::vector<int>& vector) {
    if (vector.empty()) return 0;

    int max = vector[0];
    for (size_t i = 1; i < vector.size(); ++i) {
        if (vector[i] > max) {
            max = vector[i];
        }
    }
    return max;
}

void addingSumFromIntervalToEachElement(std::vector<int>& vector) {
    int numberFirstElement = 0;
    int numberLastElement = 0;

    givingInterval(numberFirstElement, numberLastElement);

    if (numberFirstElement < 0) {
        std::cout << "Первый элемент промежутка не может быть меньше нуля" << std::endl;
    }
    if (numberFirstElement > numberLastElement) {
        std::cout << "Номер последнего элемента промежутка не может быть меньше первого" << std::endl;
    }
    if (numberLastElement > vector.size()) {
        std::cout << "Номер последнего элемента промежутка не может быть больше размера самого вектора" << std::endl;
    }
    int sum = 0;
    for (int i = numberFirstElement; i <= numberLastElement; ++i) {
        sum += vector[i];
    }
    for (int j = 0; j < vector.size(); ++j) {
        vector[j] = vector[j] + sum;
    }
}

void changingModuledEven(std::vector<int>& vector) {
    if (vector.empty()) return;

    int max = findingMax(vector);
    int min = findingMin(vector);

    for (size_t i = 0; i < vector.size(); ++i) {
        if (vector[i] % 2 == 0) {
            vector[i] = (max - min);
        }
    }
}

void deleteSameNumbers(std::vector<int>& vector) {
    for (size_t i = 0; i < vector.size(); ++i) {
        for (size_t j = i + 1; j < vector.size();) {
            if (vector[j] == vector[i]) {
                vector.erase(vector.begin() + j);
            }
            else {
                ++j;
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int average = 0;
    std::vector<int> bem;
    inputVector(bem);

    if (bem.empty()) {
        std::cout << "Вектор пуст!" << std::endl;
        return 0;
    }

    outputVector(bem);
    sizeOfVector(bem);
    isBiggerThan(bem);
    averageValueInVector(bem, average);
    std::cout << "Среднее значение вектора: " << average << std::endl;

    changingZeroesOnAverage(bem, average);
    std::cout<<"Вектор после замены всех нулей на среднее арифметическое элементов вектора"<<std::endl;
    outputVector(bem);

    addingSumFromIntervalToEachElement(bem);
    std::cout << "Вектор после добавляения суммы чисел из интервала к каждому элементу" << std::endl;
    outputVector(bem);

    changingModuledEven(bem);
    std::cout << "Вектор после замена всех четных по модулю элементов вектора на разность максимального и минимального элементов" << std::endl;
    outputVector(bem);

    deleteSameNumbers(bem);
    std::cout << "Вектор после удаления всех одинаковых элементов , кроме первого" << std::endl;
    outputVector(bem);

    return 0;
}

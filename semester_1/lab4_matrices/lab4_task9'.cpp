#include <iostream>
#include <random>

void checkingChoose(int choose) {
    if (choose != 1 && choose != 2) {
        std::cout << "Для продолжения нужно ввести 1 либо 2" << std::endl;
        exit(0);
    }
}

void inputingBordersForRandomNumbers(double& firstNumber, double& lastNumber) {
    std::cout << "Введите целое число, с которого будет начинаться генерация рандомных чисел " << std::endl;
    if (!(std::cin >> firstNumber)) {
        std::cout << "Введите корректное значение" << std::endl;
        exit(0);
    }
    std::cout << "Введите целое число, которым будет заканчиваться генерация рандомных чисел " << std::endl;
    if (!(std::cin >> lastNumber)) {
        std::cout << "Введите корректное значение" << std::endl;
        exit(0);
    }
    if (firstNumber > lastNumber) {
        std::cout << "Число, с которого начинается генерация , должно быть больше , чем число , которым заканчивается генерация" << std::endl;
        exit(0);
    }
}

void inputCharacteristicsOfColumns(int& columns, int& lines) {
    std::cout << "Введите количество столбцов матрицы (Натуральное число):" << std::endl;
    if (!(std::cin >> columns) || columns <= 0) {
        std::cout << "Введите корректное значение" << std::endl;
        exit(0);
    }
    std::cout << "Введите количество строк матрицы (Натуральное число):" << std::endl;
    if (!(std::cin >> lines) || lines <= 0) {
        std::cout << "Введите корректное значение" << std::endl;
        exit(0);
    }
}

void makingChoose(int& choose) {
    std::cout << "Если хотите вводить элементы массива самостоятельное , то введите 1 . Если же хотите использовать случайные числа , то введиите 2" << std::endl;
    if (!(std::cin >> choose)) {
        std::cout << "Для продолжения нужно ввести либо 1 , либо 2" << std::endl;
        exit(0);
    }
}

void inputingMatrixByHand(int** array, int lines, int columns) {
    std::cout << "Введите матрицу" << std::endl;
    for (int i = 0; i < lines; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (!(std::cin >> array[i][j])) {
                std::cout << "Введите корректное значение" << std::endl;
                exit(0);
            }
        }
    }
}

void outputingMatrix(int** array, int lines, int columns) {
    for (int i = 0; i < lines; ++i) {
        for (int j = 0; j < columns; ++j) {
            std::cout << array[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

void findingAmountOfColumnsWithZero(int columns, int lines, int& columnsWithZero, int** array) {
    for (int i = 0; i < columns; ++i) {
        bool hasZero = false;
        for (int j = 0; j < lines; ++j) {
            if (array[j][i] == 0) {
                hasZero = true;
                break; 
            }
        }
        if (hasZero) {
            columnsWithZero++;
        }
    }
}

void findingLongestMostGettingBiggerLine(int lines, int columns, int** array, int& maxLength, int& beforeMaxLength, int& maxLine) {
    int currentMaxLine = 0;
    beforeMaxLength = 0;
    maxLength = 0;

    for (int i = 0; i < lines; ++i) {
        int length = 1;
        int currentMax = 1;

        for (int j = 0; j < columns - 1; ++j) {
            if (array[i][j] < array[i][j + 1]) {
                length++;
                if (length > currentMax) {
                    currentMax = length;
                }
            }
            else {
                length = 1;
            }
        }

        if (currentMax > maxLength) {
            maxLength = currentMax;
            currentMaxLine = i;
        }
    }
    maxLine = currentMaxLine;
}

void fillingMatrixWithRandomDigits(int firstNumber, int lastNumber, int lines, int columns, int** array) {
    std::mt19937 gen(45218965);
    std::uniform_int_distribution<int> dist(static_cast<int>(firstNumber), static_cast<int>(lastNumber));
    for (int i = 0; i < lines; ++i) {
        for (int j = 0; j < columns; ++j) {
            array[i][j] = dist(gen);
        }
    }
}

void outputingNumberOfColumnsWithoutZero(int columns, int columnsWithZero) {
    std::cout << (columns - columnsWithZero) << " столбцов не содержат 0" << std::endl;
}

void outputingLongestMostGettingBigger(int maxLine) {
    std::cout << "Номер строки с самой длиной строго возрастающей последовательностью: " << maxLine + 1 << std::endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int columns, lines, columnsWithZero, maxLength, maxLine, beforeMaxLength, choose;
    maxLine = 0;
    maxLength = 1;
    columnsWithZero = 0;

    inputCharacteristicsOfColumns(columns, lines);
    makingChoose(choose);

    int** array = new int* [lines];
    for (int i = 0; i < lines; ++i) {
        array[i] = new int[columns];
    }

    if (choose == 1) {
        inputingMatrixByHand(array, lines, columns);
        outputingMatrix(array, lines, columns);
    }
    else if (choose == 2) {
        double lastNumber, firstNumber; 
        inputingBordersForRandomNumbers(firstNumber, lastNumber);
        fillingMatrixWithRandomDigits(firstNumber, lastNumber, lines, columns, array);
        outputingMatrix(array, lines, columns);
    }

    checkingChoose(choose);

    findingAmountOfColumnsWithZero(columns, lines, columnsWithZero, array);
    findingLongestMostGettingBiggerLine(lines, columns, array, maxLength, beforeMaxLength, maxLine);

    outputingNumberOfColumnsWithoutZero(columns, columnsWithZero);
    outputingLongestMostGettingBigger(maxLine);

    for (int i = 0; i < lines; ++i) {
        delete[] array[i];
    }
    delete[] array;

    return 0;
}

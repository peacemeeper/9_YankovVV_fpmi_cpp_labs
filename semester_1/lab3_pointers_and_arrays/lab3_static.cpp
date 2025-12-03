#include <cstdlib>
#include <iostream>
#include <random>

void checkingOnEmpty(n){
 if ( n == 0 ) {
     std::cout<<"Массив пуст"<<std::endl;
     exit(0);
 }
}
void checkingChoose(int choose) {
    if (choose != 1 && choose != 2) {
        std::cout << "Для продолжения нужно ввести 1 либо 2" << std::endl;
        exit(0);
    }
}

void outputingBiggestNumber(int max) { std::cout << "Номер максимального по модулю элемента массива : " << max << std::endl; }

void outputingArray(double array[], int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void countOfDigitsInArray(int& n) {
    std::cout << "Введите количество элементов в массиве (Натуральное число)" << std::endl;
    if (!(std::cin >> n)) {
        std::cout << "Введите коректное значение ( Натуральное число )" << std::endl;
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

void fillingArray(double array[], int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << "Введите " << (i + 1) << " элемент массива" << std::endl;
        if (!(std::cin >> array[i])) {
            std::cout << "Введите коректное значение ( Вещественное число )" << std::endl;
            exit(0);
        }
    }
}

void findingBiggestNumber(double array[], int n, int& max) {
    int maxDigit = 0;
    max = 1;
    for (int i = 1; i < n; i++) {
        if (array[i] > maxDigit) {
            maxDigit = array[i];
        }
    }
    int a = 0;
    while (array[a] < maxDigit) {
        a++;
        max++;
    }
}

void sumOfDigitsAfterFirstDigitBiigerThenZero(double array[], int n, double& sum) {
    int index = 0;
    while (array[index] <= 0 && index<n) {
        index++;
    }
    if (index == n && array[index]==0 ) {
        std::cout << "Подходящее число стоит последним" << std::endl;
    }
    if (index == n && array[index] != 0) {
        std::cout << "В массиве нет положительных чисел" << std::endl;
    }
    while ( index < n) {
        sum = sum + array[index];
        index++;
    }
}

void outputingSumOfDigitsAfterFirstDigitBiigerThenZero(double sum) {
    std::cout << "Сумма всех чисел после первого моложительного числа :" << sum << std::endl;
}

void changingArray(double array[], int n) {
    int insertPos = 0;
    for (int i = 0; i < n; i++) {
        if (array[i] >= 0 && array[i] <= 10) {
            int temp = array[i];
            array[i] = array[insertPos];
            array[insertPos] = temp;
            insertPos++;
        }
    }
}
void outputingChangedArray(double array[], int n) {
    std::cout << "Остортированный массив: ";
    outputingArray(array, n);
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

void fillingArrayWithRandomDigits(double firstNumber, double lastNumber, int n, double array[]) {
    std::mt19937 gen(45218965);
    std::uniform_int_distribution<int> dist(firstNumber, lastNumber);
    for (int i = 0; i < n; ++i) {
        array[i] = dist(gen);
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int n , max, choose;
    const int size = 1000;
    double sum = 0;
    double array[size];
    countOfDigitsInArray(n);
    makingChoose(choose);
    if (choose == 1) {
        fillingArray(array, n);
        std::cout << "Ваш массив: ";
        outputingArray(array, n);
        findingBiggestNumber(array, n, max);
        sumOfDigitsAfterFirstDigitBiigerThenZero(array, n, sum);
        changingArray(array, n);
    }
    if (choose == 2) {
        double lastNumber, firstNumber;
        inputingBordersForRandomNumbers(firstNumber, lastNumber);
        fillingArrayWithRandomDigits(firstNumber, lastNumber, n, array);
        std::cout << "Ваш массив: ";
        outputingArray(array, n);
        findingBiggestNumber(array, n, max);
        sumOfDigitsAfterFirstDigitBiigerThenZero(array, n, sum);
        changingArray(array, n);
    }
    checkingChoose(choose);
    outputingChangedArray(array, n);
    outputingBiggestNumber(max);
    outputingSumOfDigitsAfterFirstDigitBiigerThenZero(sum);
    return 0;
}

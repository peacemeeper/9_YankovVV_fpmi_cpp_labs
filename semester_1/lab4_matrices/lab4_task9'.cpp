#include <iostream>

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
  if (!(std::cin >> columns)) {
    std::cout << "Введите корректное значение" << std::endl;
    exit(0);
  }
  std::cout << "Введите количество строк матрицы (Натуральное число):" << std::endl;
  if (!(std::cin >> lines)) {
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
void inputingMatrixByHand(int array[][], int lines, int columns) {
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
void outputingMatrix(int array[][], int lines, int columns) {
  for (int i = 0; i < lines; ++i) {
    for (int j = 0; j < columns; ++j) {
      std::cout << array[i][j] << "\t";
    }
    std::cout << std::endl;
  }
}
void findingAmountOfColumnsWithZero(int columns, int lines, int& columnsWithZero, int array[][]) {
  for (int i = 0; i < columns; ++i) {
    for (int j = 0; j < lines; ++j) {
      if (array[j][i] == 0) {
        columnsWithZero++;
        i++;
      } else if (j == lines) {
        i++;
      }
    }
  }
}
void findingLongestMostGettingBiggerLine(int linesd, int columns, int array[][], int maxLength, int beforeMaxLength, int& maxLine) {
  for (int i = 0; i <= lines; ++i) {
    if (maxLength > beforeMaxLength) {
      maxLine++;
    }
    beforeMaxLength = maxLength;
    maxLength = 1;
    length = 1;
    for (int j = 0; j < columns; ++j) {
      if (array[i][j] < array[i][j + 1]) {
        length++;
      }
      if (array[i][j] >= array[i][j + 1]) {
        if (length > maxLength) {
          maxLength = length;
          length = 1;
        }
      }
    }
  }
}

void fillingMatrixWithRandomDigits(int firstNumber, int lastNumber, int lines, int cloumns, int array[][]) {
  std::mt19937 gen(45218965);
  std::uniform_int_distribution<int> dist(firstNumber, lastNumber);
  for (int i = 0; i < lines; ++i) {
    for (int j = 0; j < columns; ++j) {
      array[i] = dist(gen);
    }
  }
}

void outputingNumberOfColumnsWithoutZero(int columns, int columnsWithZero) { std::cout << (columns - columnsWithZero) << " столбцов не содержат 0" << std::endl; }

void outputingLongestMostGettingBigger(int maxLine) { std::cout << "Номер строки с самой длиной строго возрастающей последовательностью" << maxLine << std::endl; }

int main() {
  int columns, lines, zeroCount, columnsWithZero, maxLength, length, maxLine, beforeMaxLength, choose;
  maxLine = 0;
  maxLength = 1;
  zeroCount = 1;
  columnsWithZero = 0;
  inputCharacteristicsOfColumns(columns, lines);
  makingChoose(choose);
  int array[lines][columns];
  if (choose == 1) {
    inputingMatrixByHand(array, lines, columns);
    outputingMatrix(array, lines, columns);
  }
  if (choose == 2) {
    int lastNumber, firstNumber;
    inputingBordersForRandomNumbers(firstNumber, lastNumber);
    fillingMatrixWithRandomDigits(firstNumber, lastNumber, lines, cloumns, array[][]);
    outputingMatrix(array, lines, columns);
    outputingMatrix(array, lines, columns);
  }
  findingAmountOfColumnsWithZero(columns, lines, columnsWithZero, array);
  findingLongestMostGettingBiggerLine(lines, columns, array, maxLength, beforeMaxLength, maxLine);
  checkingChoose(choose);
  outputingAmountOfColumnsWithoutZero(columns, columnsWithZero);
  outputingLongestMostGettingBigger(maxLine);
  return 0;
}

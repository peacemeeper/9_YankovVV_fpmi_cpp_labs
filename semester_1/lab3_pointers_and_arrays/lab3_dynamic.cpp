#include <iostream>

#include <random>

void checkingChoose(int choose) {
  if (choose != 1 && choose != 2) {
    std::cout << "Для продолжения нужно ввести 1 либо 2" << std::endl;
    exit(0);
  }
}

void swap(double& a , double& b ){
    int t = 0;
    t = a; 
    a = b; 
    b = t;
}
void sortEvenAndOdd(int n , double * array){
    for (int i = 0; i < n; i += 2) {
        for (int j = i + 2; j < n; j += 2) {
            if (array[i] > array[j]) {
                swap(array[i], array[j]);
            }
        }
    }
    
    for (int i = 1; i < n; i += 2) {
        for (int j = i + 2; j < n; j += 2) {
            if (array[i] > array[j]) {
                swap(array[i], array[j]);
            }
        }
    }
}
void outputingArray(double * array, int n) {
  std::cout<<"Ваш массив : ";
  for (int i = 0; i < n; ++i) {
    std::cout << array[i] << " ";
  }
  std::cout << std::endl;
}

void numberOfFirstZero(double * array , int& a) {
     while (array[a] != 0) {
      a++;
    }
}

void numberOfLastZero(double * array , int& n) {
     while (array[n] != 0) {
      n--;
    }
}

void sumBetweenZeroes(int a , int n , double & sum , double * array){
    while ( a < n ) {
        sum = sum + array[a];
        a++;
    }
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
void fillingArray(double * array, int n) {
  for (int i = 0; i < n; ++i) {
    std::cout << "Введите " << (i + 1) << " элемент массива" << std::endl;
    if (!(std::cin >> array[i])) {
      std::cout << "Введите коректное значение ( Вещественное число )" << std::endl;
      exit(0);
    }
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
void fillingArrayWithRandomDigits(double firstNumber, double lastNumber, int n, double * array) {
  std::mt19937 gen(45218965);
  std::uniform_int_distribution<int> dist( firstNumber, lastNumber);
  for (int i = 0; i < n; ++i) {
    array[i] = dist(gen);
  }
}
void outputingSumBetweenZeros(double sum){
    std::cout<<"Сумма чисел между первым и последним нулями: "<<sum<<std::endl;
}

int main() {
  int a , n, choose;
  a = 0;
  double sum = 0;
  countOfDigitsInArray(n);
  double * array = new double[n];
  makingChoose(choose);
  if (choose == 1) {
    fillingArray(array , n);
    sortEvenAndOdd(n , array);
    outputingArray(array, n);
    numberOfFirstZero(array, a);
    numberOfLastZero(array , n );
    sumBetweenZeroes(a , n , sum , array);
    delete[] array;
  }
  if (choose == 2) {
     double firstNumber,lastNumber;
inputingBordersForRandomNumbers( firstNumber,  lastNumber);
    fillingArrayWithRandomDigits( firstNumber,  lastNumber,  n,  array);
    sortEvenAndOdd(n , array);
    outputingArray(array,  n);
    numberOfFirstZero(array, a);
    numberOfLastZero(array , n );
    sumBetweenZeroes(a , n , sum , array);
    delete[] array;
  }
  checkingChoose(choose);
  
    outputingSumBetweenZeros( sum);
      return 0;
    }
      


#include <iostream>
#include <random>

void checkingSize(int n ) {
if ( n < 0 ){
 std::cout<<"Количество элементов не может быть меньше 0"<<std::endl;
 exit(0);
 }
}
void checkingOnEmpty(int n){
 if ( n == 0 ) {
     std::cout<<"Массив пуст"<<std::endl;
     exit(0);
 }
}

void findLongestUnique(const double* array, int n) {
    
    int start = 0;
    int end = 0;  
    int maxLength = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = start; j < i; j++) {
            if (array[j] == array[i]) {
                if (i - start > maxLength) {
                    maxLength = i - start;
                    end = i - 1;
                }
                start = j + 1; 
                break;
            }
        }
    }
    
    if (n - start > maxLength) {
        maxLength = n - start;
        end = n - 1;
    }
    std::cout << "Цепочка: "<<std::endl;
    for (int i = end - maxLength + 1; i <= end; i++) {
        std::cout << array[i] << " ";
    }
}


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

void outputingChangedArray(double * array, int n) {
  std::cout<<"Ваш отсортированный массив : ";
  for (int i = 0; i < n; ++i) {
    std::cout << array[i] << " ";
  }
  std::cout << std::endl;
}

void sumBetweenZeroes(int a , int n , double & sum , double * array){
    while (array[a] != 0 && a < n) {
      a++;
    }
    while (array[n] != 0 && n > 0) {
      n--;
    }
    if ( a == n){
        std::cout<<"В данном ряду только один ноль"<<std::endl;
    }
    if ( n == 0 && a!=0 ){
        std::cout<<"В данном ряду нет нулей"<<std::endl;
    }
    if ( n == a+1 ){
        std::cout<<"В ряду 2 нуля , но они стоят рядом"<<std::endl;
    }
    while ( a < n ) {
        sum = sum + array[a];
        a++;
    }
}
void cleaningSum(double& sum){
    sum = 0;
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
void outputingSumBetweenZerosInChangedArray(double sum){
    std::cout<<"Сумма чисел между первым и последним нулями в отсортированном массиве: "<<sum<<std::endl;
}
void outputingSumBetweenZerosInStartArray(double sum){
    std::cout<<"Сумма чисел между первым и последним нулями в вашем массиве: "<<sum<<std::endl;
}

int main() {
  int a , n , choose;
  a = 0;
  double sum = 0;
  countOfDigitsInArray(n);
  checkingSize(n);
  checkingOnEmpty(n);
 
  double * array = new double[n];
  makingChoose(choose);
  if (choose == 1) {
    fillingArray(array , n);
    outputingArray(array , n);
    findLongestUnique(array , n);
    sumBetweenZeroes(a , n , sum , array);
    outputingSumBetweenZerosInStartArray(sum);
    cleaningSum(sum);
    sortEvenAndOdd(n , array);
    outputingChangedArray(array, n);
    sumBetweenZeroes(a , n , sum , array);
    delete[] array;
  }
  if (choose == 2) {
     double firstNumber,lastNumber;
    inputingBordersForRandomNumbers(firstNumber,  lastNumber);
    fillingArrayWithRandomDigits(firstNumber,  lastNumber,  n,  array);
    outputingArray(array , n);
    findLongestUnique(array,n);
    sumBetweenZeroes(a , n , sum , array);
    outputingSumBetweenZerosInStartArray(sum);
    cleaningSum(sum);
    sortEvenAndOdd(n , array);
    outputingChangedArray(array,  n);
    sumBetweenZeroes(a , n , sum , array);
    delete[] array;
  }
  checkingChoose(choose);
  
    outputingSumBetweenZerosInChangedArray(sum);
      return 0;
    }
      

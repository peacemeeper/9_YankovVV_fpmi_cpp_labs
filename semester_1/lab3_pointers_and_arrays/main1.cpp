#include <iostream>

#include <random>

void numberOfFirsZero(int array[] , int& a) {
     while (array[a] != 0) {
      a++;
    }
}

void numberOfSecondZero(int array[] , int& n) {
     while (array[n] != 0) {
      n--;
    }
}

void sumBetweenZeroes(int a , int n , int& sum , int array[]){
    while ( a < n ) {
        sum = sum + array[a];
        a++;
    }
}

int bubleSort(int array[],int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < ( n-1 ); j++) {
      if (array[j] > array[j + 1]) {
        int b = array[j];
        array[j] = array[j + 1];
        array[j + 1] = b;
      }
    }
  }

  std::cout << "Массив в отсортированном виде: ";

  for (int i = 0; i < 10; i++) {
    std::cout << array[i] << " ";
  }
  return 0;
}

int main() {
  int a, n, choose, sum;
  sum = 0;
  a = 0;
  std::cout << "Введите количество элементов в массиве (Целое натуральное число)" << std::endl;
  if (!(std::cin >> n)) {
    std::cout << "Введите корректное значение" << std::endl;
    return 0;
  }
  int * array = new int[n];
  std::cout << "Если хотите вводить элементы массива самостоятельное , то введите 1 . Если же хотите использовать случайные числа , то введиите 2" << std::endl;
  if (!(std::cin >> choose)) {
    std::cout << "Введите корректное значение" << std::endl;
    return 0;
  }
  if (choose == 1) {
    std::cout << "Введите элементы массива: ";
    for (int i = 0; i < n; i++) {
      std::cin >> array[i];
    }
    bubleSort(array , n);
    numberOfFirsZero(array, a);
    numberOfSecondZero(array , n );
    sumBetweenZeroes(a , n , sum , array);
    delete[] array;
  }
  if (choose == 2) {
     int firstNumber,lastNumber;
    std::cout<<"Введите целое число, с которого будет начинаться генерация рандомных чисел "<<std::endl;
    if (!(std::cin >> firstNumber)) {
        std::cout << "Введите корректное значение" << std::endl;
        return 0;
    }
    std::cout<<"Введите целое число, которым будет заканчиваться генерация рандомных чисел "<<std::endl;
    if (!(std::cin >> lastNumber)) {
        std::cout << "Введите корректное значение" << std::endl;
        return 0;
    }
    if ( firstNumber > lastNumber ){
        std::cout<<"Число, с которого начинается генерация , должно быть больше , чем число , которым заканчивается генерация"<<std::endl;
        return 0;
    }
    std::mt19937 gen(45218965);
    std::uniform_int_distribution<int> dist(firstNumber,lastNumber);
    std::cout<<"Элементы массива:"<<std::endl;
    for ( int i = 0; i < n ; ++i){
        array[i] = dist(gen);
        std::cout<<array[i]<<" ";
    }
    std::cout<<std::endl;
    
    bubleSort(array , n);
    numberOfFirsZero(array, a);
    numberOfSecondZero(array , n );
    sumBetweenZeroes(a , n , sum , array);
    delete[] array;
  }
    for(int i = 0 ; i < n ; ++i){
        std::cout<<array[i]<<std::endl;
    }
      std::cout<<"Сумма чисел между первым и последним нулями:"<<sum<<std::endl;
  return 0;
}

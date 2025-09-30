#include <iostream>
#include <cstdlib>
#include <random>

int main() {
    setlocale(LC_ALL, "Russian");
    int a, b, n, max, sum, num, numberOfNegativeNumbers,choose;
    a = 0;
    max = 1;
    sum = 0;
    std::cout << "Введите количество элементов в массиве (Натуральное число)"<< std::endl;
    if (!(std::cin >> n)) {
        std::cout << "Введите корректное значение" << std::endl;
        return 0;
    }
    int array[n];
    std::cout<<"Если хотите вводить элементы массива самостоятельное , то введите 1 . Если же хотите использовать случайные числа , то введиите 2"<<std::endl;
    std::cin>>choose;
    if (choose ==  1){
    while (a < n) {
        std::cout << "Введите " << (a + 1) << " элемент массива" << std::endl;
        if (!(std::cin >> array[a])) {
        std::cout << "Введите корректное значение" << std::endl;
        return 0;
        }
        if (array[a] * array[a] > array[a - 1] * array[a - 1]) {
            max++;
        }
        a++;
    }
    a = 0;
    std::cout<<"Числа в промежутке от 0 до 10:"<<std::endl;
     while(a<=n){
         if (array[a]<=10 && array[a]>=0 ){
             b=0;
             b=array[a];
             std::cout<<b<<std::endl;
         }
         a++;
     }
     a=0;
    if (array[a] > 0) {
        while (a < n) {
            sum = sum + array[a];
            a++;
        }
 
    } else if (array[a] < 0) {
        while (array[a] < 0) {
            a++;
        }
        while (a < n) {
            sum = sum + array[a];
            a++;
        }
    }
    std::cout << "Сумма элементов массива, расположенных после первого положительного числа = "<< sum << std::endl;
    std::cout << "Номер максимального по модулю элемента массива = " << max << std::endl;
    return 0;
}
if (choose ==  2){
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
    while (a < n) {
        array[a] = dist(gen);
        std::cout<<array[a]<<std::endl;
        if (array[a] * array[a] > array[a - 1] * array[a - 1]) {
            max++;
        }
        a++;
    }
    a = 0;
    std::cout<<"Числа в промежутке от 0 до 10:"<<std::endl;
     while(a<=n){
         if (array[a]<=10 && array[a]>=0 ){
             b=0;
             b=array[a];
             std::cout<<b<<std::endl;
         }
         a++;
     }
     a=0;
    if (array[a] > 0) {
        while (a < n) {
            sum = sum + array[a];
            a++;
        }
 
    } else if (array[a] < 0) {
        while (array[a] < 0) {
            a++;
        }
        while (a < n) {
            sum = sum + array[a];
            a++;
        }
    }
    std::cout << "Сумма элементов массива,расположенных после первого положительного числа = "<< sum << std::endl;
    std::cout << "Номер максимального по модулю элемента массива = " << max << std::endl;
    return 0;
}
 if ( choose != 1  || choose != 2 ) {
     std::cout<<"Для продолжения нужно ввести 1 либо 2"<<std::endl;
 }
 return 0;
}

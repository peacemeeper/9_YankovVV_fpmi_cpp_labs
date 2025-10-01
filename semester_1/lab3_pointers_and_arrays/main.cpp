
#include <iostream>
#include <random>

int main()
{
    int a,a1,n,maxLength, length, firstNumber,lastNumber,choose;
    maxLength = 1;
    a1=0;
    a=0;
    length=1;
    std::cout<<"Введите количество элементов в массиве (Целое натуральное число)"<<std::endl;
    std::cin>>n;
    int *array = new int[n];
        std::cout<<"Если хотите вводить элементы массива самостоятельное , то введите 1 . Если же хотите использовать случайные числа , то введиите 2"<<std::endl;
    std::cin>>choose;
    if (choose ==  1){
         while (a < n) {
        std::cout << "Введите " << (a + 1) << " элемент массива" << std::endl;
        std::cin>>array[a];
        a++;
         }
    a=0;
    while (a <n ){
        a1=a+1;
        length=1;
            while(array[a]!=array[a1] && a1<n){
            a1++;
            length++;
            }
                if ( length > maxLength ) {
                    maxLength= length;
            }
            a++;
    }
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
        a++;
    }
    a=0;
    while (a <n ){
        a1=a+1;
        length=1;
            while(array[a]!=array[a1] && a1<n){
            a1++;
            length++;
            }
                if (length > maxLength ) {
                    maxLength= length;
            }
            a++;
    }
    }
    std::cout<<"Самая длинная цепочка подряд стоящих различных элементов:"<<maxLength<<std::endl;
    return 0;
    }
 

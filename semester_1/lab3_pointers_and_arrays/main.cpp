
#include <iostream>

int main()
{   setlocale(LC_ALL, "Russian");
    int a,b,n,max,sum,numberOfNegativeNumbers;
    a=0;
    max = 0;
    sum = 0;
    std::cout<<"Введите количество элементов в массиве (Натуральное число)"<<std::endl;
    if(!(std::cin>>n)){
        std::cout<<"Введите корректное значение"<<std::endl;
        return 0;
    }
    int array[n];
    while (a < n) {
        std::cout<<"Введите "<< (a+1)<< " элемент массива"<<std::endl;
        std::cin>>array[a];
        if ( array[a]*array[a] > array[a-1]*array[a-1] ) {
            max++;
        }
        a++;
    } 
    a = 0;
    if (array[a] > 0){
        while ( a < n) {
            sum = sum + array[a];
            a++;
        }
        
    }
    else if ( array[a]<0) {
        while (array[a]<0){
            a++;
        }
        while (a<n){
            sum = sum + array[a];
            a++;
        }
    }
    std::cout<<"Сумма элементов массива,расположенных после первого положительного числа = "<<sum<<std::endl;
    std::cout<<"Номер максимального по модулю элемента массива = "<< max <<std::endl;
    return 0;
}

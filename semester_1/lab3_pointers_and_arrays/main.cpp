
#include <iostream>

int main()
{
    int a,a1,n,maxLength, length;
    maxLength = 1;
    a1=0;
    a=0;
    length=1;
    std::cout<<"Введите количество элементов в массиве (Целое натуральное число)"<<std::endl;
    std::cin>>n;
    int *array = new int[n];
    while (a < n) {
        std::cout << "Введите " << (a + 1) << " элемент массива" << std::endl;
        std::cin>>array[a];
        a++;
    }
    a=0;
    while (a < n){
            a1=a+1;
            length=1;
                while ( a1 < n){
                    if (array[a] != array[a1]){
                        while ( array[a] != array[a1]){
                    }
                length++;
                a1++;
                if ( length > maxLength ) {
                    maxLength= length;
                }
             }
             next:
             a++;
            }
    std::cout<<maxLength<<std::endl;
    std::cout<<a<<std::endl;
    std::cout<<a1<<std::endl;
    return 0;
}
}


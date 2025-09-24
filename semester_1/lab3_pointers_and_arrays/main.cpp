/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

int main()
{   int a,n,max,sum;
    a=0;
    max = 0;
    sum = 0;
    std::cout<<"Введите количество элементов в массиве (Натуральное число)"<<std::endl;
    std::cin>>n;
    int array[n];
    while (a < n) {
        std::cout<<"Введите "<< (a+1)<< " элемент массива"<<std::endl;
        std::cin>>array[a];
        if ( array[a] > max ) {
            max = a ;
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
    std::cout<<sum<<std::endl;
    return 0;
}

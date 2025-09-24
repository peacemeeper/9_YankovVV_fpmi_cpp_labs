#include <iostream>
int main(){
    setlocale(LC_ALL, "Russian");
    long double n1,n2,n3,n4,n5,n6,n7,n8,n9,n10,number;
    number = 0;
    std::cout<<"Введите первое число :";
    std::cin>>n1;
    std::cout<<"Введите второе число :";
    std::cin>>n2;
    std::cout<<"Введите третье число :";
    std::cin>>n3;
    std::cout<<"Введите четвертое число :";
    std::cin>>n4;
    std::cout<<"Введите пятое число :";
    std::cin>>n5;
    std::cout<<"Введите шестое число :";
    std::cin>>n6;
    std::cout<<"Введите седьмое число :";
    std::cin>>n7;
    std::cout<<"Введите восьмое число :";
    std::cin>>n8;
    std::cout<<"Введите девятое число :";
    std::cin>>n9;
    std::cout<<"Введите десятое число :";
    std::cin>>n10;
    if (n1<n2){
        number++;
    }
    if(n2<n1 && n2<n3){
        number++;
    }
    if(n3<n2 && n3<n4){
    number++;
    }
    if(n4<n3 && n4<n5){
        number++;
    }
    if(n5<n4 && n5<n6){
        number++;
    }
    if(n6<n7 && n6<n5){
        number++;
    }
    if(n7<n6 && n7<n8){
        number++;
    }
    if(n8<n7 && n8<n9){
        number++;
    }
    if(n9<n10 && n9<n8){
        number++;
    }
    if(n10<n9){
        number++;
    }
    std::cout<<"Количество чисел, которые меньше своих соседей = "<<number<<std::endl;
	return 0;

}

#include <iostream>

int main() {
setlocale(LC_ALL, "Russian");

	int a;
	std::cout << "Введите шестизначное число" << std::endl;
	std::cin >> a;
	if (a > 99999 and a < 1000000) {
		int b, c, d, e,f,g;
		b = a/100000; 
		c=(a%100000)/10000;
		d=(a%10000)/1000;
		g=(a%1000)/100;
		f=(a%100)/10;
		e=a%10;
		if((c+d+b)==(e+f+g)){
		    std::cout<<"Ваше число является счастливым"<<std::endl;
		}
		else{
		    std::cout<<"Ваше число не является счастливым"<<std::endl;
		}
	} 
	else {
		std::cout << "Это не шестизначное число" << std::endl;
	}
	return 0;
}
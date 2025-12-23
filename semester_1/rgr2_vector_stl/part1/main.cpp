#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

void inputVector(std::vector<int> &vector ) {
	std::cout << "Вводите целые числа в промежутке от -2147483648 до 2147483647" << std::endl;
	std::cout << "Если хотите остановить ввод чисел , то просто введите любой символ кроме пробела и числа" << std::endl;
	std::cout << "Так же для остановки цикла , можно ввести число , которое не входит в промежуток , указанный в первой строке" << std::endl;
	std::cout << "Ввод: ";
	int num;
	while (std::cin >> num) {
		vector.push_back(num);
	}
	std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void outputVector(std::vector<int> vector) {
	std::cout << "Полученный вектор: ";
	for (int i = 0; i < vector.size(); ++i) {
		std::cout << vector[i] << " ";
	}
	std::cout<<std::endl;
}

void sizeOfVector(std::vector<int> vector) {
	std::cout << "Размер вашего вектора : " << vector.size() << std::endl;
}

void findingSameNumbers(std::vector<int> vector, int number) {
	int counter = 0; 
	for (int i = 0; i < vector.size(); ++i) {
		if (vector[i] == number) {
			counter++;
		}
	}
	if (counter == 0) {
		std::cout << "В векторе нет чисел , равных вашему" << std::endl;
	}
	else std::cout << "Количество чисел равных вашему: " << counter << std::endl;
}

void sumOfVector(std::vector<int> vector) {
	int sum = 0 ;
	for (int i = 0; i < vector.size(); ++i) {
		sum += vector[i];
	}
	std::cout << "Сумма чисел в векторе: " << sum << std::endl;
}

void averageValueInVector(std::vector<int> vector , int &average) {
	int sum = 0;
	for (int i = 0; i < vector.size(); ++i) {
		sum += vector[i];
	}
	average = sum / vector.size();
}

void changingZeroesOnAverage(std::vector<int> &vector, int average) {
	for (int i = 0; i < vector.size(); ++i) {
		if (vector[i] == 0){
			vector[i] = average;
		}
	}
}
void givingInterval(int numberLastElement, int numberFirstElement) {
	std::cout << "Введите номер элемента вектора , с которого начентся промежуток суммирования (Натуральное число) : ";
	if (!(std::cin >> numberFirstElement)) {
		std::cout << "Введите коррекнтнок число" << std::endl;
		exit(0);
	}
	std::cout << "Введите номер элемента вектора , которым закончется промежуток суммирования (Натуральное число) : ";
	if (!(std::cin >> numberLastElement)) {
		std::cout << "Введите коррекнтнок число" << std::endl;
		exit(0);
	}
}

int findingMin(std::vector<int> vector , int &min) {
	min = vector[0];
	for (int i = 1; i < vector.size(); ++i) {
		if (vector[i] < min) {
			min = vector[i];
		}
	}
	return min;
}
int findingMax(std::vector<int> vector , int &max) {
	max = vector[0];
	for (int i = 1; i < vector.size(); ++i) {
		if (vector[i] > max) {
			max = vector[i];
		}
	}
	return max;
}


void addingSumFromIntervalToEachElement(std::vector<int>& vector, int numberFirstElement, int numberLastElement) {
	givingInterval(numberFirstElement, numberLastElement);
	if (numberFirstElement < 0) {
		std::cout << "Первый элемент промежутка не может быть меньше нуля" << std::endl;
	}
	if (numberFirstElement > numberLastElement) {
		std::cout << "Номер последнего элемента промежутка не может быть меньше первого" << std::endl;
	}
	if (numberLastElement > vector.size()) {
		std::cout << "Номер последнего элемента промежутка не может быть больше размера самого вектора" << std::endl;
	}
	int sum = 0; 
	for (int i = numberFirstElement; i < (numberLastElement - numberFirstElement); ++i) {
		sum += vector[i];
	}
	for (int j = 0; j < vector.size(); ++j) {
		vector[j] = vector[j] + sum;
	}
}

void changingModuledEven(std::vector<int> vector) {
	int max = findingMax(vector,max);
	int min = findingMin(vector, min);;
	findingMax(vector, max);
	findingMin(vector , min);
	for (int i = 0; i < vector.size(); ++i) {
		if (vector[i] % 2 == 0) {
			vector[i] = (max - min);
		}
	}
}

void deleteSameNumbers(std::vector<int> &vector) {
	for (int i = 0; i < vector.size(); ++i) {
		for (int j = i + 1; j < vector.size();) {
			if (vector[j] == vector[i]) {
				vector.erase(vector.begin() + j);
			}
			else ++j;
		}
	}
}

int main() {
	int min, min;
	int numberFirstElement = 0;
	int numberLastElement = 0;
	int average = 0;
	setlocale(LC_ALL, "Russian");
	std::vector<int> bem;
	inputVector(bem);
	outputVector(bem);
	sizeOfVector(bem);
	deleteSameNumbers(bem);
	outputVector(bem);
	return 0;
}

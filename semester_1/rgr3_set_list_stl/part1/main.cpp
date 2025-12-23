#include <iostream>
#include <set>

void isNegative(int n) {
	if (n < 2) {
		std::cout << "Минимальное простое число : 2" << std::endl;
		exit(0);
	}
}

void gettingDigit(int &n) {
	std::cout << "Введите натуральное число , до которого будет вестить поиск простых чисел решетом Эратосфена :";
	std::cin >> n;
}

void fillingContainer(int n, std::set<int> &set) {
	for (int i = 0; i <= n; ++i) {
		set.insert(i);
	}
}

void Eratosphen(std::set<int> &set ,int n) {
	for (int i = 2; i * i < n; ++i) {
		for (int j = i * i; j < n; j += i) {
			set.erase(j);
		}
	}
}

void outputingElements(std::set<int> set){
	for (auto& item : set) {
		std::cout << item << " ";
	}
	std::cout << std::endl;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int N;
	std::set<int> bem;
	gettingDigit(N);
	fillingContainer(N, bem);
	std::cout << "Полученный контейнер" << std::endl;
	outputingElements(bem);
	Eratosphen(bem, N);
	std::cout << "Ваш контейнер после решета Эратосфена" << std::endl;
	outputingElements(bem);
}

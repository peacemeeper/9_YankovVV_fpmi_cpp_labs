
#include <iostream>
#include <random>

int main()
{
    int n,choose;
    std::cout<<"Введите количество элементов в массиве (Целое натуральное число)"<<std::endl;
    std::cin>>n;
    int *array = new int[n];
        std::cout<<"Если хотите вводить элементы массива самостоятельное , то введите 1 . Если же хотите использовать случайные числа , то введиите 2"<<std::endl;
    std::cin>>choose;
    if (choose ==  1){
          std::cout << "Введите элементы массива: ";
    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
    }
    int sum = 0;
    int a = 0;
    int maxLength = 1;
    int currentLength = 1;
    int startIndex = 0;      // начало текущей цепочки
    int maxStartIndex = 0;   // начало самой длинной цепочки
    
    for (int i = 1; i < n; i++) {
        if (array[i] != array[i - 1]) {
            currentLength++;
            if (currentLength > maxLength) {
                maxLength = currentLength;
                maxStartIndex = startIndex;
            }
        } else {
            currentLength = 1;
            startIndex = i;
        }
    }
     while(array[a]!=0){
        a++;
    }
    while(array[n-1]!=0){
        n--;
    }
    if(a!=n){
        while (a!=n){
        sum+=array[a];
        a++;
        }
        std::cout <<"Сумма между нулями " << sum <<std::endl;
    }
    if(a=n){
        std::cout<<"В массиве либо нет нулей , либо он только один , так что сумма между нулями: "<<sum<<std::endl;
    }
    std::cout << "Длина самой длинной цепочки: " << maxLength << std::endl;
    std::cout << "Начинается с индекса: " << maxStartIndex << std::endl;
    std::cout << "Элементы цепочки: ";
    for (int i = maxStartIndex; i < maxStartIndex + maxLength; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
    
    delete[] array;
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
    for (int i = 0; i < n; i++) {
        array[i] = dist(gen);
        i++;
    }
    
    int sum = 0;
    int a =0;
    int maxLength = 1;
    int currentLength = 1;
    int startIndex = 0;      // начало текущей цепочки
    int maxStartIndex = 0;   // начало самой длинной цепочки
    
    for (int i = 1; i < n; i++) {
        if (array[i] != array[i - 1]) {
            currentLength++;
            if (currentLength > maxLength) {
                maxLength = currentLength;
                maxStartIndex = startIndex;
            }
        } else {
            currentLength = 1;
            startIndex = i;
        }
    }
     while(array[a]!=0){
        a++;
    }
    while(array[n-1]!=0){
        n--;
    }
    if(a!=n){
        while (a!=n){
        sum+=array[a];
        a++;
    }
    std::cout <<"Сумма между нулями " << sum <<std::endl;
    }
    if(a=n){
        std::cout<<"В массиве либо нет нулей , либо он только один , так что сумма между нулями: "<<sum<<std::endl;
    }
    }
    std::cout << "Длина самой длинной цепочки: " << maxLength << std::endl;
    std::cout << "Элементы цепочки: ";
    for (int i = maxStartIndex; i < maxStartIndex + maxLength; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
    
    delete[] array;
    return 0;
}

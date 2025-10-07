#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Введите количество элементов массива: ";
    cin >> n;
    
    double* arr = new double[n];
    
    cout << "Введите элементы массива: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int maxLength = 1;
    int currentLength = 1;
    int startIndex = 0;      // начало текущей цепочки
    int maxStartIndex = 0;   // начало самой длинной цепочки
    
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
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
    
    cout << "Длина самой длинной цепочки: " << maxLength << endl;
    cout << "Начинается с индекса: " << maxStartIndex << endl;
    cout << "Элементы цепочки: ";
    for (int i = maxStartIndex; i < maxStartIndex + maxLength; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    delete[] arr;
    return 0;
}
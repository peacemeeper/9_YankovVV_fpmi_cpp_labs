#include <iostream>



int main() {
    int columns, lines, zeroCount,columnsWithZero , maxLength , length , maxLine, beforeMaxLength;
    maxLine=0;
    maxLength = 1;
    zeroCount = 1;
    columnsWithZero = 0;
    std::cout << "Введите количество столбцов матрицы" << std::endl;
    if(!(std::cin >> columns)){
        std::cout<<"Введите корректное значение"<<std::endl;
        return 0;
    }
    std::cout << "Введите количество строк матрицы" << std::endl;
    if(!(std::cin >> lines)){
        std::cout<<"Введите корректное значение"<<std::endl;
        return 0;
    }
    std::cout<<"Введите матрицу"<<std::endl;
    int array[lines][columns];
    for (int i = 0; i < lines; ++i) {
        for (int j = 0; j < columns; ++j) {
            if(!(std::cin >> array[i][j])){
                std::cout<<"Введите корректное значение"<<std::endl;
                return 0;
            }
        }
    }
    std::cout << "Матрица выглядит вот так:" << std::endl;
    for (int i = 0; i < lines; ++i) {
        for (int j = 0; j < columns; ++j) {
            std::cout << array[i][j] << "\t";
        }
        std::cout << std::endl;
    }
        for (int i = 0; i < columns; ++i) {
        for (int j = 0; j < lines ; ++j) {
            if (array[j][i] == 0) {
                columnsWithZero++;
                i++;
            }
            else if (j == lines ){
                i++;
            }
    }
}
    for (int i = 0; i <= lines ; ++i) {
        if (maxLength > beforeMaxLength ) {
            maxLine++;
        }
        beforeMaxLength=maxLength;
        maxLength = 1;
        length = 1;
        for (int j = 0; j < columns ; ++j) {
            
             if ( array[i][j] < array[i][j+1] ){
                length++;
            }
            if ( array[i][j] >= array[i][j+1] ){
                if( length > maxLength ) {
                    maxLength = length;
                    length = 1;
            }
        }
}
}

    std::cout<<(columns-columnsWithZero)<<" столбцов не содержат 0" << std::endl;
    std::cout<<"Бем бем бем "<< maxLine<<std::endl;
    return 0;
}

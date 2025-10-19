#include <iostream>

int main()
{
    int n,m;
    int array[10][10];
    std::cout<<"Введите количество столбцов матрицы"<<std::endl;
     std::cin>>n;
     std::cout<<"Введите количество строк матрицы"<<std::endl;
     std::cin>>m;
     for ( int i = 0; i < m ; ++i ){
        for ( int j = 0 ; j < n ; ++j){
            std::cin>>array[i][j];
        }
     }
     for ( i = 0; i < m ; ++i ){
        for ( j = 0 ; j < n ; ++j){
            std::cout<<array[i][j]<<"\t";
        }
        std::cout<<endl;
     }
    return 0;
}

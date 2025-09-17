
#include <iostream>

int main()
{
    long long f,a1,a2,a3,a,b,n,l,z,g,rev;
    std::cout<<"Введите число a"<<std::endl;
    if (!(std::cin>>a)){
    std::cout<<"Неверный симовл"<<std::endl;
    return 0;
    }
    std::cout<<"Введите число b"<<std::endl;
    if (!(std::cin>>b)){
    std::cout<<"Неверный символ"<<std::endl;
    return 0;
    }
    
    a1=a;
    a2=a;
    a3=a;
    rev = 0;
    f=0;
    g=0;
    n = 0;
    z = a;
    l = 0;
    while (a2<=b){
        a=a2;
        z=a2;
        a1=a2;
        n=a2;
        rev=0;
        
     while ( a > 0) {
        n = a; 
        a = a / 10;
        l++;
     }
     while ( g < l/2 ) {
        rev = rev *10 + z%10;
        if (rev == 0) {
            goto start_loop;
        }
        z = z/10;
        g++;
     }
      while ( f<l/2) {
          a1 = a1/10;
          f++;
      }
      if ( rev == a1 ) {
         std::cout<<a2<<std::endl;
      }
     
         start_loop:
     a2++;
    }
    
    



    return 0;
}

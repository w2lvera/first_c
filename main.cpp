#include <stdio.h>
#include <math.h>
//#include <locale.h>
//итерационные алгоритмы
// три примера

//пример 1. Перевернуть число, т.е. из 2345 сделать 5432

int reversInt(int a){
    int s=0;
    for( ; a ; a/=10 )
        s=s*10+a%10;
    return s;
}
//пример 2. Подсчитать сумму ряда 1/2+1/4+1/8+1/16+...с точностью eps=0.0001
double sumOfSeries(double eps,int& n){
    double s=0;
    double cn=1;
    n=0;
    while(cn>eps){
        cn = cn/2;//очередной член ряда
        s+=cn;
        n++;//число членов сn, удовлетворяющих заданной точности
    }
    return s;
}
//пример 3. Подсчитать sin(x) с точностью eps=0.0001.
//Использовать разложение sin в ряд Тейлора
//sin(x) = x-x^3/3!+x^5/5!-x^7/7!+...
double mySin(double x, double eps){
    double cn = x;//очередной член ряда
    double s = cn;
    for(int n=3;fabs(cn)>eps;n+=2){
        cn = -cn*x*x/(n*(n-1));
        s+=cn;
    }
    return s;
}
//двочные операции
//операция сдвига, т.е умножения на степень 2
int mult(int x, int multiplier){
    return x<<multiplier;
}
int main()
{
    //setlocale(LC_ALL, "Russian");
   //пример 1. Перевернуть число, т.е. из 2345 сделать 5432
    int res;
    res = reversInt(2345);
    printf("res = %d\n",res);
   //пример 2. Подсчитать сумму ряда 1/2+1/4+1/8+1/16+...с точностью eps=0.0001
    int n;
    double sum = sumOfSeries(0.0001,n);
    printf("sum = %lf   n=%d\n",sum,n);
   //пример 3. Подсчитать sin(x) с точностью eps=0.0001.
    double sin = mySin(3.141592/6,0.01);//sin(30)
    printf("sin = %lf   \n",sin);
   //операция сдвига, т.е умножения на степень 2
   //перебираем все степени двойки до 10 и умножаем 3 на эти степени
    printf("\nДвоичные операции");
    printf("\nсдвиг вправо| множитель | результат = 3 x множитель\n");
    for(int i=2,j=1; j<10 ; i = i<<1,j++){
        printf("     %d      |     %3d   |      %4d\n",j,i,mult(3,j));
    }
    return 0;
}
 //git push --set-upstream fromQt master

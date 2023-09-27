#include <stdio.h>
//функция возвращает модуль числа
int mod(int x) {
    if (x < 0)return -x;
    return x;
}
//функция возвращает модуль числа с использованием оператора ?
int mod1(int x) {
    return (x<0)?-x:x;
}
//функция возвращает максимальное из двух чисел
int max(int a, int b) {
    return (a > b) ? a : b;
}
//функция возвращает максимальное из трех чисел
int max(int a, int b, int c) {
    int max=a;
    if (b > max)max = b;
    if (c > max)max = c;
    return max;
}
//функция возвращает максимальное из n вводимых чисел
int maximum(int n) {
    printf("\ninput %d integers separated by spaces\n",n);
    int max=0x80000000;//самое маленькое int
   // int max = ~0x7ffffffff;
    int i = 0;
    int x;
    while (i < n) {
        scanf("%d", &x);
        if (x > max)max = x;
        i++;
    }
    return max;
}
int maximum1(int n) {
    int max = 0x80000000;
    // int max = ~0x7ffffffff;

    int x;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        if (x == 100)continue;//число 100 не проверяется на максимум
        if (x > max)max = x;

    }
    return max;
}
//функция возвращает максимальное из трех чисел
int max1(int a, int b, int c) {
    int max = a;
    max = (b > max) ? b : max;
    max = (c > max) ? c : max;
    return max;
}
//функция выводит делители числа
void printDel(int x) {
    if (x <= 1)return ;
    printf("\nделители числа %d\n",x);
    for (int i = 2; i * i <= x; i++) {
         if (x % i == 0)
            printf("%d %d\n", x / i, i);
    }
}
//функция проверяет простоту числа. 0 - непростое 1 - простое
int prime(int x) {
    if (x <= 1)return 0;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)  return 0;
    return 1;
}
//функция возвращает простое число, ближайшее к данному х
int prime_closestToThis(int x) {
    int i;
    for (i = 1; !prime(x + i) && !prime(x - i); i++);
    if (prime(x + i))return x + i;
    return x - i;
}
int main()
{
    int res;
    res = mod(-4);
    printf("\nmod(-4) = %d",res);
    res = mod1(-4);
    printf("\nmod(-4) = %d",res);
    res = max(-4,5);
    printf("\nmax(-4,5) = %d",res);
    res = max(-4,-5,-2);
    printf("\nmax(-4,-5,-2) = %d\n",res);
    res = maximum(5);//функция возвращает максимальное из 5 вводимых чисел
    printf("\nmaximum(5) = %d",res);
    printDel(36);//функция выводит делители числа 36
    res = prime_closestToThis(50);//функция возвращает простое число, ближайшее к 50
    printf("\nprime_closestToThis(50) = %d",res);
}
 //git push --set-upstream fromQt master

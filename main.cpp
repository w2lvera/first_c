#include <stdio.h>

int lastDigit(int value){
    return value - value/10*10;
}
int even(int value){
    return value - value/2*2;
}
int check(int value, int del){
    return value - value/del*del;
}
/////////////////// указатели /////////////////
void swap(int* a, int* b){
    int help;
    help = *a; // положить в а то, что лежит по адресу b
    *a = *b; //по адресу а положить то, что лежит по адресу b
    *b = help;//по адресу b положить то, что лежит и help
}
int main()
{
    int a = 123;
    int result;
    result = even(a);
    printf("result = %d\n",result);
    result = lastDigit(a);
    printf("result = %d\n",result);
    result = check(a,10);
    printf("result = %d\n",result);
//////////////////////////// указатели /////////////////////////////
    int c = 100;
    int b = 1;
    printf("\n pointers \n");
    printf("c = %d  b = %d\n",c,b);
    swap(&c,&b);// swap(&с - взятие адреса переменной с , &b - взятие адреса переменной b)
    printf("after swap \nc = %d  b = %d\n",c,b);
    return 0;
}
 //git push --set-upstream fromQt master

#include <stdio.h>

using namespace std;
int lastDigit(int value){
    return value - value/10*10;
}
int even(int value){
    return value - value/2*2;
}
int check(int value, int del){
    return value - value/del*del;
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

    return 0;
}
 //git push --set-upstream fromQt master

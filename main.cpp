#include <stdio.h>
typedef unsigned char byte;
//checking the k-th bit of value

byte checkByte(byte value,byte k){
    return (value&(1<<k))>>k;
}

int main()
{
    byte x = 252;    //binary representation of x --> 1111 1100
    //mask = 1000 0000...0000 0000, k - 7...0 bit
    for(int mask = 0x80,k=7;mask;mask=mask>>1,k--){
        byte res = (x&mask)>>k;
        printf("%d",res);
    }
    return 0;
}
 //git push --set-upstream fromQt master

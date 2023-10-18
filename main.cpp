//bit operation
#include <stdio.h>
typedef unsigned char byte;
typedef unsigned short word;
//////////////////////////////////////////////
//checking the k-th bit of value
byte checkBite(byte value,byte k){
    return (value&(1<<k))>>k;
}
//binary representation of value x --> 1111 1100
void binaryRepresentation(byte value){
    for(int k = 7;k>=0;k--)
        printf("%d",checkBite(value,k));
}
//////////////////////////////////////////////
//checking the k-th 4bit of value
byte check4Bite(word value,word k){
    return (value&(15<<k))>>k;
}
//hexadecimal representation of value
void hexRepresentation(word value){
    for(int k = 12;k>=0;k-=4){
        byte res = check4Bite(value,k);
        if(res<10)printf("%d",res);
        else printf("%c",'A'+res-10);
    }
}
//////////////////////////////////////////////
//checking the k-th 3bit of value
byte check3Bite(word value,word k){
    return (value&(7<<k))>>k;
}
//octal representation of value
void octalRepresentation(word value){
    for(int k = 15;k>=0;k-=3){
        byte res = check3Bite(value,k);
        printf("%d",res);
        }
}
////////////////////////////////////////////
/// replacing bits in a value
////////////////////////////////////////////
word replacing3Bits(byte k,word x,word m){
    if(k>7||k<4)throw 1;
    word mask = ~(7<<m);
    return (x&mask)|(k<<m);
}
///create mask for k
byte createMask(byte k){
    byte mask = 1;
    while(k>>1){
        mask=mask<<1;
        k=k>>1;
    }
    return (mask<<1)-1;
}
word replacingBits(byte k,word x,word m){

    word mask = ~(createMask(k)<<m);
    return (x&mask)|(k<<m);
}

int main()
{
    //binary representation of x --> 1111 1100
    byte x=252;
    printf("\n binary representation of x = 252          ");
    binaryRepresentation(x);
    //hexadecimal representation of y = 0xFFFF
    word y = 0xFFFF;
    printf("\n hexadecimal representation of y =0xffff   ");
    hexRepresentation(y);
    //octal representation of y = 0xffff
    printf("\n octal representation of y = 0xffff        ");
    octalRepresentation(y);
    ///
    /// replacing bits in a value
    ///
    word value = 40;//0000 0000 0010 1000
    //replacing bits 2,3,4 of the number 40 with 5
    word res;
    try{
        res = replacing3Bits(5,value,2);
        printf("\n replacing bits 2,3,4 of the number 40 with 5 ");
    //     00101000 40
    //     00010100  5<<2
    //     replacing3Bits(5,value,2)
    //     00110100 52
        printf("res = %d",res);
    }
    catch(int x){
        printf("\n the replacement variable must be less than 7 and greater than 3\n");
    }

    //replacing bits 2,3,4 of the number 40 with 5 with count of mask
    res = replacingBits(5,value,2);
    printf("\n replacing bits 2,3,4 of the number 40 with 5 with count of mask  %d",res);
    //replacing 5 bit of the number 40 with 0 with count of mask
    res = replacingBits(0,value,5);
    printf("\n replacing 5 bit of the number 40 with 0 with count of mask  %d",res);

    return 0;
}
 //git push --set-upstream fromQt master

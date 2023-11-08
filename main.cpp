#include <stdio.h>
//Sum of array elements
int sumLine(int* a,int n){
    int s=0;
    for(int i=0;i<n;i++) s+=a[i];
    return s;
}
void printLine(int * a,int n){
    for(int i=0;i<n;i++) printf("%4d ",a[i]);
}
const int m = 3;
void printArray2(int a[][m],int n,int m){
    for(int i = 0;i<n;i++){
        for(int j=0;j<m;j++)
            printf("%4d ", a[i][j]);
        printf("\n");
    }
}
void printDinamicArray2(int** a,int n,int m){
    for(int i = 0;i<n;i++){
        for(int j=0;j<m;j++)
            printf("%4d ", a[j][i]);
        printf("\n");
    }
}
void printArrayByString(int* a,int n,int m){
    for(int i = 0;i<n;i++){
        for(int j=0;j<m;j++)
            printf("%4d ", a[i*m+j]);
        printf("\n");
    }
}
void printArrayByCollum(int* a,int n,int m){
    for(int j = 0;j<m;j++){
        for(int i=0;i<n;i++)
            printf("%4d ", a[j+i*m]);
        printf("\n");
    }
}
int shiftElementRight(int* a,int n){
    int last = a[n-1];
    for(int i=n-1;i>0;i--)
        a[i]=a[i-1];
    a[0]=last;
    return last;
}
int shiftElementLeft(int* a,int n){
    int first = a[0];
    for(int i=0;i<n-1;i++)
        a[i]=a[i+1];
    a[n-1]=first;
    return first;
}
int main()
{
    const int n = 5;

    ////////// two-dimensional arrays //////////////

    int matr[n][m] = {
                      0,0,0,
                      1,1,1,
                      2,2,2,
                      3,3,3,
                      4,4,4
                     };
    printArray2(matr,n,m);
    printf("\n print by strings\n");
    printArrayByString(*matr,n,m);
    printf("\n print by collums\n");
    printArrayByCollum(*matr,n,m);
    /////////////////////sum all elements////////////////////
    int sum = sumLine(*matr,n*m);
    int sum1String = sumLine(matr[1],m);
    printf("\nsum all elements %d\nsum 1 string %d\n",sum,sum1String);
    ////////////////////dinamic arrays//////////////////////
    int n1 = 4;
    int* arr = new int[n1]{1,2,3,4};
    shiftElementRight(arr,n1);
    printLine(arr,n1);
    shiftElementLeft(arr,n1);
    printLine(arr,n1);
    int** arr2 = new int*[n1];
    for(int i = 0; i<n1 ;i++)
        arr2[i]= new int[n1]{i,i,i,i};

    printf("\n print by strings\n");
    printDinamicArray2(arr2,n1,n1);


    return 0;
}
 //git push --set-upstream fromQt master

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
//array in stack
const int m = 3+1;
void printArray2(int a[][m],int n,int m){
    for(int i = 0;i<n;i++){
        for(int j=0;j<m;j++)
            printf("%4d ", a[i][j]);
        printf("\n");
    }
}
//array in dinamic memory
void printDinamicArray2(int** a,int n,int m){
    for(int i = 0;i<n;i++){
        for(int j=0;j<m;j++)
            printf("%4d ", a[i][j]);
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
//////////////////////////////////// lesson8 ////////////////////
int sumDiagonalUp(int** a,int n){
    int sum = 0;
    for(int i = 0;i<n;i++)
        for(int j=i;j<n;j++)
            sum += a[i][j];
    return sum;
}
int sumDiagonalDown(int** a,int n){
    int sum = 0;
    for(int i = 0;i<n;i++)
        for(int j=0;j<i;j++)
            sum += a[i][j];
    return sum;
}
int sumDiagonal(int** a,int n){
    int sum = 0;
    for(int i = 0;i<n;i++)
        sum += a[i][i];
    return sum;
}
void chessOrder(int* a,int n){
    for(int i = 0;i<n-1;i+=2){
        a[i]=1;
        a[i+1]=2;
    }

    a[n-1]=(n%2)?1:2;
}
int batchInLine(int* a,int n){
    int batchSize = 1;
    int maxBatchSize = 1;
    int i;
    for(i = 0; i<n-1; i++ ){
        if(a[i]==a[i+1]){  //seria
            batchSize++;
        }
        else{ // end seria
            if(batchSize>maxBatchSize){
                maxBatchSize = batchSize;
            }
           batchSize = 1;
        }
    }
    //seria has last element
    if(batchSize!=1 && i == n-1)
        if(batchSize>maxBatchSize){
            maxBatchSize = batchSize;
        }
    return maxBatchSize;
}
int main()
{
    const int n = 5;

    ////////// two-dimensional arrays //////////////

    int matr[n][m] = {
                      0,0,0,0,
                      1,1,1,1,
                      2,2,2,2,
                      3,3,3,3,
                      4,4,4,4
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
    ////////////////////lesson 8 chessOrder ///////////////////
    chessOrder(*matr,n*(m));
    printf("\n");
    printArray2(matr,n,m);
    printf("\n");
    ////////////////////dinamic arrays//////////////////////
    int n1 = 4;
    int* arr = new int[n1]{1,2,3,4};
    shiftElementRight(arr,n1);
    printLine(arr,n1);
    shiftElementLeft(arr,n1);
    printLine(arr,n1);

    /////////// two-dimensional array in dinamic memory ///////////////

    int** arr2 = new int*[n1];
    for(int i = 0; i<n1 ;i++)
        arr2[i]= new int[n1]{i,i,i,i};

    printf("\n print by strings\n");
    printDinamicArray2(arr2,n1,n1);
    /////////////////// diagonal ///////////////////////
    sum = sumDiagonalUp(arr2,n1);
    printf("\n sumDiagonalUp sum = %d\n",sum);
    sum = sumDiagonalDown(arr2,n1);
    printf("\n sumDiagonalDown sum = %d\n",sum);
    sum = sumDiagonal(arr2,n1);
    printf("\n sumDiagonalUp sum = %d\n",sum);
    ////////////////////// seria //////////////////////
    /// \brief batchInLine
    /// \param a
    /// \param n
    ///

    int a[n*m]{1,1,1,1,1,1,5,6,7,4,4,4,4,3,4,0,0,0,0,0};
    int batchSize = batchInLine(a, n*m);
    printf("\n bathSize = %d",batchSize);
    return 0;
}
 //git push --set-upstream fromQt master

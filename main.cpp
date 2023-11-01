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
int main()
{
    const int n = 5;
    int arr[n] = {1,2,3,4,5};
    for(int x:arr)printf("%d ",x);
    for(int i=0;i<n;i++) arr[i]=i+1;
    /////////////////////sum////////////////////
    int sum = sumLine(arr,n);
    //Sum of array elements without first element
    int sumWithoutFirst = sumLine(arr+1,n-1);
    ////////// two-dimensional arrays //////////////
    const int m = 3;
    int matr[n][m] = {0,0,0,
                     1,1,1,
                     2,2,2,
                     3,3,3,
                     4,4,4};
    //print line by line
    printf("\n");
    for(int i = 0;i<n;i++){
        for(int j=0;j<m;j++)
            printf("%4d ", matr[i][j]);
        printf("\n");
    }
    printf("\nprint for each");
    for(int* p :matr){
        printf("\n");
        printLine(p,m);
    }

    //print by columns
    printf("\nprint by columns\n");
    for(int i = 0;i<m;i++){
        for(int j=0;j<n;j++)
            printf("%4d ", matr[j][i]);
        printf("\n");
    }
    //sum of matrix elements
    int sumOfMatrixElements = sumLine(*matr,n*m);
    printf("\nsum of matrix elements %d",sumOfMatrixElements);
    //the sum of the elements of each row of the matrix
    int sumElementsOfEachRow;
    for(int i = 0;i<n;i++)
    {
        sumElementsOfEachRow = sumLine(matr[i],m);
        printf("\n row %d sum = %d",i,sumElementsOfEachRow);
    }
    return 0;
}
 //git push --set-upstream fromQt master

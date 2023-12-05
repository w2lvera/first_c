#include <stdio.h>
int readTextFileByInt(const char* fileName){
    int n;
    int m;
    FILE* f;
    fopen_s(&f,fileName,"r");
    if(!f)return -1;
    fscanf(f,"%d%d",&n,&m);
    int** a = new int*[n];
    for(int i=0;i<n;i++)
        a[i] = new int[m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            fscanf(f,"%d",&a[i][j]);
            printf("%d",a[i][j]);
        }
        printf("\n");
    }
    fclose(f);
    return 0;
}
int readTextFileByIntWithError(const char* fileName){
    int d;

    FILE* f;
    fopen_s(&f,fileName,"r");
    if(!f)return -1;
    while(fscanf(f,"%d",&d)==1){
       printf("%d ",d);
    }
    if(feof(f))return 0;
    return -2;
    fclose(f);
    return 0;
}
int readTextFileByWords(const char* fileName){
    char word[80];
    FILE* f;
    fopen_s(&f,fileName,"r");
    if(!f)return -1;
    while(fscanf(f,"%s",word)==1){
        puts(word);
    }
    fclose(f);
    return 0;
}
int readTextFileByStrings(const char* fileName){
    char str[800];
    FILE* f;
    fopen_s(&f,fileName,"r");
    if(!f)return -1;
    while(fgets(str,800,f)){
        puts(str);
    }
    fclose(f);
    return 0;
}
int readTextFileAndWriteToAnother(const char* fileNameRead,const char* fileNameWrite){
    char str[800];
    FILE* f;
    fopen_s(&f,fileNameRead,"r");
    FILE* f1;
    fopen_s(&f1,fileNameWrite,"w");
    if(!f1)return -1;
    while(fgets(str,800,f)){
        fputs(str,f1);
    }
    fclose(f);
    fclose(f1);
    return 0;
}
int main()
{
    int err=readTextFileByIntWithError("C:\\Users\\Vera\\Documents\\withoutQt\\text.txt");
    switch(err){
    case 0: printf("OK\n");break;
    case -1: printf("file not open\n");break;
    case -2: printf("file have error\n");
    }

//    if(readTextFileByWords("C:\\Users\\Vera\\Documents\\withoutQt\\main.cpp")==-1){
//        printf("file not open\n");
//               return -1;
//    }
//    if(readTextFileByStrings("C:\\Users\\Vera\\Documents\\withoutQt\\main.cpp")==-1){
//        printf("file not open\n");
//               return -1;
//    }
//    if(readTextFileAndWriteToAnother("C:\\Users\\Vera\\Documents\\withoutQt\\main.cpp","C:\\Users\\Vera\\Documents\\withoutQt\\main1.cpp")==-1){
//        printf("file not open\n");
//               return -1;
//    }
}
 //git push --set-upstream fromQt master

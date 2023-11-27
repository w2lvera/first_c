#include <stdio.h>
#include <string.h>
int myStrlen(char* str){
    int n = 0;
    for(;str[n]!='\0'; n++);
    return n;
}
int myStrcmp(const char* s1,const char* s2){
    int i = 0;
    for(int i=0;s1[i]!='\0'&& s2[i]!='\0'&& s1[i]==s2[i];i++);
    return s1[i]-s2[i];
}
void myStrcpy(char* s1,char*s2){
    while(*s1++=*s2++);
   // for(int i=0;s1[i]!='\0'&& s2[i]!='\0'; s1[i]=s2[i],i++);
}
char* resizeStr(char*str, char c){
    int i;
    for(i=0;str[i] && str[i]!=c;i++);
    str[i]='\0';
    return str;
}
int charToInt(const char* str){
    int number = 0;
    for(int i = 0;str[i];i++)
        number = number*10+str[i]-'0';
    return number;
}
char* intToChar(int n,char* str){
    int i;
    for(i=0;n!=0;i++,n/=10){
        str[i] = n%10+'0';
    }
    int k =i;
    for(int i = 0,j=k-1;i<j;i++,j--){
        int s = str[i];
        str[i] = str[j];
        str[j] = s;
    }
    str[k]='\0';
}
char* capitalToUpper(char* str){
    for(int i = 0; str[i];i++){
        if(str[i]>'A'&& str[i]<'Z')
            str[i]+='a'-'A';
    }
    return str;
}
int main()
{
    printf("   cod   |    simvol\n");
    for(int i=32;i<255;i++)
        printf("   %3d   |    %c\n",i,i);
    char str[100]="i love you";
    printf("\n%s   strlen = %d last simvol %d\n",str,myStrlen(str),str[10]);
    resizeStr(str,'y');
    printf("\n%s \n",str);
    int n = charToInt("1234");
    printf("\n n=%d \n",n);
    intToChar(n,str);
    printf("\n%s \n",str);
    myStrcpy(str,"I love Strings");
    printf("\n%s \n",str);
    capitalToUpper(str);
    printf("\n%s \n",str);

}

 //git push --set-upstream fromQt master

#include<stdio.h>
#include<string.h>
int ctoe(char str1[100]){//though etoc and c toe are same,just for easiness written
    int i,j;
    for(i=0;str1[i]!='\0';i++){
        if(str1[i]=='e'){//conversion happens
            str1[i]='a';
        }
        else if(str1[i]=='a'){
            str1[i]='e';
        }
        if(str1[i]=='f'){
            str1[i]='u';
        }
        else if(str1[i]=='u'){
            str1[i]='f';
        }
    }
    for(j=0;str1[j]!='\0';j++){
        printf("%c",str1[j]);
    }
    return 0;
}
int etoc(char str1[100]){//though etoc and c toe are same,just for easiness written
    int i,j;
    for(i=0;str1[i]!='\0';i++){
        if(str1[i]=='e'){//conversion happens
            str1[i]='a';
        }
        else if(str1[i]=='a'){
            str1[i]='e';
        }
        if(str1[i]=='f'){
            str1[i]='u';
        }
        else if(str1[i]=='u'){
            str1[i]='f';
        }
    }
    for(j=0;str1[j]!='\0';j++){
        printf("%c",str1[j]);
    }
    return 0;
}
int main(void)
{
    char str1[100];
    char str[1];
    scanf("%s\n",str);
    fgets(str1,100,stdin);//input taken
    if(*str=='e'){
        ctoe(str1);
    }
    else if(*str=='c'){
        etoc(str1);
    }

    return 0;
}

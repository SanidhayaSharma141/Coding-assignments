#include<stdio.h>
#include<string.h>
int v(char str[]){
    char ch;
    int c=0;
    int i;
    for(i=0;str[i+1]!='\0';i++){//i+1 is done everywhere coz my compiler is giving length one more than actual one,output is correct.therefore i+1 is used everywhere
        ch=tolower(str[i]);//it was taught in class..its there in pdf as well
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
            c++;
        }
    }
    printf("%d",c);
    return 0;
}
int c(char str[]){
    char ch;
    int c=0;
    int i=0;
    for(i=0;str[i+1]!='\0';i++){
        ch=tolower(str[i]);
        if(ch=='b'||ch=='c'||ch=='d'||ch=='f'||ch=='g'||ch=='h'||ch=='j'||ch=='k'||ch=='l'||ch=='m'||ch=='n'||ch=='p'||ch=='q'||ch=='r'||ch=='s'||ch=='t'||ch=='v'||ch=='w'||ch=='x'||ch=='y'||ch=='z'){
            c=c+1;
    }}
    printf("%d",c);
    return 0;
}
int d(char str[]){
    int c=0,i=0;
    for(i=0;str[i+1]!='\0';i++){
        char ch=str[i];
        if(ch=='0'||ch=='1'||ch=='2'||ch=='3'||ch=='4'){
            c=c+1;
        }
        else if(ch=='5'||ch=='6'||ch=='7'||ch=='8'||ch=='9'){
            c=c+1;
        }
    }
    printf("%d",c);
    return 0;
}
int s(char str[]){
    int c=0,i=0;
    for(i=0;str[i+1]!='\0';i++){
        char ch=str[i];
        if(ch==' '){
            c=c+1;
        }
    }
    printf("%d",c);
    return 0;
}
int r(char str[]){
    int j;
    for(j=strlen(str)-2;j>=0;j--){
        printf("%c",str[j]);}
    return 0;
}
int main(void)
    {
    char str[100];//as we dont knw the size
    char response[1];
    scanf("%s\n",response);
    fgets(str,100,stdin);
    if(*response=='v'){
        v(str);
    }
    else if(*response=='c'){
        c(str);
    }
    else if(*response=='d'){
        d(str);
    }
    else if(*response=='s'){
        s(str);
    }
    else if(*response=='r'){
        r(str);
    }
    else{
        printf("Invalid character");
    }
    return 0;
}

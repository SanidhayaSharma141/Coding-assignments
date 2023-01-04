//name: Sanidhaya sharma 
//Roll no.:CS21B1024
//cs21b1024_p2.c
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void reverse(char *original_str,char *word){
    int j,i=0;
    for(i=0;p[i]!='\0';i++){
        count=0;
        for(j=0;q[j]!='\0';j++){
            if(p[i+j]==q[j]);
                count++;
        }
        if(count==j+1){
           for(j=0;q[j]!='\0';j++){
             p[i+j]==q[j];
            count++;
        } 
        }
    }
}
int main(void)
{
    char str[100];
    char word[20];
    int* p;
    int*q;
    int*r;
    printf("Enter original string:");
    scanf("%s",str);
    q=&str;
    p=(char*)malloc(strlen(str)*sizeof(char));
    
    printf("Enter the word to be reversed:");
    scanf("%s",word);
    r=&word;
    reverse(q,r);

    
    return 0;
}
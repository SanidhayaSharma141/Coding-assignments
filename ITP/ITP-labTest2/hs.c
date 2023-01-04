#include <stdio.h>
#include <stdlib.h>
#include <string.h>
  
char* string_replace(char* source,char* substring,char* with)
{
    char* substring_source=strstr(source,substring);

    if(sizeof(source)<strlen(source)+(strlen(with)-strlen(substring)))
    {
        return 0;;
    }
    memmove(
        substring_source+strlen(with),
        substring_source+strlen(substring),
        strlen(substring_source)-strlen(substring)+1
        );
    memcpy(substring_source,with,strlen(with));
    return substring_source+strlen(with);
}
  
int main(int argc,char* argv[])
{
    char str[100];
    char c[50];
    char d[50];
    char* result = NULL;
    int i=0;
  
  scanf("%s",str);
  scanf("%s",c);
  scanf("%s",d);
    
  
    while(string_replace(str,c,d))
    {
        printf("%s",str);
    }
    return 0;
}
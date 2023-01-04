//<CS21B1024> <SANIDHAYA SHARMA>
//CS21B1024 PROBLEM 1
#include<stdio.h>
int amount(bal){
    int i,b,
    printf("Enter the withdrawal amount ");
        scanf("%d",&i);
        if(bal<i){
            printf("You don't have sufficient balance");
        }
        else if((i%3==0)||(i%7==0)){
            bal=bal-i;
            printf("After withdrawing %d: %d\n", i,bal);
            return bal;
}}
int main(void){
    int bal,n,i,j,a,b,c;
    char chars;

    printf("Enter the account balance: ");
    scanf("%d",&bal);
    printf("Initial account balance: %d\n",bal);
    amount(bal);
    while(true){
        printf("Do you want to raise more withdrawal requests(Y/N): ");
        scanf("%c",&chars);
        if(chars=='Y'){
            amount(bal);
        }
        else{
            break;
        }}

    }
    

    return 0;
}
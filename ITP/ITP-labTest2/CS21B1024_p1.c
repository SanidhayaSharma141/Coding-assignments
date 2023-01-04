//Roll no.:CS21B1024
//Name: Sanidhaya sharma
//CS21B1024_P1.c
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Student{
    int rollno;
    float cgpa;
    };
struct Student b[50];
int highcgpa(int i){
    int j;
    float p;
    p=b[0].cgpa;
    for(j=0;j<i;j++){
        if(p<b[j].cgpa){
            p=b[j].cgpa;
        }
    }
    printf("Highest CGPA is %f",p);
    return 0;
}
int lowcgpa(int i){
    int j;
    float p;
    p=b[0].cgpa;
    for(j=0;j<i;j++){
        if(p>b[j].cgpa){
            p=b[j].cgpa;
        }
    }
    printf("Lowest CGPA is %f",p);
    return 0;
}
int parcgpa(float cgp,int i){
    int j,count=0;
    int arr[50];
    for(j=0;j<i;j++){
        if(b[j].cgpa==cgp){
            count++;
            if(count==1){
                printf("Roll no.s of students having %f CGPA:",cgp);
                printf("%d",j+1);
            }
            printf("%d",j+1);
        }
    }

    return 0;

}
int main(void)
{
    int i=0;
    float cgp;
    char rep2[4],rep3[4];
    char rep;
    do
    {
        printf("Enter the details of the student:");
        scanf("%d",&b[i].rollno);
        scanf("%f",&b[i].cgpa);
        i=i+1;
        printf("Want to enter the details of more students ? Enter Yes to Continue, otherwise enter No:");
        scanf("%c",&rep);
    } while ( rep=='Yes');
    do
    {
        printf("\nPlease choose the operation you want to perform:\n");
        printf("1. Press H for highest CGPA\n");
        printf("2. Press L for lowest CGPA\n");
        printf("3. Press P to find students with a particular CGPA\n");
        printf("4. Type Exit to stop\n");
        scanf("%s",rep3);
        if(rep3=="H"){
            highcgpa(i);
        }
        else if(rep3=="L"){
            lowcgpa(i);
        }
        else if(rep3=="P"){
            printf("Enter the CGPA:");
            scanf("%f",cgp);
            parcgpa(cgp,i);
        }
        else if(rep3=="Exit"){
            break;
        }
        printf("Want to continue ? Enter Yes to Continue, otherwise enter No:");
        scanf("%s",rep2);
        if(rep2=="No"){
            printf("“You choose to exit”.");
        }

    } while (rep2=="Yes" );

    return 0;
}

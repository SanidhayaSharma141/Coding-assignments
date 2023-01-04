/* Dynamic Programming C implementation of LCS problem */
#include<stdio.h>
#include<string.h>
#define A_MAX 50
#define B_MAX 50
struct subseq{
    int L[A_MAX][B_MAX];
    char str[A_MAX];
};
int max(int a, int b) {
   return (a>b? a:b);
}
typedef struct subseq ss;
// void printsol(ss k,char * X,int i,int j){
//     if (i==0||j==0){
//         return;
//     }
//     else if (k.st[i][j]==4){
//         printf("h");
//         printsol(k,X,i-1,j-1);
//         printf("%s",X[i]);
//     }
//     else if (k.st[i][j]==2){
//         printf("o");
//         printsol(k,X,i-1,j);
//     }
//     else{
//         printf("p");
//         printsol(k,X,i,j-1);
//     }

// }

ss lcs(char *X, char *Y, int m, int n)
{
    ss k;

	for (int i = 1; i <=m; i++)
	{
		for (int j = 1; j<=n; j++)
		{
			if (X[i - 1] == Y[j - 1]){
                // k.st[i][j]=4;
				k.L[i][j] = k.L[i - 1][j - 1] + 1;
                // strncat(k.str,&Y[j-1],1);
                //1 means diagonal 2 means up, 3 means down
                }
                
			else{
				k.L[i][j] = max(k.L[i - 1][j], k.L[i][j - 1]);}
                // k.st[i][j]= (k.L[i - 1][j]> k.L[i][j - 1])? 2:3;
                
		}
	}

	// L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1]
    // printsol(k,X,m,n);
	return k;
}



// Driver program to test above function
int main()
{

	char X[A_MAX] = "AGGTABckl";
	char Y[B_MAX] = "GXTXAYBchghklpp";

	int m = strlen(X);
	int n = strlen(Y);
    ss k=lcs(X,Y,m,n);
    printf("Length of LCS is: %d\n",k.L[m][n]);
    printf("the subsequence is : %s",k.str);

	return 0;
}
// code submitted by Aditya Yadav (adityayadav012552)

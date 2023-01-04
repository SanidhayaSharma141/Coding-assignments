/* Dynamic Programming C implementation of LCS problem */
#include<stdio.h>
#include<string.h>
#define A_MAX 50
#define B_MAX 50
int max(int a, int b) {
   return (a>b? a:b);
}
struct subseq{
    int L[A_MAX][B_MAX];
    char str[A_MAX];
};
typedef struct subseq ss;
/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
ss lcs(char *X, char *Y, int m, int n)
{
    ss k;
    int ct=0;
	// intitalizing a matrix of size (m+1)*(n+1)
	// int L[m + 1][n + 1];

	/* Following steps build L[m+1][n+1] in bottom up fashion. Note
		that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (X[i - 1] == Y[j - 1]){
				k.L[i][j] = k.L[i - 1][j - 1] + 1;
                strncat(k.str,Y[j-1],1);}
                
			else
				k.L[i][j] = max(k.L[i - 1][j], k.L[i][j - 1]);
		}
	}

	// L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1]
	return k;
}

// ss lcssol(char *X, char *Y, int m, int n){
//     ss k=lcs(X,Y,m,n);

// }
// Driver program to test above function
int main()
{
	
	char X[A_MAX] = "AGGTABckl";
	char Y[B_MAX] = "GXTXAYBchghklpp";

	int m = strlen(X);
	int n = strlen(Y);
    ss k=lcs(X,Y,m,n);
    printf("Length of LCS is: %d\n",k.L[m][n]);
    printf("the subsequence is : %s",strrev(k.str));

	return 0;
}
// code submitted by Aditya Yadav (adityayadav012552)

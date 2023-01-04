#include<stdio.h>
#define MAX_WEIGHT 100
#define N 100
struct Knapsack{
    int knap[N][MAX_WEIGHT];
    int arr[N];
};
typedef struct Knapsack ks;
int max(int a, int b) {
   return (a>b? a:b);
}
ks knapsack(int W, int wt[], int val[], int n) {
   int i, w;
   ks k;
   for (i = 1; i <= n; i++) {
      for (w = 1; w <= W; w++) {
         if (wt[i-1] <= w)
            k.knap[i][w] = max(val[i-1] + k.knap[i-1][w-wt[i-1]], k.knap[i-1][w]);
         else
            k.knap[i][w] = k.knap[i-1][w];
      }
   }
   return k;
}



ks knapsacksol(int W, int wt[], int val[], int n){
    ks k=knapsack(W,wt,val,n);
    int kp=0;
    int j=W;
    // int arr[n];
    for(int i= n;i>=0&&j>0;i--){
        if(k.knap[i][j]>k.knap[i-1][j]){
            k.arr[kp++]=wt[i-1];
            j=j-wt[i-1];
        }
        
    }

    return k;

    
}
int main() {
   int val[] = {12,10,20,15};
   int wt[] = {2,1,3,2};
   int W = 5;
   int n = sizeof(val)/sizeof(val[0]);
   ks k=knapsacksol(W, wt, val, n);
//    for(int i=0;i<=n;i++){
//     for(int j=0;j<=W;j++){
//         printf("%d ",k.knap[i][j]);
//     }
//     printf("\n");
//    }
   printf("The solution is : %d \n",k.knap[n][W]);
   printf("the weights are:");
   for(int i=0;i<=n&&k.arr[i]!=0;i++){
    printf("%d ",k.arr[i]);
   }
   return 0;
}
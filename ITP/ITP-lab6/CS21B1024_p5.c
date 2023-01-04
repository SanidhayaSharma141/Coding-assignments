#include<stdio.h>
int main(void)
{
    int i,j,k,l;
    int a,b,c,d;
    int arr0[3][2][2],arr1[3][2][2],arr2[3][2][2],arr3[3][2][2];
    int arrf[4][3][2][2];
//taking one of the 4 3d arrays and scanning the value and then storing that value in the 4d array 
    for(i=0;i<3;i++){
        for(j=0;j<2;j++){
            for(k=0;k<2;k++){
            scanf("%d",&arr0[i][j][k]);
            arrf[0][i][j][k]=arr0[i][j][k];
            }
        }
    }
//taking one of the 4 3d arrays and scanning the value and then storing that value in the 4d array 
    for(i=0;i<3;i++){
        for(j=0;j<2;j++){
            for(k=0;k<2;k++){
                scanf("%d",&arr1[i][j][k]);
                arrf[1][i][j][k]=arr1[i][j][k];
            }
        }
    }
//taking one of the 4 3d arrays and scanning the value and then storing that value in the 4d array 
    for(i=0;i<3;i++){
        for(j=0;j<2;j++){
            for(k=0;k<2;k++){
                scanf("%d",&arr2[i][j][k]);
                arrf[2][i][j][k]=arr2[i][j][k];
            }
        }
    }
    //taking one of the 4 3d arrays and scanning the value and then storing that value in the 4d array 
    for(i=0;i<3;i++){
        for(j=0;j<2;j++){
            for(k=0;k<2;k++){
                scanf("%d",&arr3[i][j][k]);
                arrf[3][i][j][k]=arr3[i][j][k];
            }
        }
    }
    scanf("%d %d %d %d",&a,&b,&c,&d);
    printf("%d",arrf[a][b][c][d]);
    return 0;
}
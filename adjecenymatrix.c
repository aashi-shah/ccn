#include<stdio.h>

#define vertices 10
#define edges 10

void createarr(int n, int arr[][n+1],int m){
    int x,y;

    for(int i=0;i<n+1;i++){
        for(int j=0;j<n+1;j++){
            arr[i][j] = 0;
        }
    }

    for(int i=0;i<m;i++){
        printf("\nEnter the edge %d : ", i+1);
        scanf("%d %d", &x,&y);

        arr[x][y] = 1;
        arr[y][x] = 1;
    }
}

void disparr(int n, int arr[][n+1]){
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            printf(" %d ",arr[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int n,m;

    printf("\nEnter no of edges : ");
    scanf("%d", &n);
    printf("\nEnter no. of vertices : ");
    scanf("%d", &m);

    if(m> n*(n-1)/2){
        printf("\nInvalid");
        return 1;
    }

    int arr[vertices+1][vertices+1];
    createarr(n,arr,m);
    disparr(n,arr);
    return 0;
}

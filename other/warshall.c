#include <stdio.h>
#include <stdbool.h>
#include <string.h>


void warshall(int n,bool mat[n][n]){
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                mat[i][j] = mat[i][j] || (mat[i,k] && mat[j][k]);
}


int main()
{
    int n, e;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    bool mat[n][n];
    memset(mat, false, sizeof(mat));

    printf("Enter the number of edges: ");
    scanf("%d", &e);

    printf("Enter the edges:\n");
    int v1, v2;
    for (int i = 0; i < e; i++)
    {
        printf("Edge %d: ",i);
        scanf("%d%d", &v1, &v2);
        mat[v1][v2] = true;
    }

    int sorted[n];

    warshall(n, mat);

    printf("transitive closure\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            printf("%d  ",mat[i][j]);
        printf("\n");
    }

    printf("sorted order: ");
    for(int i=0;i<n;i++)
        printf("%d  ",sorted[i]);

    return 0;
}
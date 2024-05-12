#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void topologicalSort(int n, bool mat[n][n], int sorted[n])
{
    int indegree[n];
    bool visited[n];
    int zeroindegvertex = -1;

    for (int i = 0; i < n; i++)
    {
        indegree[i] = 0;
        visited[i] = false;
        for (int j = 0; j < n; j++)
            indegree[i] += mat[j][i] ? 1 : 0;
        if (indegree[i] == 0)
            zeroindegvertex = i;
    }

    int count = 0;
    while (true)
    {
        if (zeroindegvertex == -1)
            if (count == n)
                return;
            else
            {
                printf("cycle found sorting not possible");
                return;
            }

        sorted[count] =  zeroindegvertex;
        visited[zeroindegvertex] = true;
        
        int temp = -1;
        for (int i = 0; i < n; i++) {
            if (mat[zeroindegvertex][i] == true)
                indegree[i]--;

            if(indegree[i]<1 && !visited[i])
                temp = i;
        }
        zeroindegvertex = temp;
        count++;
        
    }
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

    topologicalSort(n, mat, sorted);

    printf("sorted order: ");
    for(int i=0;i<n;i++)
        printf("%d  ",sorted[i]);

    return 0;
}
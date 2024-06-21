#include <string.h>
#include <stdio.h>
#define V 6

void main()
{
    int u, v, n, i, j, ne = 1;
    int visited[V] = {0}, min, minCost = 0;
    // int cost[V][V];
    // cost[0][0] = 0;
    // cost[0][1] = 5;
    // cost[0][2] = 2;
    // cost[0][3] = 3;
    // cost[1][0] = 5;
    // cost[1][1] = 0;
    // cost[1][2] = 9;
    // cost[1][3] = 7;
    // cost[2][0] = 2;
    // cost[2][1] = 9;
    // cost[2][2] = 0;
    // cost[2][3] = 1;
    // cost[3][0] = 3;
    // cost[3][1] = 7;
    // cost[3][2] = 1;
    // cost[3][3] = 0;
    int cost[V][V] = { {0, 2, 3, 0, 0, 0},
                       {2, 0, 5, 3, 4, 0},
                       {3, 5, 0, 0, 4, 0},
                       {0, 3, 0, 0, 2, 3},
                       {0, 4, 4, 2, 0, 5},
                       {0, 0, 3, 0, 0, 0} };
    // int cost[V][V] = {
    //     {0, 4, 0, 0, 0, 0, 0, 8, 0},
    //     {4, 0, 8, 0, 0, 0, 0, 11, 0},
    //     {0, 8, 0, 7, 0, 4, 0, 0, 2},
    //     {0, 0, 7, 0, 9, 14, 0, 0, 0},
    //     {0, 0, 0, 9, 0, 10, 0, 0, 0},
    //     {0, 0, 4, 14, 10, 0, 2, 0, 0},
    //     {0, 0, 0, 0, 0, 2, 0, 1, 6},
    //     {8, 11, 0, 0, 0, 0, 1, 0, 7},
    //     {0, 0, 2, 0, 0, 0, 6, 7, 0}
    // };
    int cost[V][V];
    cost[0][0] = 0;
    cost[0][1] = 3;
    cost[0][2] = 1;
    cost[0][3] = 6;
    cost[0][4] = 0;
    cost[0][5] = 0;

    cost[1][0] = 3;
    cost[1][1] = 0;
    cost[1][2] = 5;
    cost[1][3] = 0;
    cost[1][4] = 3;
    cost[1][5] = 0;

    cost[2][0] = 1;
    cost[2][1] = 5;
    cost[2][2] = 0;
    cost[2][3] = 5;
    cost[2][4] = 6;
    cost[2][5] = 4;

    cost[3][0] = 6;
    cost[3][1] = 0;
    cost[3][2] = 5;
    cost[3][3] = 0;
    cost[3][4] = 0;
    cost[3][5] = 2;

    cost[4][0] = 0;
    cost[4][1] = 3;
    cost[4][2] = 6;
    cost[4][3] = 0;
    cost[4][4] = 0;
    cost[4][5] = 6;

    cost[5][0] = 0;
    cost[5][1] = 0;
    cost[5][2] = 4;
    cost[5][3] = 2;
    cost[5][4] = 6;
    cost[5][5] = 0;

    for (int i = 1; i <= V; i++)
    {
        for (int j = 1; j <= V; j++)
            if (cost[i][j] == 0)
                cost[i][j] = 999;
    }

    visited[0] = 1;

    while (ne < V)
    {
        for (i = 1, min = 999; i <= V; i++)
        {
            for (j = 1; j <= V; j++)
            {
                if (cost[i][j] < min)
                {
                    if (visited[i] != 0)
                    {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        if (visited[u] == 0 || visited[v] == 0)
        {
            printf("\n Edge %d:{%d,%d} cost: %d", ne++, u, v, min);
            minCost += min;
            visited[v] = 1;
        }
        cost[u][v] = cost[v][u] = 999;
    }
    printf("\n Minimum Cost : %d", minCost);
}
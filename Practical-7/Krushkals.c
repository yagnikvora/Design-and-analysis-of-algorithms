#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define V 6

int i, j, k, a, b, u, v, ne = 1;
int min, mincost = 0, cost[V][V], perent[V];
int find(int i)
{
    while (perent[i])
    i = perent[i];
    return i;
}
int uni(int i, int j)
{
    if (i != j)
    {
        perent[j] = i;
        return 1;
    }
    return 0;
}
void main()
{
    int cost[V][V] = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}};
    // int cost[V][V] = {{0, 2, 3, 0, 0, 0},
    //                   {2, 0, 5, 3, 4, 0},
    //                   {3, 5, 0, 0, 4, 0},
    //                   {0, 3, 0, 0, 2, 3},
    //                   {0, 4, 4, 2, 0, 5},
    //                   {0, 0, 3, 0, 0, 0}};
    // int cost[V][V];
    // cost[0][0] = 0;
    // cost[0][1] = 4;
    // cost[0][2] = 4;
    // cost[0][3] = 0;
    // cost[0][4] = 0;
    // cost[0][5] = 0;
    // cost[1][0] = 4;
    // cost[1][1] = 0;
    // cost[1][2] = 2;
    // cost[1][3] = 0;
    // cost[1][4] = 0;
    // cost[1][5] = 0;
    // cost[2][0] = 4;
    // cost[2][1] = 2;
    // cost[2][2] = 0;
    // cost[2][3] = 3;
    // cost[2][4] = 4;
    // cost[2][5] = 0;
    // cost[3][0] = 0;
    // cost[3][1] = 0;
    // cost[3][2] = 3;
    // cost[3][3] = 0;
    // cost[3][4] = 3;
    // cost[3][5] = 0;
    // cost[4][0] = 0;
    // cost[4][1] = 0;
    // cost[4][2] = 4;
    // cost[4][3] = 3;
    // cost[4][4] = 0;
    // cost[4][5] = 0;
    // cost[5][0] = 0;
    // cost[5][1] = 0;
    // cost[5][2] = 2;
    // cost[5][3] = 0;
    // cost[5][4] = 3;
    // cost[5][5] = 0;

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

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
            if (cost[i][j] == 0)
                cost[i][j] = 999;
    }
    while (ne < V)
    {
        for (i = 0, min = 999; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = find(u);
        v = find(v);
        if (uni(u, v))
        {
            printf("Edge %d: {%d,%d} cost : %d\n", ne++, a, b, min);
            mincost += min;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    printf("Minimum Cost : %d\n", mincost);
}
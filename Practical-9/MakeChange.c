#include <stdio.h>
int coins[9] = {1, 2, 5, 10, 20, 50, 100, 200, 500};
void minCost(int cost)
{
    int i, k = 0;
    int minCost[20] = {0};
    for (i = 8; i >= 0; i--)
    {
        while (cost >= coins[i])
        {
            cost -= coins[i];
            minCost[k++] = coins[i];
        }
    }

    for (i = 0; i < k; i++)
        printf("%d,",minCost[i]);
}
void main()
{
    int n;
    printf("Enter Total cost : ");
    scanf("%d", &n);
    minCost(n);
}
#include <stdio.h>
int lcs(char X[], char Y[], int m, int n)
{
    int L[m + 1][n + 1], i, j;
    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = (L[i - 1][j] > L[i][j - 1]) ? L[i - 1][j] : L[i][j - 1];
        }
    }
    return L[m][n];
}
int main()
{
    char S1[] = "yagnik";
    char S2[] = "vorayagnikss";
    int m = sizeof(S1);
    int n = sizeof(S2);
    printf("Length of LCS is %d", (lcs(S1, S2, m, n) - 1));
    return 0;
}

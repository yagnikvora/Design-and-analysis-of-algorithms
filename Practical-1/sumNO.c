#include <stdio.h>
#include<time.h>
int main()
{
    long long a = 0;
    int i, n;
    double CPU_time = 0.0;
    clock_t s;
    clock_t e;
    printf("Enter N : ");
    scanf("%d", &n);
    s = clock();
    for (i = 1; i <= n; i++)
    {
        a = a + i;
    }
    e = clock();
    printf("Sum : %lld", a);
    CPU_time = (double)(e - s) / CLOCKS_PER_SEC;
    printf("\nTime : %lf", CPU_time);
    return 0;
}

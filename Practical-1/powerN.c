#include <stdio.h>
#include <time.h>
int main()
{
    long long a = 1;
    int i, b, p;
    double CPU_time = 0.0;
    clock_t s;
    clock_t e;
    printf("Enter Base : ");
    scanf("%d", &b);
    printf("Enter Power : ");
    scanf("%d", &p);
    s = clock();
    for (i = 1; i <= p; i++)
    {
        a = a * b;
    }
    e = clock();
    printf("Power : %lld", a);
    CPU_time = (double)(e - s) / CLOCKS_PER_SEC;
    printf("\nTime : %lf", CPU_time);
    return 0;
}

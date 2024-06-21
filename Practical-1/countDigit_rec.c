#include <stdio.h>
#include <time.h>
int cont(long long);
int c = 0;
int main()
{
    long long n;
    double CPU_time = 0.0;
    clock_t s;
    clock_t e;

    printf("Enter N : ");
    scanf("%lld", &n);
    s = clock();
    cont(n);
    e = clock();
    printf("Count : %d", c);

    CPU_time = (double)(e - s) / CLOCKS_PER_SEC;
    printf("\nTime : %lf", CPU_time);
    return 0;
}
int cont(long long a)
{
    if (a > 0)
    {
        c++;
        return cont(a / 10);
    }
}
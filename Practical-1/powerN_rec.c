#include <stdio.h>
#include <time.h>
long long powN(int,int);
int main()
{
    int b,p;
    double CPU_time = 0.0;
    clock_t s;
    clock_t e;

    printf("Enter Base : ");
    scanf("%d", &b);
    printf("Enter Power : ");
    scanf("%d", &p);

    s = clock();
    long long f = powN(b,p);
    e = clock();
    printf("Power : %lld", f);

    CPU_time = (double)(e - s) / CLOCKS_PER_SEC;
    printf("\nTime : %lf", CPU_time);
    return 0;
}
long long powN(int a,int b)
{
    if (b == 0)
    {
        return 1;
    }
    else
    {
        return (a * powN(a,b - 1));
    }
}
#include <stdio.h>
#include <time.h>
int main()
{
    int i = 0;
    long long n, temp;
    double CPU_time = 0.0;
    clock_t s;
    clock_t e;
    printf("Enter N : ");
    scanf("%lld", &n);
    temp = n;
    s = clock();
    while(temp>0){
        temp = temp/10;
        i++;
    }
    e = clock();
    printf("Count : %d", i);
    CPU_time = (double)(e - s) / CLOCKS_PER_SEC;
    printf("\nTime : %lf", CPU_time);
    return 0;
}

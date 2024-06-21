// #include <stdio.h>
// #include <time.h>
// int main()
// {
//     int n,i;
//     long long fact=1;
//     double CPU_time = 0.0;
//     clock_t s;
//     clock_t e;

//     printf("Enter N : ");
//     scanf("%d", &n);
//     s = clock();
//     for(i=1;i<=n;i++){
//         fact *= i;
//     }
//     e = clock();
//     printf("Factorial : %lld", fact);
//     CPU_time = (double)(e - s) / CLOCKS_PER_SEC;
//     printf("\nTime : %lf", CPU_time);
//     return 0;
// }

#include <stdio.h>
#include <time.h>

void main()
{
    int a[100000], n, counter=0, temp, i;
    a[0] = 1;
    double CPU_time = 0.0;
    clock_t s;
    clock_t e;
    printf("Enter the number to Find Factorial: ");
    scanf("%d", &n);
    s = clock();

    for (; n >= 2; n--)
    {
        temp = 0;
        for (i = 0; i <= counter; i++)
        {
            temp = (a[i] * n) + temp;
            a[i] = temp % 10;
            temp = temp / 10;
        }
        while (temp > 0)
        {
            a[++counter] = temp % 10;
            temp = temp / 10;
        }
    }
    e = clock();

    for (i = counter; i >= 0; i--)
        printf("%d", a[i]);
        
    CPU_time = (double)(e - s) / CLOCKS_PER_SEC;
    printf("\nTime : %lf", CPU_time);
}
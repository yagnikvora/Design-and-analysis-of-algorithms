// #include <stdio.h>
// #include<time.h>
// long long fact(int);
// int main()
// {
//     int n;
//     double CPU_time = 0.0;
//     clock_t s;
//     clock_t e;

//     printf("Enter N : ");
//     scanf("%d", &n);
//     s = clock();
//     long long f = fact(n);
//     e = clock();
//     printf("Factorial : %lld", f);
//     CPU_time = (double)(e-s)/CLOCKS_PER_SEC;
//     printf("\nTime : %ld",CPU_time);
//     return 0;
// }
// long long fact(int a){
//     if(a == 1){
//         return 1;
//     }
//     else{
//         return (a * fact(a-1));
//     }
// }

#include <stdio.h>
#include <time.h>
void multiply(int a[], int n, int *counter)
{
    int temp = 0;
    for (int i = 0; i <= *counter; i++)
    {
        temp = (a[i] * n) + temp;
        a[i] = temp % 10;
        temp = temp / 10;
    }
    while (temp > 0)
    {
        a[++(*counter)] = temp % 10;
        temp = temp / 10;
    }
}
void factorialRecursive(int a[], int n, int *counter)
{
    if (n >= 2)
    {
        multiply(a, n, counter);
        factorialRecursive(a, n - 1, counter);
    }
}
int main()
{
    int a[100000], n, counter = 0;
    a[0] = 1;
    double CPU_time = 0.0;
    clock_t start, end;
    printf("Enter the number to find factorial: ");
    scanf("%d", &n);
    start = clock();
    factorialRecursive(a, n, &counter);
    end = clock();
    printf("Factorial of %d is: ", n);
    for (int i = counter; i >= 0; i--)
        printf("%d", a[i]);
    CPU_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nTime: %lf", CPU_time);
    return 0;
}

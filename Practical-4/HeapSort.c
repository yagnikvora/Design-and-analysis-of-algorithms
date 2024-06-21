#include <stdio.h>
#include <time.h>
void maxHipify(int[], int, int);

void maxHipify(int a[], int n, int i)
{
    int large = i;
    int l = i * 2 + 1;
    int r = i * 2 + 2;

    if (l < n && a[l] > a[large])
        large = l;

    if (r < n && a[r] > a[large])
        large = r;

    if (large != i)
    {
        int temp = a[large];
        a[large] = a[i];
        a[i] = temp;
        maxHipify(a, n, large);
    }
}

void main()
{
    int i, j,len;
    int a[10];
    long n = sizeof(a) / sizeof(a[0]);
    double CPU_time = 0.0;
    clock_t s;
    clock_t e;
    FILE *fp;

    printf("\n----------Best Case------------");
    fp = fopen("best.txt", "r");
    for (i = 0; i < n; i++)
    {
        fscanf(fp, "%d", &a[i]);
    }
    s = clock();
    // Sorting Logic
    len = n;
    for (i = (len / 2) - 1; i >= 0; i--)
        maxHipify(a, len, i);
    for (i = len - 1; i >= 0; i--)
    {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        maxHipify(a, i, 0);
    }
    
    e = clock();

    CPU_time = (double)(e - s) / CLOCKS_PER_SEC;
    printf("\nTime : %lf", CPU_time);

    printf("\n----------Avarage Case------------");
    fp = fopen("avg.txt", "r");
    for (i = 0; i < n; i++)
    {
        fscanf(fp, "%d", &a[i]);
    }

    s = clock();
    len = n;
    for (int i = (len / 2) - 1; i >= 0; i--)
        maxHipify(a, len, i);
    for (int i = len - 1; i >= 0; i--)
    {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        maxHipify(a, i, 0);
    }
    e = clock();
    CPU_time = (double)(e - s) / CLOCKS_PER_SEC;
    printf("\nTime : %lf", CPU_time);

    printf("\n----------Worst Case------------");
    fp = fopen("worst.txt", "r");
    for (i = 0; i < n; i++)
    {
        fscanf(fp, "%d", &a[i]);
    }

    s = clock();
    len = n;
    for (int i = (len / 2) - 1; i >= 0; i--)
        maxHipify(a, len, i);
    for (int i = len - 1; i >= 0; i--)
    {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        maxHipify(a, i, 0);
    }
    e = clock();
    CPU_time = (double)(e - s) / CLOCKS_PER_SEC;
    printf("\nTime : %lf", CPU_time);
    fclose(fp);
}
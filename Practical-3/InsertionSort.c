#include <stdio.h>
#include <time.h>

void main()
{
    int i, j;
    int a[100000];
    int n = sizeof(a) / sizeof(a[0]);
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
    for (i = 1; i < n; i++)
    {
        j = i - 1;
        int temp = a[i];
        while (j >= 0 && a[j] > temp)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
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

    for (i = 1; i < n; i++)
    {
        j = i - 1;
        int temp = a[i];
        while (j >= 0 && a[j] > temp)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
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

    for (i = 1; i < n; i++)
    {
        j = i - 1;
        int temp = a[i];
        while (j >= 0 && a[j] > temp)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }

    e = clock();
    CPU_time = (double)(e - s) / CLOCKS_PER_SEC;
    printf("\nTime : %lf", CPU_time);
    fclose(fp);
}
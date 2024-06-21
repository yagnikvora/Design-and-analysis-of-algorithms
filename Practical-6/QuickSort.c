#include <stdio.h>
#include <time.h>
int part(int a[], int lb, int ub)
{

    int start = lb;
    int end = ub;
    int pivot = a[start];
    while (start < end)
    {
        while (start <= ub && a[start] <= pivot)
        {
            start++;
        }
        while (end >= 0 && a[end] > pivot)
        {
            end--;
        }
        if (start < end)
        {
            int temp = a[start];
            a[start] = a[end];
            a[end] = temp;
        }
    }
    int temp = a[end];
    a[end] = a[lb];
    a[lb] = temp;
    return end;
}
void sort(int a[], int lb, int ub)
{
    if (lb < ub)
    {
        int mid = part(a, lb, ub);
        sort(a, lb, mid - 1);
        sort(a, mid + 1, ub);
    }
}
void main()
{
    int i, j, flag = 1;
    int a[40000];
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
    sort(a, 0, n - 1);
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
    sort(a, 0, n-1);
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
    sort(a, 0, n-1);
    e = clock();
    CPU_time = (double)(e - s) / CLOCKS_PER_SEC;
    printf("\nTime : %lf", CPU_time);
    fclose(fp);
}
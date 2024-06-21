#include <stdio.h>
#include <time.h>
int b_search(int a[], int val, int lb, int ub)
{
    if (lb > ub)
        return -1;
    int mid = (lb + ub) / 2;
    if (a[mid] == val)
        return mid;
    else if (a[mid] > val)
        return b_search(a, val, lb, mid - 1);
    else
        return b_search(a, val, mid + 1, ub);        
}

void main()
{
    int i, se, f = 0, mid;
    int a[500000];
    int n = sizeof(a) / sizeof(a[0]);
    double CPU_time = 0.0;
    clock_t s;
    clock_t e;
    FILE *fp;

    fp = fopen("best.txt", "r");
    for (i = 0; i < n; i++)
        fscanf(fp, "%d", &a[i]);        

    printf("Enter element to search : ");
    scanf("%d", &se);

    s = clock();
    int index = b_search(a, se, 0, n-1);
    e = clock();

    if (index == -1)
        printf("Element not found\n");
    else
        printf("Element %d is present at index %d\n", se, index);

    CPU_time = (double)(e - s) / CLOCKS_PER_SEC;
    printf("\nTime : %lf", CPU_time);
    fclose(fp);
}
#include <stdio.h>
#include <time.h>

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
    // Search Logic
    int lb = 0;
    int ub = n - 1;
    while (lb <= ub)
    {
        mid = (lb + ub) / 2;
        if (a[mid] == se)
        {
            f = 1;
            break;
        }
        else if (a[mid] < se)
            lb = mid + 1;
        else
            ub = mid - 1;
    }
    if (f == 1)
        printf("Element found at index : %d\n", mid);
    else
        printf("Element not found");
    
    e = clock();
    CPU_time = (double)(e - s) / CLOCKS_PER_SEC;
    printf("\nTime : %lf", CPU_time);
    fclose(fp);
}
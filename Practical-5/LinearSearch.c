#include <stdio.h>
#include <time.h>

void main()
{
    int i, se, f=0;
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
    for (i = 0; i < n; i++)
    {
        if (a[i] == se)
        {
            f = 1;
            break;
        }
    }
    if (f == 1)
        printf("Element found at index %d\n", i);
    else
        printf("Element not found");

    e = clock();
    CPU_time = (double)(e - s) / CLOCKS_PER_SEC;
    printf("\nTime : %lf", CPU_time);
    fclose(fp);
}
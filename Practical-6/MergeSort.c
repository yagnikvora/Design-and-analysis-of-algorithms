#include <stdio.h>
#include <time.h>

#define S 100000
int b[S];
int merge(int a[], int lb,int mid, int ub)
{
    int i = lb;
    int j = mid + 1;
    int k = lb;
    while(i<=mid && j<=ub) {
        if(a[i] <= a[j]) 
            b[k++] = a[i++];
        else 
            b[k++] = a[j++];
    }
    if(i>mid){
        while(j<=ub)
            b[k++] = a[j++];
    }else{
        while(i<=mid)
            b[k++] = a[i++];
    }
    for(int y = 0;y<k;y++){
        a[y] = b[y];
    }

}
void sort(int a[], int lb, int ub)
{
    if (lb < ub)
    {
        int mid = (lb + ub) / 2;
        sort(a, lb, mid);
        sort(a, mid + 1, ub);
        merge(a, lb, mid, ub);
    }
}
void main()
{
    int i, j, flag = 1;
    int a[S];
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
    sort(a, 0, n - 1);
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
    sort(a, 0, n - 1);
    e = clock();
    CPU_time = (double)(e - s) / CLOCKS_PER_SEC;
    printf("\nTime : %lf", CPU_time);
    fclose(fp);
}
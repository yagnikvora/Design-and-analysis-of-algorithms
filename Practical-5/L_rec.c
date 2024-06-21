#include <stdio.h>
#include <time.h>
int l_search(int a[],int n,int s,int val){
    if(s>n){
        if(a[n] == val)
            return n;  
        else
            return l_search(a,n+1,s,val); 
    }else
        return -1;
}
void main()
{
    int i, se, f = 0;
    int a[50000];
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
    int index = l_search(a,0,n,se);
    e = clock();

    if (index == -1)
        printf("Element not found\n");
    else
        printf("Element %d is present at index %d\n", se, index);

    CPU_time = (double)(e - s) / CLOCKS_PER_SEC;
    printf("\nTime : %lf", CPU_time);
    fclose(fp);
}
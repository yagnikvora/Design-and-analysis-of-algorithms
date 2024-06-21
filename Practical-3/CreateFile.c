#include<stdio.h>
#include<stdlib.h>
void main()
{
    int i;
    FILE *fp;
    fp = fopen("best.txt", "w");
    for (i = 1; i <= 500000; i++)
        fprintf(fp, "%d\n", i);

    fp = fopen("worst.txt", "w");
    for (i = 500000; i >= 1; i--)
        fprintf(fp, "%d\n", i);
    
    fp = fopen("avg.txt", "w");
    for (i = 1; i <= 500000; i++)
        fprintf(fp, "%d\n", rand());
        
    fclose(fp);
}
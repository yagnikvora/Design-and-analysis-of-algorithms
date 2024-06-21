#include <stdio.h>
#define size 7
int q[size], front = -1,rear= -1;
void enQueue(int);
void deQueue();
void display();

void main()
{
    int c,val;
    printf("1.Insert\n2.Delete\n3.Display\nEnter Choice : ");
    scanf("%d", &c);
    while (c <= 3)
    {
        switch (c)
        {
        case 1:
            printf("Enter Value : ");
            scanf("%d", &val);
            enQueue(val);
            break;
        case 2:
            deQueue();
            break;
        case 3:
            display();
            break;
        default:
            printf("Enter Valid choice\n\n");
            break;
        }
        printf("1.Insert\n2.Delete\n3.Display\nEnter Choice : ");
        scanf("%d", &c);
    }
}

void enQueue(int val)
{
    if (rear >= size - 1)
        printf("Queue Overflow\n\n");
    else{    
        q[++rear] = val;
    }
    if(front == -1)
        front = 0;
}

void deQueue()
{
    if (front == -1)
        printf("Queue is Underflow\n");
    else
        printf("Deleted Value : %d\n\n", q[front++]);
}

void display()
{
    int i;
    for (i = front; i <= rear; i++)
        printf("%d,", q[i]);
    printf("\n");
}
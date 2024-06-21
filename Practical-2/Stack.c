#include <stdio.h>
#define size 7
int s[size], top = -1;
void push(int);
void pop();
void display();
void change(int, int);
void peep(int);

void main()
{
    int c, val, pos;
    printf("1.PUSH\n2.POP\n3.CHANGE\n4.PEEP\n5.DISPLAY\nEnter Choice : ");
    scanf("%d", &c);
    while (c <= 5)
    {
        switch (c)
        {
        case 1:
            printf("Enter Value : ");
            scanf("%d", &val);
            push(val);
            break;
        case 2:
            pop();
            break;
        case 3:
            printf("Enter Value : ");
            scanf("%d", &val);
            printf("Enter Position : ");
            scanf("%d", &pos);
            change(val, pos);
            printf("Value changed\n\n");
            break;
        case 4:
            printf("Enter Position : ");
            scanf("%d", &pos);
            peep(pos);
            break;
        case 5:
            display();
            break;
        default:
            printf("Enter Valid choice\n\n");
            break;
        }
        printf("\n1.PUSH\n2.POP\n3.CHANGE\n4.PEEP\n5.DISPLAY\nEnter Choice : ");
        scanf("%d", &c);
    }
}

void push(int val)
{
    if (top == size - 1)
        printf("Stack Overflow\n\n");
    else
        s[++top] = val;
}

void pop()
{
    if (top == -1)
        printf("Stack is Underflow\n");
    else
        printf("Deleted Value : %d\n\n",s[top--]);
}

void change(int val, int pos)
{
    if (top - pos + 1 <= -1)
        printf("Stack Underflow\n\n");
    else
        s[top - pos + 1] = val;
}
void peep(int pos)
{
    if (top - pos + 1 <= -1)
        printf("Stack Underflow\n\n");
    else
        printf("value at %d : %d\n\n", pos, s[top - pos + 1]);
}
void display()
{
    int i;
    for (i = 0; i <= top; i++)
        printf("%d,", s[i]);
    printf("\n");
}
#include <stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

void insert(int);
void delete();
void display();

struct Node *first = NULL;

void main()
{
    int c, val;
    printf("1.Insert\n2.Delete\n3.Display\nEnter Choice : ");
    scanf("%d", &c);
    while (c <= 3)
    {
        switch (c)
        {
        case 1:
            printf("Enter Value : ");
            scanf("%d", &val);
            insert(val);
            break;
        case 2:
            delete();
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

void insert(int val)
{
    struct Node *new_Node = malloc(sizeof(struct Node));
    new_Node->data = val;
    new_Node->next = NULL;
    if (first == NULL)
        first = new_Node;
    else
    {
        struct Node* save = first;
        while(save->next != NULL)
            save = save->next;
        save->next = new_Node;
    }
}

void delete()
{
    if(first == NULL){
        printf("Linked List is empty...\n");
    }else{
        struct Node* save = first;
        struct Node* ptr = first;

        while (save->next != NULL)
        {
            ptr = save;
            save = save->next;
        }
        ptr->next = NULL;
        printf("Node with data %d is deleted\n", save->data);
        free(save);
    }
}

void display()
{
    if(first == NULL){
        printf("Underflow");
    }else{
        struct Node* save = first;
        while (save->next != NULL)
        {
            printf("%d,", save->data);
            save = save->next;
        }
        printf("%d,", save->data);
        printf("\n\n");
    }
}
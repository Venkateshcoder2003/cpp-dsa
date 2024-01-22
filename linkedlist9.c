#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} NODE;
static int count = 0;
NODE *INSERT(NODE *head, int data)
{
    NODE *newnode, *temp;
    newnode = (NODE *)malloc(sizeof(NODE));
    newnode->data = data;
    newnode->next = NULL;
    printf("\n%d Is Pushed To Stack", data);
    temp = head;
    if (head == NULL)
        head = temp = newnode;
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    return head;
}
NODE *DELETE(NODE *head)
{
    if (head == NULL)
    {
        printf("\nStack Is empty(STACK UNDERFLOW)");
    }
    else
    {
        NODE *temp = head;
        printf("\nThe Top Of The Stack %d Is Popped From Top Of The Stack", head->data);
        head = head->next;
        free(temp);
        count--;
    }
    return head;
}
void DISPLAY(NODE *head)
{
    NODE *temp = head;
    if (head == NULL)
    {
        printf("\nQUEUE Is Empty Cannot Display Elements");
    }

    else
    {
        printf("BEGIN->");
        while (temp != NULL)
        {
            printf("%d->", temp->data);
            temp = temp->next;
        }
        printf("END\n");
    }
}

int main()
{
    int choice, data;
    NODE *head = NULL;

    while (1)
    {
        printf("\n1:INSERT\n2:DELETE\n3:DISPLAY\n4:EXIT\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter The Data To Be Inserted Into Queue: ");
            scanf("%d", &data);
            head = INSERT(head, data);
            break;
        case 2:
            head = DELETE(head);
            break;

        case 3:
            DISPLAY(head);
            break;
        case 4:
            exit(0);
        default:
            printf("\nInvalid Choice");
        }
    }
}

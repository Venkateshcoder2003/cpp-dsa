#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} NODE;
static int count = 0;
NODE *PUSH(NODE *head, int data)
{
    NODE *newnode;
    newnode = (NODE *)malloc(sizeof(NODE));
    count++;
    newnode->data = data;
    newnode->next = head;
    printf("\n%d Is Pushed Onto The Stack", data);
    return newnode;
}
NODE *POP(NODE *head)
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
NODE *PEEK(NODE *head)
{
    if (head == NULL)
    {
        printf("\nStack Is Empty");
    }
    else
    {
        NODE *temp = head;
        printf("\nTop Of The Stack Is %d", temp->data);
    }
    return head;
}
void DISPLAY(NODE *head)
{
    NODE *temp = head;
    if (head == NULL)
    {
        printf("\nSTACK Is Empty Cannot Display Elements");
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
        printf("\n1:PUSH\n2:POP\n3:PEEK\n4:DISPLAY\n5:EXIT\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter The Data To Push Into The Stack: ");
            scanf("%d", &data);
            head = PUSH(head, data);
            break;
        case 2:
            head = POP(head);
            break;
        case 3:
            head = PEEK(head);
            break;
        case 4:
            DISPLAY(head);
            break;
        case 5:
            exit(0);
        default:
            printf("\nInvalid Choice");
        }
    }
}
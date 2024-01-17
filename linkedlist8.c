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
    NODE *newnode;
    newnode = (NODE *)malloc(sizeof(NODE));
    count++;
    newnode->data = data;
    newnode->next = head;
    printf("\n%d Is Inserted Into The QUEUE", data);
    return newnode;
}
NODE *DELETE(NODE *head)
{
    NODE *temp, *prev_node;
    if (head == NULL)
        printf("\nQUEUE IS Empty\n");
    else
    {
        temp = head;
        if (temp->next == NULL)
        {
            head = NULL;
            free(temp);
        }
        else
        {
            while (temp->next != NULL)
            {
                prev_node = temp;
                temp = temp->next;
            }
            printf("\n%d Is Removed From The QUEUE \n", temp->data);
            prev_node->next = NULL;
            free(temp);
        }
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

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} NODE;
static int count = -1;
NODE *INSERT_BEGIN(NODE *head, int data)
{
    NODE *newnode;
    newnode = (NODE *)malloc(sizeof(NODE));
    count++;
    newnode->data = data;
    newnode->next = head;

    return newnode;
}
NODE *INSERT_END(NODE *head, int data)
{
    NODE *newnode, *temp;
    newnode = (NODE *)malloc(sizeof(NODE));
    count++;
    newnode->data = data;
    newnode->next = NULL;
    temp = head;
    if (head == NULL)
        head = temp = newnode;
    else
    {
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
    return head;
}
NODE *INSERT_MIDDLE(NODE *head, int pos)
{
    NODE *newnode, *temp;
    int i = 0, data;
    newnode = (NODE *)malloc(sizeof(NODE));
    count++;
    temp = head;
    if (pos > count)
    {
        printf("\nInvalid Position Entered ");
        return;
    }
    else
    {
        while (i < pos)
        {
            temp = temp->next;
            i++;
        }
        newnode = (NODE *)malloc(sizeof(NODE));
        printf("\nEnter The Data: ");
        scanf("%d", &data);
        newnode->data = data;
        newnode->next = temp->next;
        temp->next = newnode;
    }
    return head;
}
void DISPLAY(NODE *head)
{
    NODE *temp;
    temp = head;
    if (count < 0)
    {
        printf("No Elements In Linked List To Display");
        return;
    }

    else
    {
        printf("\nBEGIN->");
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
    int choice, data, pos;
    NODE *head = NULL;
    while (1)
    {
        printf("\n1:INSERT@BEGIN\n2:INSERT@END\n3:INSERT@MIDDLE\n4:DISPLAY\n5:EXIT");
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter The Data To Be Inserted At Beginning: ");
            scanf("%d", &data);
            head = INSERT_BEGIN(head, data);
            break;
        case 2:
            printf("Enter The Data To be Inserted At Last: ");
            scanf("%d", &data);
            head = INSERT_END(head, data);
            break;
        case 3:
            printf("Enter The Position: \n");
            scanf("%d", &pos);
            head = INSERT_MIDDLE(head, pos);
            break;
        case 4:
            DISPLAY(head);
            break;
        case 5:
            exit(0);
        default:
            printf("INVALID CHOICE");
        }
    }
    break;
}
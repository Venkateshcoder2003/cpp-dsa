#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} NODE;
static int count = 0;

NODE *CREATE_LINKED_LIST(NODE *head, int data)
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
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    return head;
}

NODE *search(NODE *head)
{
    NODE *temp;
    int key;
    printf("\nEnter The Key Element To Be Searched: ");
    scanf("%d", &key);

    if (head == NULL)
    {
        printf("\nLinked List Is Empty,Cannot Search The Entered Element");
    }
    else
    {
        temp = head;
        int i = 1;
        while (temp != NULL)
        {
            if (key == temp->data)
            {
                printf("\nThe Key %d Is Fount At %dth NODE", key, i);
                return head;
            }
            i++;
            temp = temp->next;
        }
        printf("\nThe Key %d Is NOt Present In Linked List", key);
    }
    return head;
}
NODE *DISPLAY(NODE *head)
{
    NODE *temp;
    temp = head;
    if (head == NULL)
    {
        printf("No Elements In Linked List To Display");
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
    return head;
}
int main()
{
    int choice, data;
    NODE *head = NULL;

    while (1)
    {
        printf("\n1:CREATE_LINKED_LIST\n2:SEARCH\n3:DISPLAY\n4:EXIT\n");
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter The Data To add I Linked List: ");
            scanf("%d", &data);
            head = CREATE_LINKED_LIST(head, data);
            break;
        case 2:
            head = search(head);
            break;
        case 3:
            head = DISPLAY(head);
            break;
        case 4:
            exit(0);
        default:
            printf("\nInvalid Choice");
        }
    }
}
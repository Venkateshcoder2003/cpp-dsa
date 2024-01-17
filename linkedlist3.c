#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} NODE;
static int count = 0;
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
NODE *DELETE_BEGINNING(NODE *head)
{
    if (count == -1 || head == NULL)
    {
        printf("\nLinked List Is Empty");
    }
    else
    {
        NODE *temp = head;
        head = head->next;
        free(temp);
        count--;
    }
    return head;
}
NODE *DELETE_END(NODE *head)
{
    int temp_count = 0, i = 0;
    NODE *temp, *temp1;
    if (count == 0 || head == NULL)
    {
        printf("Linked List Is Empty Cannot Delete Elements");
    }
    else
    {
        NODE *prev_node;
        temp = head;
        while (temp->next != NULL)
        {
            prev_node = temp;
            temp = temp->next;
        }

        if (temp == head)
        {
            head = NULL;
            free(temp);
            count--;
        }
        else
        {
            prev_node->next = NULL;
            free(temp);
            count--;
        }
    }
    return head;
}
void DISPLAY(NODE *head)
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
}

int main()
{
    int choice, data, pos;
    NODE *head = NULL;
    while (1)
    {
        printf("\n1:INSERT@BEGIN\n2:INSERT@END\n3:DELETE@BEGIN\n4:DELETE@END\n5:DISPLAY\n6:EXIT\n");
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
            head = DELETE_BEGINNING(head);
            break;
        case 4:
            head = DELETE_END(head);
            break;
        case 5:
            DISPLAY(head);
            break;
        case 6:
            exit(0);
        default:
            printf("INVALID CHOICE");
        }
    }
    return 0;
}
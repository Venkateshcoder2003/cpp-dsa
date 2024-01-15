#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} NODE;
static int count = 0;
void DISPLAY(NODE *head)
{
    int i = 0;
    if (head == NULL)
    {
        printf("No Elements To Display In Linked List");
    }
    else
    {
        NODE *temp = head;
        printf("\nBEGIN->");
        while (i < count)
        {
            printf("%d->", temp->data);
            temp = temp->next;
            i++;
        }
        printf("END\n");
    }
}
NODE *CREATE_LIST(NODE *head, int data)
{
    NODE *newnode;
    NODE *temp = head;
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
NODE *REVERSE_LIST(NODE *head)
{
    NODE *prev_node = 0, *curr_node = head, *next_node = head;
    if (head == NULL)
    {
        printf("\nLinked List Is Empty,No Elements To Reverse");
        return head;
    }
    else
    {
        while (next_node != NULL)
        {
            next_node = next_node->next;
            curr_node->next = prev_node;
            prev_node = curr_node;
            curr_node = next_node;
        }
        head = prev_node;
        // DISPLAY(head);
    }
    printf("*****Reversing Successfull You Can Call Display Function Now By Pressing 3*****\n");
    return head;
}
int main()
{
    int choice, data;
    NODE *head = NULL;
    while (1)
    {
        printf("\n1:CREATE_LIST\n2:REVERSE_LIST\n3:DISPLAY\n4:EXIT\n");
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter The Data To be Added To The List: ");
            scanf("%d", &data);
            head = CREATE_LIST(head, data);
            break;
        case 2:
            head = REVERSE_LIST(head);
            break;
        case 3:
            DISPLAY(head);
            break;
        case 4:
            free(head);
            exit(0);
        default:
            printf("\nInvalid Choice");
        }
    }
}
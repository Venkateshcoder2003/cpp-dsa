// PRIORITY QUEUE USING LINKED LIST WHERE ELEMENTS ARE ITSELF PRIORITIES
// HERE PRIORITY ORDER IS:-SMALLER THE NUMBER HIGHER THE PRIORITY AND IT WILL BE DELETED FIRST
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} NODE;
NODE *INSERT(NODE *head, int data)
{
    NODE *newnode;
    newnode = (NODE *)malloc(sizeof(NODE));
    newnode->data = data;
    if (head == NULL || data <= head->data)
    {
        newnode->next = head;
        head = newnode;
    }
    else
    {
        NODE *temp = head, *p_node = NULL;
        while (temp != NULL && data >= temp->data)
        {
            p_node = temp;
            temp = temp->next;
        }
        p_node->next = newnode;
        newnode->next = temp;
    }
    printf("%d Data Is Added to Priority Queue!", data);
    return head;
}
NODE *DELETE(NODE *head)
{
    if (head == NULL)
    {
        printf("\nQueue Is Empty");
    }
    else
    {
        NODE *temp = head;
        printf("The Data %d had Highest Priority and Is Deleted From Queue", temp->data);
        head = head->next;
        free(temp);
    }
    return head;
}
NODE *DISPLAY(NODE *head)
{
    if (head == NULL)
    {
        printf("\nQueue is Empty");
    }
    else
    {
        NODE *temp = head;
        printf("FRONT->");
        while (temp != NULL)
        {
            printf("%d->", temp->data);
            temp = temp->next;
        }
        printf("REAR\n");
    }
    return head;
}
int main()
{
    NODE *head = NULL;
    int data, choice;
    while (1)
    {
        printf("\n1:INSERT\n2:DELETE\n3:DISPLAY\n4:EXIT\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)

        {
        case 1:
            printf("Enter Data To be Inserted Into Priority Queue: \n");
            scanf("%d", &data);
            head = INSERT(head, data);
            break;
        case 2:
            head = DELETE(head);
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
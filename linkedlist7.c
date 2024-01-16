#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} NODE;

NODE *PUSH(NODE *head, int data)
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
NODE *POP(NODE *head)
{
    NODE *temp, *prev_node;
    if (head == NULL)
        printf("\nStack IS Empty\n");
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
            printf("\n%d Is Removed From The Top Of The Stack \n", temp->data);
            prev_node->next = NULL;
            free(temp);
        }
    }
    return head;
}
NODE *PEEK(NODE *head)
{
    NODE *temp, *prev_node;
    if (head == NULL)
        printf("\nStack IS Empty\n");

    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        printf("\nTop Of The Stack Is: %d", temp->data);
    }
    return head;
}
void DISPLAY(NODE *head)
{
    if (head == NULL)
        printf("\nStack IS Empty\n");

    else
    {
        NODE *temp = head;
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
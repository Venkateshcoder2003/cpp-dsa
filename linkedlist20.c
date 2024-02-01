

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} NODE;

NODE *INSERT_LAST(NODE *head, int data)
{
    NODE *newnode;
    newnode = (NODE *)malloc(sizeof(NODE));
    newnode->data = data;
    newnode->next = NULL;
    NODE *temp = head;
    if (head == NULL)
    {
        head = temp = newnode;
    }
    else
    {
        NODE *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    return head;
}
NODE *CREATE_LIST(NODE *head, int data)
{
    NODE *newnode;
    NODE *prev_node = NULL;
    newnode = (NODE *)malloc(sizeof(NODE));
    newnode->data = data;

    if (head == NULL || data < head->data)
    {
        newnode->next = head;
        head = newnode;
    }
    else
    {
        NODE *temp = head;
        while (temp != NULL && data > temp->data)
        {
            prev_node = temp;
            temp = temp->next;
        }
        if (temp == NULL || data != temp->data)
        {
            prev_node->next = newnode;
            newnode->next = temp;
        }
        return head;
    }
}

NODE *display(NODE *head)
{
    if (head == NULL)
    {
        printf("The Current list Empty");
        return head;
    }
    else
    {

        NODE *temp = head;
        printf("\nBEGIN->");
        while (temp != NULL)
        {
            printf("%d->", temp->data);
            temp = temp->next;
        }
        printf("END");
    }
    return head;
}

NODE *merge(NODE *first, NODE *second, NODE *third)
{
    if (first == NULL && second == NULL)
    {
        printf("Lists Are Empty\n");
        return NULL;
    }
    while (first != NULL && second != NULL)
    {
        if (first->data < second->data)
        {
            third = CREATE_LIST(third, first->data);
            first = first->next;
        }
        else if (first->data > second->data)
        {
            third = CREATE_LIST(third, second->data);
            second = second->next;
        }
        else
        {
            third = CREATE_LIST(third, first->data);
            second = second->next;
            first = first->next;
        }
    }

    while (first != NULL)
    {
        third = CREATE_LIST(third, first->data);
        first = first->next;
    }
    while (second != NULL)
    {
        third = CREATE_LIST(third, second->data);
        second = second->next;
    }
    printf("\nLists are merged successfully");

    return third;
}
int main()
{
    int data, choice;
    NODE *head = NULL, *l1 = NULL, *l2 = NULL, *l3 = NULL;
    while (1)
    {
        printf("\n1:CREATE_LIST 1\n2:CREATE LIST 2\n3:MERGE\n4:DISPLAY\n5:Merge DisplY\n6:EXIT\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter the data: ");
            scanf("%d", &data);
            l1 = CREATE_LIST(l1, data);
            break;
        case 2:
            printf("\nEnter the data: ");
            scanf("%d", &data);
            l2 = CREATE_LIST(l2, data);
            break;
        case 3:

            l3 = merge(l1, l2, l3);
            break;
        case 4:
            l1 = display(l1);
            l2 = display(l2);

            break;
        case 5:
            l3 = display(l3);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid Choice");
        }
    }
    return 0;
}
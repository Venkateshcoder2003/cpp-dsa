// #include <stdio.h>
// #include <stdlib.h>

// typedef struct node
// {
//     int data;
//     struct node *next;
// } NODE;
// static int count = -1;
// NODE *INSERT_BEGIN(NODE *head, int data)
// {
//     NODE *newnode;
//     newnode = (NODE *)malloc(sizeof(NODE));
//     count++;
//     newnode->data = data;
//     newnode->next = head;

//     return newnode;
// }
// NODE *INSERT_END(NODE *head, int data)
// {
//     NODE *newnode, *temp;
//     newnode = (NODE *)malloc(sizeof(NODE));
//     count++;
//     newnode->data = data;
//     newnode->next = NULL;
//     temp = head;
//     if (head == NULL)
//         head = temp = newnode;
//     else
//     {
//         while (temp->next != NULL)
//             temp = temp->next;
//         temp->next = newnode;
//     }
//     return head;
// }
// NODE *INSERT_MIDDLE(NODE *head, int pos)
// {
//     NODE *newnode, *temp;
//     int i = 0, data;

//     temp = head;
//     if (pos > count + 1 || pos < 0)
//     {
//         printf("\nInvalid Position Entered ");
//     }
//     else
//     {
//         while (i < pos - 1)
//         {
//             temp = temp->next;
//             i++;
//         }
//         newnode = (NODE *)malloc(sizeof(NODE));
//         count++;
//         printf("\nEnter The Data: ");
//         scanf("%d", &data);
//         newnode->data = data;
//         newnode->next = temp->next;
//         temp->next = newnode;
//     }
//     return head;
// }
// NODE *DELETE_BEGINNING(NODE *head)
// {
//     if (head == NULL)
//     {
//         printf("\nLinked List Is Empty");
//     }

//     else
//     {
//         NODE *temp = head;
//         head = head->next;
//         free(temp);
//         count--;
//     }
//     return head;
// }
// NODE *DELETE_END(NODE *head)
// {
//     int temp_count = 0, i = 0;
//     NODE *temp, *temp1;
//     if (head == NULL)
//     {
//         printf("Linked List Is Empty Cannot Delete Elements");
//     }
//     else
//     {
//         NODE *prev_node;
//         temp = head;
//         while (temp->next != NULL)
//         {
//             prev_node = temp;
//             temp = temp->next;
//         }

//         if (temp == head)
//         {
//             head = NULL;
//             free(temp);
//             count--;
//         }
//         else
//         {
//             prev_node->next = NULL;
//             free(temp);
//             count--;
//         }
//     }
//     return head;
// }
// NODE *DELETE_BETWEEN(NODE *head, int pos)
// {
//     int i = 1;
//     if (pos >= count || pos < 0)
//     {
//         printf("\nInvalid Position Entered");
//     }
//     else
//     {
//         if (pos == 0)
//         {
//             NODE *temp = head;
//             head = head->next;
//             free(temp);
//             count--;
//         }
//         else
//         {
//             NODE *temp, *nextnode;
//             temp = head;
//             while (i < pos)
//             {
//                 temp = temp->next;
//                 i++;
//             }
//             nextnode = temp->next;
//             temp->next = nextnode->next;
//             free(nextnode);
//             count--;
//         }
//     }
//     return head;
// }
// void DISPLAY(NODE *head)
// {
//     NODE *temp;
//     temp = head;
//     if (head == NULL)
//     {
//         printf("No Elements In Linked List To Display");
//     }

//     else
//     {
//         printf("\nBEGIN->");
//         while (temp != NULL)
//         {
//             printf("%d->", temp->data);
//             temp = temp->next;
//         }
//         printf("END\n");
//     }
// }

// int main()
// {
//     int choice, data, pos;
//     NODE *head = NULL;
//     while (1)
//     {
//         printf("\n1:INSERT@BEGIN\n2:INSERT@END\n3:INSERT@MIDDLE\n4:DELETE_FROM_BEGIN\n5:DELETE_FROM_END\n6:DELETE_FROM_MIDDLE\n7:DISPLAY\n8:EXIT");
//         printf("\nEnter Your Choice: ");
//         scanf("%d", &choice);

//         switch (choice)
//         {
//         case 1:
//             printf("\nEnter The Data To Be Inserted At Beginning: ");
//             scanf("%d", &data);
//             head = INSERT_BEGIN(head, data);
//             break;
//         case 2:
//             printf("Enter The Data To be Inserted At Last: ");
//             scanf("%d", &data);
//             head = INSERT_END(head, data);
//             break;
//         case 3:
//             printf("Enter The Position: \n");
//             scanf("%d", &pos);
//             head = INSERT_MIDDLE(head, pos);
//             break;
//         case 4:
//             head = DELETE_BEGINNING(head);
//             break;
//         case 5:
//             head = DELETE_END(head);
//             break;
//         case 6:
//             printf("Enter The Position: ");
//             scanf("%d", &pos);
//             head = DELETE_BETWEEN(head, pos - 1);
//             break;
//         case 7:
//             DISPLAY(head);
//             break;
//         case 8:
//             exit(0);
//         default:
//             printf("INVALID CHOICE");
//         }
//     }
// }
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
    if (head == NULL)
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
    if (head == NULL)
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
NODE *INSERT_MIDDLE(NODE *head, int pos)
{
    NODE *newnode, *temp;
    int i = 0, data;
    temp = head;
    if (pos > count + 1 || pos < 0)
    {
        printf("\nInvalid Position Entered ");
    }
    else
    {
        newnode = (NODE *)malloc(sizeof(NODE));
        printf("\nEnter The Data: ");
        scanf("%d", &data);
        newnode->data = data;
        if (pos == 0)
        {
            newnode->next = head;
            head = newnode;
        }
        else
        {
            while (i < pos - 1)
            {
                temp = temp->next;
                i++;
            }
            newnode->next = temp->next;
            temp->next = newnode;
        }
        count++;
    }
    return head;
}

NODE *DELETE_BETWEEN(NODE *head, int pos)
{
    int i = 1;
    if (pos >= count || pos < 0)
    {
        printf("\nInvalid Position Entered");
    }
    else
    {
        if (pos == 0)
        {
            NODE *temp = head;
            head = head->next;
            free(temp);
            count--;
        }
        else
        {
            NODE *temp, *nextnode;
            temp = head;
            while (i < pos)
            {
                temp = temp->next;
                i++;
            }
            nextnode = temp->next;
            temp->next = nextnode->next;
            free(nextnode);
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
        printf("\n1:INSERT@BEGIN\n2:INSERT@END\n3:INSERT@MIDDLE\n4:DELETE_FROM_BEGIN\n5:DELETE_FROM_END\n6:DELETE_FROM_MIDDLE\n7:DISPLAY\n8:EXIT");
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
            head = DELETE_BEGINNING(head);
            break;
        case 5:
            head = DELETE_END(head);
            break;
        case 6:
            printf("Enter The Position: ");
            scanf("%d", &pos);
            head = DELETE_BETWEEN(head, pos - 1);
            break;
        case 7:
            DISPLAY(head);
            break;
        case 8:
            exit(0);
        default:
            printf("INVALID CHOICE");
        }
    }
}
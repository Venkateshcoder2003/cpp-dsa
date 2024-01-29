// // PRIORITY QUEUE USING LINKED LIST WHEN PRIORITIES ARE GIVEN

// #include <stdio.h>
// #include <stdlib.h>

// struct node
// {
//     int data;
//     int pri;
// };

// typedef struct node
// {
//     struct node p;
//     struct node *next;
// } NODE;
// NODE *INSERT(NODE *head, int data, int pri)
// {
//     NODE *newnode, *p_node, *temp;
//     newnode = (NODE *)malloc(sizeof(NODE));
//     newnode->next = NULL;

//     if (head == NULL || pri < head->p.pri)
//     {
//         newnode->next = head;
//         head = head->next;
//     }
//     else
//     {
//         while (temp != NULL && pri >= temp->p.name)
//         {
//             p_node = temp;
//             temp = temp->next;
//         }
//         p_node->next = newnode;
//         newnode->next = temp;
//     }
//     printf("%d Data With Priority %d Is Added to Priority Queue!", p.data, p.pri);
//     return head;
// }
// NODE *DELETE(NODE *head)
// {
//     if (head == NULL)
//     {
//         printf("\nQueue Is Empty");
//     }
//     else
//     {
//         NODE *temp = head;
//         printf("The Data %d had Highest Priority and Is Deleted From Queue", temp->p.data);
//         head = head->next;
//         free(temp);
//     }
//     return head;
// }
// NODE *DISPLAY(NODE *head)
// {
//     if (head == NULL)
//     {
//         printf("\nQueue is Empty");
//     }
//     else
//     {
//         NODE *temp = head;
//         printf("FRONT->");
//         while (temp != NULL)
//         {
//             printf("[%d][%d]->", temp->p.data, temp->p.pri);
//             temp = temp->next;
//         }
//         printf("REAR\n");
//     }
//     return head;
// }
// int main()
// {
//     NODE *head = NULL;
//     int data, pri, choice;
//     while (1)
//     {
//         printf("\n1:INSERT\n2:DELETE\n3:DISPLAY\n4:EXIT\n");
//         printf("Enter Your Choice: ");
//         scanf("%d", &choice);

//         switch (choice)

//         {
//         case 1:
//             printf("Enter Data To be Inserted Into Priority Queue: \n");
//             scanf("%d", &data);
//             printf("\nEnter Its Priority: ");
//             scanf("%d", &pri);
//             head = INSERT(head, data, pri);
//             break;
//         case 2:
//             head = DELETE(head);
//             break;
//         case 3:
//             head = DISPLAY(head);
//             break;
//         case 4:
//             exit(0);
//         default:
//             printf("\nInvalid Choice");
//         }
//     }
// }
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    int pri;
    struct node *next;
};

typedef struct node NODE;

NODE *INSERT(NODE *head, int data, int pri)
{
    NODE *newnode, *temp, *prev;

    newnode = (NODE *)malloc(sizeof(NODE));
    newnode->data = data;
    newnode->pri = pri;
    newnode->next = NULL;

    if (head == NULL || pri < head->pri)
    {
        newnode->next = head;
        head = newnode;
    }
    else
    {
        temp = head;
        while (temp != NULL && pri >= temp->pri)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = newnode;
        newnode->next = temp;
    }

    printf("%d Data With Priority %d Is Added to Priority Queue!\n", data, pri);
    return head;
}

NODE *DELETE(NODE *head)
{
    if (head == NULL)
    {
        printf("\nQueue Is Empty\n");
    }
    else
    {
        NODE *temp = head;
        printf("The Data %d with Priority %d has the Highest Priority and Is Deleted From Queue\n", temp->data, temp->pri);
        head = head->next;
        free(temp);
    }
    return head;
}

void DISPLAY(NODE *head)
{
    if (head == NULL)
    {
        printf("\nQueue is Empty\n");
    }
    else
    {
        NODE *temp = head;
        printf("FRONT->");
        while (temp != NULL)
        {
            printf("(%d, %d)->", temp->data, temp->pri);
            temp = temp->next;
        }
        printf("REAR\n");
    }
}

int main()
{
    NODE *head = NULL;
    int data, pri, choice;
    while (1)
    {
        printf("\n1: INSERT\n2: DELETE\n3: DISPLAY\n4: EXIT\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter Data To be Inserted Into Priority Queue: \n");
            scanf("%d", &data);
            printf("\nEnter Its Priority: ");
            scanf("%d", &pri);
            head = INSERT(head, data, pri);
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
            printf("\nInvalid Choice\n");
        }
    }
    return 0;
}

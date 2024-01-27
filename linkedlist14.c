// #include <stdio.h>
// #include <stdlib.h>

// typedef struct node
// {
//     int data;
//     struct node *next;
// } NODE;
// static int count = 0;
// NODE *create_list(NODE *head, int data)
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
// NODE *display(NODE *head)
// {
//     if (head == NULL)
//     {
//         printf("No Elements To Display In Linked List");
//     }
//     else
//     {
//         NODE *temp = head;
//         printf("\nBEGIN->");
//         while (temp != NULL)
//         {
//             printf("%d->", temp->data);
//             temp = temp->next;
//         }
//         printf("END\n");
//     }
//     return head;
// }
// NODE *Remove_Duplicates(NODE *head)
// {
//     int flag = 0, n = count, key, arr[count];
//     NODE *temp = head, *run_node;

//     for (int i = 1; i < n; i++)
//     {
//         if (temp == NULL)
//             break;
//         key = temp->data;
//         flag = 0;
//         run_node = head;
//         for (int j = 1; j < n; j++)
//         {
//             if (key == run_node->data)
//                 flag++;
//             run_node = run_node->next;
//         }
//         if (flag == 2)
//             arr[i] = key;
//         temp = temp->next;
//     }
//     for (int k = 1; k < count; k++)
//     {
//         printf("%d\t", arr[k]);
//     }
//     return head;
// }
// int main()
// {
//     int choice, data;
//     NODE *head = NULL;
//     while (1)
//     {
//         printf("\n1:create_list\n2:Remove_duplicates\n3:Display\n4:Exit\n");
//         printf("Enter Your Choice: ");
//         scanf("%d", &choice);

//         switch (choice)
//         {
//         case 1:
//             printf("\nEnter The Data: ");
//             scanf("%d", &data);
//             head = create_list(head, data);
//             break;
//         case 2:
//             head = Remove_Duplicates(head);
//             break;
//         case 3:
//             head = display(head);
//             break;
//         case 4:
//             exit(0);
//         default:
//             printf("\nInvalid Choice");
//         }
//     }
//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} NODE;
static int count = 0;
NODE *create_list(NODE *head, int data)
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
NODE *display(NODE *head)
{
    if (head == NULL)
    {
        printf("No Elements To Display In Linked List");
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
        printf("END\n");
    }
    return head;
}
NODE *Remove_Duplicates(NODE *head)
{
    int flag = 0, n = count, key, arr[count];
    NODE *temp = head, *run_node;

    for (int i = 1; i < n; i++)
    {
        if (temp == NULL)
            break;
        key = temp->data;
        flag = 0;
        run_node = head;
        for (int j = 1; j < n; j++)
        {
            if (key == run_node->data)
                flag++;
            run_node = run_node->next;
        }
        if (flag == 2)
            arr[i] = key;
        temp = temp->next;
    }
    printf("Duplicate elements in the linked list are: ");
    for (int k = 1; k < count; k++)
    {
        if (arr[k] != 0)
            printf("%d\t", arr[k]);
    }
    return head;
}

int main()
{
    int choice, data;
    NODE *head = NULL;
    while (1)
    {
        printf("\n1:create_list\n2:Remove_duplicates\n3:Display\n4:Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter The Data: ");
            scanf("%d", &data);
            head = create_list(head, data);
            break;
        case 2:
            head = Remove_Duplicates(head);
            break;
        case 3:
            head = display(head);
            break;
        case 4:
            exit(0);
        default:
            printf("\nInvalid Choice");
        }
    }
    return 0;
}
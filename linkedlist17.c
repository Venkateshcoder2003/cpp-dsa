#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} NODE;
static int count = 0, i = 0, j = 0;
int arr1[100], arr2[100];
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
    arr1[i] = newnode->data;
    arr2[j] = newnode->data;
    j++;
    i++;
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
int Check_palindrome()
{
    int l = 0, flag;
    for (int k = count - 1; k >= 0; k--)
    {
        if (arr1[l] == arr2[k])
        {
            l++;
            flag = 0;
        }
        else
            flag++;
    }
    if (flag == 0)
        return 1;
    return 0;
}
// NODE *DISPLAY(NODE *head)
// {
//     int i = 0;
//     if (head == NULL)
//     {
//         printf("No Elements To Display In Linked List");
//     }
//     else
//     {
//         NODE *temp = head;
//         printf("\nBEGIN->");
//         while (i < count)
//         {
//             printf("%d->", temp->data);
//             temp = temp->next;
//             i++;
//         }
//         printf("END\n");
//     }
//     return head;
// }

int main()
{
    int choice, data, res = 0;
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
            res = Check_palindrome();
            if (res == 1)
                printf("\nLinked LIst Is Palindrome");
            else
                printf("\nLinked List Is Not Palindrome");
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
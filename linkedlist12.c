#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} NODE;
static int count = -1;
NODE *create(NODE *head, int data)
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

NODE *sort(NODE *head)
{

    NODE *p_node = NULL, *c_node = head, *n_node = head;
    for (int i = 0; i <= count; i++)
    {
        n_node = head;
        for (int j = 0; j <= count - i - 1; j++)
        {
            n_node = n_node->next;
            if (c_node->data > n_node->data)
            {
                int temp = c_node->data;
                // t_node->next = p_node->next;
                c_node->data = n_node->data;
                // p_node->next = n_node->next;
                n_node->data = temp;
                // n_node->next = t_node->next;
            }
            p_node = c_node;
            c_node = c_node->next;
        }
        p_node = NULL;
        c_node = head;
        n_node = head;
    }
    return head;
}

NODE *INSERT_POSITION(NODE *head, int key)
{
    NODE *n_node = head, *c_node = head, *p_node = NULL;
    NODE *newnode = (NODE *)malloc(sizeof(NODE));
    newnode->data = key;
    while (n_node != NULL)
    {
        n_node = n_node->next;
        if (newnode->data > c_node->data && (n_node == NULL || newnode->data < n_node->data))
        {
            newnode->next = n_node;
            c_node->next = newnode;
            break;
        }
        p_node = c_node;
        c_node = n_node;
    }
    return head;
}

NODE *DISPLAY(NODE *head)
{
    NODE *temp;

    if (head == NULL)
    {
        printf("\nLinked List Is Empty");
    }
    else
    {
        temp = head;
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
    int choice, data, key;
    NODE *head = NULL;

    while (1)
    {
        printf("\n1:Createlist\n2:sort\n3:insert@suitableposition\n4:Display\n5:Exit\n");
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter The Data To Be Inserted Into Linked List: ");
            scanf("%d", &data);
            head = create(head, data);
            break;
        case 2:
            head = sort(head);
            break;
        case 3:
            printf("\nEnter The Data by Seeing The Sorted Linked List: ");
            scanf("%d", &key);
            head = INSERT_POSITION(head, key);
            break;
        case 4:
            head = DISPLAY(head);
            break;
        case 5:
            exit(0);
        }
    }
}

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left, *right;
} NODE;
NODE *create_node(int data)
{
    NODE *newnode = (NODE *)malloc(sizeof(NODE));
    if (newnode == NULL)
    {
        printf("Memory Allocation Failed");
        exit(0);
    }
    newnode->data = data;
    newnode->left = newnode->right = NULL;

    return newnode;
}
NODE *insert_node(NODE *root, int data)
{
    if (root == NULL)
    {
        root = create_node(data);
    }
    else if (data < root->data)
    {
        root->left = insert_node(root->left, data);
    }
    else
    {
        root->right = insert_node(root->right, data);
    }
    return root;
}
int count(NODE *root)
{
    NODE *temp = root;
    int x = 0, y = 0;
    if (temp != NULL)
    {
        x = count(temp->left);
        y = count(temp->right);
        if (x > y)
        {
            return x + 1;
        }
        else
        {
            return y + 1;
        }
    }
    return 0;
}
int main()
{
    int data, choice;
    NODE *root = NULL;
    NODE *inptr = NULL, *preptr = NULL, *postptr = NULL;
    int key;
    int c = 0;
    while (1)
    {
        printf("\n1:Insert_node\n2:inorder_traversal\n3:preorder\n4:postorder\n5:Delete\n6:Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter The Data: ");
            scanf("%d", &data);
            root = insert_node(root, data);
            break;
        case 2:
            c = count(root);
            printf("\nThe Number Of Having left and right childs are: %d", c);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid Choice\n");
        }
    }
}

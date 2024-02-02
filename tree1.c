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
void inorder(NODE *root)
{
    if (root != NULL)
    {

        inorder(root->left);
        printf("%d->", root->data);
        inorder(root->right);
    }
}
void preorder(NODE *root)
{
    if (root != NULL)
    {
        printf("%d->", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(NODE *root)
{
    if (root != NULL)
    {

        postorder(root->left);
        postorder(root->right);
        printf("%d->", root->data);
    }
}
int main()
{
    int data, choice;
    NODE *root = NULL;
    NODE *inptr = NULL, *preptr = NULL, *postptr = NULL;

    while (1)
    {
        printf("\n1:Insert_node\n2:inorder_traversal\n3:preorder\n4:postorder\n5:display\n6:Exit\n");
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
            inorder(root);
            break;
        case 3:
            preorder(root);
            break;
        case 4:
            postorder(root);
            break;
            // case 5:
            //     root = display(root);
            //     break;
        case 6:
            exit(0);
        default:
            printf("Invalid Choice\n");
        }
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

typedef struct node
{
    char info;
    struct node *lchild, *rchild;

} NODE;

NODE *createpostfix(char postfix[])
{
    NODE *newnode, *stack[20];
    int top = -1;
    char ch;

    for (int i = 0; postfix[i] != NULL; i++)
    {
        ch = postfix[i];
        newnode = (NODE *)malloc(sizeof(NODE));
        newnode->info = ch;
        newnode->lchild = newnode->rchild = NULL;
        if (isalnum(ch))
        {
            stack[++top] = newnode;
        }
        else
        {
            newnode->rchild = stack[top--];
            newnode->lchild = stack[top--];
            stack[++top] = newnode;
        }
    }
    if (top == 0)
    {
        return (stack[top]);
    }
    else
    {
        return NULL;
    }
}
float eval(NODE *root)
{
    float num;
    switch (root->info)
    {
    case '+':
        return (eval(root->lchild) + eval(root->rchild));

    case '-':
        return (eval(root->lchild) - eval(root->rchild));

    case '*':
        return (eval(root->lchild) * eval(root->rchild));

    case '/':
        return (eval(root->lchild) / eval(root->rchild));

    case '^':
        return (pow(eval(root->lchild), eval(root->rchild)));

    default:
        if (isalpha(root->info))
        {
            printf("\n%c=", root->info);
            scanf("%f", &num);
            return (num);
        }
        else
        {
            return (root->info - '0');
        }
    }
}
int main()
{
    char postfix[30];
    NODE *root = NULL;
    float res;
    printf("\nEnter Valid Postfix Expression: ");
    scanf("%s", postfix);
    root = createpostfix(postfix);
    res = eval(root);
    printf("\nResult = %f", res);
    return 0;
}
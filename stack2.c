/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 5
#define MAXNAMELENGTH 50

typedef struct
{
    char names[MAXSIZE][MAXNAMELENGTH];
    int top;
} NAME_STACK;

int isFull(NAME_STACK *s)
{
    return s->top == MAXSIZE - 1;
}

int isEmpty(NAME_STACK *s)
{
    return s->top == -1;
}

void push(NAME_STACK *s, const char *name)
{
    if (isFull(s))
    {
        printf("\nStack Overflow\n");
    }
    else
    {
        // s->top++;
        strcpy(s->names[++s->top], name);
        printf("\n%s pushed successfully.\n", name);
    }
}

void pop(NAME_STACK *s)
{
    if (isEmpty(s))
    {
        printf("\nStack Underflow \n");
    }
    else
    {
        printf("\n%s popped from the stack.\n", s->names[s->top--]);
        // s->top--;
    }
}

void peek(NAME_STACK *s)
{
    if (isEmpty(s))
    {
        printf("\nStack is empty.\n");
    }
    else
    {
        printf("\nTop of the stack: %s\n", s->names[s->top]);
    }
}

void display(NAME_STACK *s)
{
    if (isEmpty(s))
    {
        printf("\nStack is empty.\n");
    }
    else
    {
        printf("\nNames in the stack:\n");
        for (int i = 0; i <= s->top; i++)
        {
            printf("%s\n", s->names[i]);
        }
    }
}

int main()
{
    NAME_STACK nameStack;
    nameStack.top = -1;

    int choice;
    char name[MAXNAMELENGTH];

    while (1)
    {
        printf("\n1: Push\n2: Pop\n3: Peek\n4: Display\n5: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter name to push: ");
            scanf("%s", name);
            push(&nameStack, name);
            break;
        case 2:
            pop(&nameStack);
            break;
        case 3:
            peek(&nameStack);
            break;
        case 4:
            display(&nameStack);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 5
#define MAXNAMELENGTH 50

typedef struct
{
    char names[MAXSIZE][MAXNAMELENGTH];
    int top;
} STACK;

int isFull(STACK s)
{
    return s.top == MAXSIZE - 1;
}

int isEmpty(STACK s)
{
    return s.top == -1;
}

void push(STACK *s, const char *name)
{
    if (isFull(*s))
    {
        printf("\nStack Overflow\n");
    }
    else
    {
        strcpy(s->names[++s->top], name);
        printf("\n%s pushed successfully.\n", name);
    }
}

void pop(STACK *s)
{
    if (isEmpty(*s))
    {
        printf("\nStack Underflow \n");
    }
    else
    {
        printf("\n%s popped from the stack.\n", s->names[s->top--]);
    }
}

void peek(STACK *s)
{
    if (isEmpty(*s))
    {
        printf("\nStack is empty.\n");
    }
    else
    {
        printf("\nTop of the stack: %s\n", s->names[s->top]);
    }
}

void display(STACK *s)
{
    if (isEmpty(*s))
    {
        printf("\nStack is empty.\n");
    }
    else
    {
        printf("\nNames in the stack:\n");
        for (int i = 0; i <= s->top; i++)
        {
            printf("%s\n", s->names[i]);
        }
    }
}

int main()
{
    STACK s; // Declare structure variable directly as STACK s
    s.top = -1;

    int choice;
    char name[MAXNAMELENGTH];

    while (1)
    {
        printf("\n1: Push\n2: Pop\n3: Peek\n4: Display\n5: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter name to push: ");
            scanf("%s", name);
            push(&s, name);
            break;
        case 2:
            pop(&s);
            break;
        case 3:
            peek(&s);
            break;
        case 4:
            display(&s);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

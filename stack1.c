#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5

typedef struct
{
    int items[MAXSIZE];
    int top;
} STACK;

int isfull(STACK s)
{
    if (s.top == MAXSIZE - 1)
        return 1;
    return 0;
}
int isempty(STACK s)
{
    if (s.top == -1)
        return 1;
    return 0;
}

void PUSH(STACK *s, int data)
{
    s->items[++s->top] = data;
    printf("\nPUSHED SUCCESSFULLY\n");
}

int POP(STACK *s)
{
    return (s->items[s->top--]);
}

int PEEK(STACK s)
{
    return (s.items[s.top]);
}

void DISPLAY(STACK s)
{
    for (int i = 1; i <= s.top; i++)
    {
        printf("%d->", s.items[i]);
    }
}

int main()
{
    STACK s;
    int top = -1;
    int choice, data;

    while (1)
    {
        printf("\n1:PUSH\n2:POP\n3:PEEK\n4:DISPLAY\n5:EXIT\n");
        printf("Enter Your Choice: \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (isfull(s))
            {
                printf("\nSTACKOVERFLOW");
            }
            else
            {
                printf("Enter Data To be Pushed To Stack: \n");
                scanf("%d", &data);
                PUSH(&s, data);
            }
            break;
        case 2:
            if (isempty(s))
            {
                printf("\nSTACKUNDERFLOW");
            }
            else
            {
                printf("\n data %d Is Popped from Top of of the stack", POP(&s));
            }
            break;
        case 3:
            if (isempty(s))
            {
                printf("\nSTACK EMPTY");
            }
            else
            {
                printf("\n Data %d is on The Top Of The Stack", PEEK(s));
            }
            break;
        case 4:
            if (isempty(s))
            {
                printf("\nSTACK EMPTY");
            }
            else
            {
                DISPLAY(s);
            }
            break;
        case 5:
            exit(0);
        default:
            printf("\nINVALID CHOICE");
        }
    }
    return 0;
}
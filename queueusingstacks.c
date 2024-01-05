#include <stdio.h>
#include <stdlib.h>
#define MAX 10
typedef struct
{
    int items[MAX];
    int top;
} STACK;

int count = 0; // to keep track of number of integers in stacks

void PUSH1(STACK *s1, int x)
{
    if (s1->top == MAX - 1)
        printf("\nQueue Is Full");
    else
    {
        s1->items[++s1->top] = x;
        count++;
        printf("%d Is Added To Queue\n", x);
    }
}
void ENQUEUE(STACK *s1, STACK *s2, int x)
{
    if (s1->top == MAX - 1)
        printf("\nQueue Is Full");
    else
    {
        PUSH1(s1, x);
    }
}

int pop1(STACK *s1)
{
    if (s1->top == -1)
        printf("Queue Is Empty Cannot POP Elements From Queue");
    else
    {
        return (s1->items[s1->top--]);
    }
}

void PUSH2(STACK *s2, int x)
{
    if (s2->top == MAX - 1)
        printf("\nQueue Is Full");
    else
    {
        s2->items[++s2->top] = x;
    }
}
int pop2(STACK *s2)
{
    if (s2->top == -1)
        printf("Queue Is Empty");
    else
    {
        return (s2->items[s2->top--]);
    }
}

int DEQUEUE(STACK *s1, STACK *s2)
{
    int a, b, x = -1;
    int y;
    if (s1->top == -1 && s2->top == -1)
        printf("\nQueue IS Empty");
    else
    {
        while (s1->top != -1)
        {
            a = pop1(s1);
            PUSH2(s2, a);
        }
        x = pop2(s2);
        count--;
    }

    while (s2->top != -1)
    {
        y = pop2(s2);
        PUSH1(s1, y);
        count++;
    }

    return x;
}

void DISPLAY(STACK *s1)
{
    if (s1->top == -1)
        printf("\nCan't Display Elements Queue Is Empty\n");
    else
    {
        for (int i = 0; i <= s1->top; i++)
            printf("%d->", s1->items[i]);
    }
}
int main()
{
    STACK s1, s2;
    s1.top = s2.top = -1;
    int choice;
    int data, ele;
    while (1)
    {
        printf("\n1:ENQUEUE\n2:DEQUEUE\n3:DISPLAY\n4:EXIT");
        printf("\nEnter Your Choice: \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter An Integer To Insert: \n");
            scanf("%d", &data);
            ENQUEUE(&s1, &s2, data);
            break;
        case 2:
            ele = DEQUEUE(&s1, &s2);
            if (ele != -1)
                printf("\n%d Is Removed From Queue\n", ele);
            break;
        case 3:
            DISPLAY(&s1);
            break;
        case 4:
            exit(0);
        default:
            printf("\nInvalid Choice");
        }
    }
}
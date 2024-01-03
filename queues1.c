#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int *items;
    int front;
    int rear;
};

void create_queue(struct queue *q)
{
    printf("Enter Size of Queue: ");
    scanf("%d", &q->size);
    q->items = (int *)malloc(q->size * sizeof(int));
    q->front = q->rear = -1;
}

void INSERT(struct queue *q, int x)
{
    if (q->rear == q->size - 1)
    {
        printf("\nQueue Is Full(Queue Overflow)");
    }
    else
    {
        q->rear++;
        q->items[q->rear] = x;
        printf("%d Is added To Queue\n", x);
    }
}

int DELETE(struct queue *q)
{
    int x = -1;
    if (q->rear == q->front)
    {
        printf("Queue Is Empty (Queue Underflow)");
    }
    else
    {
        q->front++;
        x = q->items[q->front];
    }
    return x;
}

void DISPLAY(struct queue *q)
{
    if (q->rear == q->front)
    {
        printf("QUEUE Is Empty Cannot Display  The Elements\n");
    }

    else
    {
        printf("\nFRONT->");
        for (int i = q->front + 1; i <= q->rear; i++)
        {
            printf("%d->", q->items[i]);
        }
    }
    printf("RARE\n");
}

int main()
{
    int choice, data, ele;
    struct queue q;
    create_queue(&q);

    while (1)
    {
        printf("\n1:INSERT\n2:DELETE\n3:DISPLAY\n4:EXIT\n");
        printf("Enter Your Choice: \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter An Integer To Insert: ");
            scanf("%d", &data);
            INSERT(&q, data);
            break;

        case 2:
            ele = DELETE(&q);
            printf("%d Is Removed From Queue\n", ele);
            break;

        case 3:
            DISPLAY(&q);

            break;

        case 4:
            exit(0);

        default:
            printf("Invalid Choice\n");
        }
    }
    return 0;
}
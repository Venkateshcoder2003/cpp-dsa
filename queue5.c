#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int *items;
    int new_size;
    int front;
    int rear;
};

int count = 0;

void create_queue(struct queue *q)
{
    printf("Enter Size Of Queue: ");
    scanf("%d", &q->size);
    q->new_size = q->size + 1;
    q->items = (int *)malloc(q->new_size * sizeof(int));
    q->front = q->rear = 0;
}

void INSERT(struct queue *q, int x)
{
    if ((q->rear + 1) % q->new_size == q->front)
    {
        printf("\nQueue Is Full (QUEUE OVERFLOW)\n");
    }
    else
    {
        q->rear = (q->rear + 1) % q->new_size;
        q->items[q->rear] = x;
        count++;
        printf("%d Is Added To Queue\n", x);
    }
}

int DELETE(struct queue *q)
{
    int x = -1;
    if (q->rear == q->front)
    {
        printf("Queue Is Empty (QUEUE UNDERFLOW)\n");
    }
    else
    {
        x = q->items[q->front];
        q->front = (q->front + 1) % q->new_size;
        count--;
    }
    return x;
}

void DISPLAY(struct queue *q)
{
    int i = q->front + 1;
    if (count == 0)
    {
        printf("Queue Is Empty\n");
        return;
    }
    do
    {
        printf("%d->", q->items[i]);
        i = (i + 1) % q->new_size;

    } while (i != (q->rear + 1) % q->new_size);
    printf("REAR\n");
}

int main()
{
    int choice, data, ele;
    struct queue q;
    create_queue(&q);

    while (1)
    {
        printf("\n1: INSERT\n2: DELETE\n3: DISPLAY\n4: EXIT\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter An Element To Insert: ");
            scanf("%d", &data);
            INSERT(&q, data);
            break;

        case 2:
            ele = DELETE(&q);
            if (ele != -1)
                printf("\n%d Is Deleted From Queue\n", ele);
            break;

        case 3:
            DISPLAY(&q);
            break;

        case 4:
            free(q.items);
            printf("\n*******Memory Deallocated Successfully*******");
            exit(0);

        default:
            printf("\nInvalid Choice\n");
        }
    }
    return 0;
}

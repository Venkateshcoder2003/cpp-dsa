#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    char *items;
    int front;
    int rear;
};

void create_queue(struct queue *q)
{
    printf("Enter Size of Queue: ");
    scanf("%d", &q->size);
    q->items = (char *)malloc(q->size * sizeof(char));
    q->front = q->rear = -1;
}

void INSERT(struct queue *q, char x)
{
    if (q->rear == q->size - 1)
    {
        printf("\nQueue Is Full (Queue Overflow)\n");
    }
    else
    {
        q->rear++;
        q->items[q->rear] = x;
        printf("%c Is added To Queue\n", x);
    }
}

char DELETE(struct queue *q)
{
    char x = '\0';
    if (q->rear == q->front)
    {
        printf("Queue Is Empty (Queue Underflow)\n");
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
        printf("QUEUE Is Empty. Cannot Display The Elements\n");
    }
    else
    {
        printf("\nFRONT->");
        for (int i = q->front + 1; i <= q->rear; i++)
        {
            printf("%c->", q->items[i]);
        }
    }
    printf("RARE\n");
}

int main()
{
    int choice;
    char data, ele;
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
            printf("Enter a Character To Insert: ");
            scanf(" %c", &data); // Use a space before %c to consume the newline character
            INSERT(&q, data);
            break;

        case 2:
            ele = DELETE(&q);
            if (ele != '\0')
                printf("%c Is Removed From Queue\n", ele);
            break;

        case 3:
            DISPLAY(&q);
            break;

        case 4:
            free(q.items);
            exit(0);

        default:
            printf("Invalid Choice\n");
        }
    }

    return 0;
}

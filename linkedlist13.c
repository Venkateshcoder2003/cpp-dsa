
#include <stdio.h>
#include <stdlib.h>

struct polynomial
{
    float coeff;
    float powx;
    float powy;
};

typedef struct node
{
    struct polynomial p;
    struct node *next;
} NODE;

NODE *INSERT_END(NODE *head, float cf, float px, float py)
{
    NODE *temp;
    NODE *newnode = (NODE *)malloc(sizeof(NODE));
    newnode->p.coeff = cf;
    newnode->p.powx = px;
    newnode->p.powy = py;
    newnode->next = NULL;
    temp = head;
    if (cf == 0)
    {
        return head;
    }

    if (head == NULL)
        head = temp = newnode;

    else
    {
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }

    return head;
}
NODE *read_polynomial(NODE *head)
{
    float coeff, powx, powy;
    // NODE *newnode = (NODE *)malloc(sizeof(NODE));
    printf("\nEnter The Coefficient: \n");
    scanf("%f", &coeff);
    printf("Enter Power Of x(1st variable): \n");
    scanf("%f", &powx);
    printf("Enter The Power Of y(2nd Variable): \n");
    scanf("%f", &powy);
    head = INSERT_END(head, coeff, powx, powy);
    return head;
}

NODE *display(NODE *head)
{
    if (head == NULL)
        printf("Polynomial Is Not Entered Still");

    else
    {
        NODE *temp = head;
        while (temp != NULL)
        {
            printf("(%0.0fx^%0.0fy^%0.0f)", temp->p.coeff, temp->p.powx, temp->p.powy);
            if (temp->next != NULL)
                printf(" + ");
            temp = temp->next;
        }
    }
    return head;
}
NODE *add(NODE *poly1, NODE *poly2)
{
    NODE *temp1 = poly1;
    NODE *temp2 = poly2;
    NODE *poly3 = NULL;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->p.powx == temp2->p.powx && temp1->p.powy == temp2->p.powy)
        {
            poly3 = INSERT_END(poly3, temp1->p.coeff + temp2->p.coeff, temp1->p.powx, temp1->p.powy);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        // else if ((temp1->p.powx > temp2->p.powx) || (temp1->p.powx == temp2->p.powx && temp1->p.powy > temp2->p.powy))
        else if ((temp1->p.powx > temp2->p.powx) || (temp1->p.powx == temp2->p.powx && temp1->p.powy > temp2->p.powy))

        {
            poly3 = INSERT_END(poly3, temp1->p.coeff, temp1->p.powx, temp1->p.powy);
            temp1 = temp1->next;
        }
        else
        {
            poly3 = INSERT_END(poly3, temp2->p.coeff, temp2->p.powx, temp2->p.powy);
            temp2 = temp2->next;
        }
    }

    while (temp1 != NULL)
    {
        poly3 = INSERT_END(poly3, temp1->p.coeff, temp1->p.powx, temp1->p.powy);
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        poly3 = INSERT_END(poly3, temp2->p.coeff, temp2->p.powx, temp2->p.powy);
        temp2 = temp2->next;
    }
    return poly3;
}

int main()
{
    NODE *poly1 = NULL, *poly2 = NULL;
    NODE *poly3 = NULL;
    int stop_read1 = 1, stop_read2 = 1;
    printf("Enter The Input For Polynomial 1(0 for stop reading the polynomial 1)");
    while (stop_read1)
    {
        poly1 = read_polynomial(poly1);
        printf("\n0 for stop 1 for continue\n");
        scanf("%d", &stop_read1);
    }
    printf("\nFirst Polynomial Is: ");
    poly1 = display(poly1);
    printf("\nEnter The Input For Polynomial 2(0 for stop reading the polynomial 2)");
    while (stop_read2)
    {
        poly2 = read_polynomial(poly2);
        printf("\n0 for stop 1 for continue\n");
        scanf("%d", &stop_read2);
    }
    printf("\nSecond  Polynomial Is: ");
    poly2 = display(poly2);

    poly3 = add(poly1, poly2);
    printf("\nResultant  Polynomial Is: ");
    poly3 = display(poly3);
}
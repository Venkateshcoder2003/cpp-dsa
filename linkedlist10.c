#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct player
{
    char name[20];
    char teamname[20];
    float bat_avg;
} p;

typedef struct node
{
    struct player p;
    struct node *next;
} NODE;

NODE *ADD_DETAILS(NODE *head)
{
    NODE *newnode, *temp;
    newnode = (NODE *)malloc(sizeof(NODE));
    printf("Enter Name: \n");
    scanf("%s", newnode->p.name);
    printf("Enter Team Name: \n");
    scanf("%s", newnode->p.teamname);
    printf("Enter Batting Average: \n");
    scanf("%f", &newnode->p.bat_avg);

    newnode->next = NULL;
    temp = head;
    if (head == NULL)
        head = temp = newnode;
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    printf("\nThe Details Of The Player %s Is Added At The End of The List", newnode->p.name);
    return head;
}
NODE *search(NODE *head, const char name[20])
{
    NODE *temp;
    temp = head;
    while (temp != NULL)
    {
        if (strcmp(temp->p.name, name) == 0)
        {
            printf("The Player With Name %s Is Present In The Linked List", name);
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}
void DISPLAY(NODE *head)
{
    if (head == NULL)
    {
        printf("\nLinked List Is Empty\n");
    }
    else
    {
        NODE *temp = head;
        printf("\n%-20s%-20s%-20s\n", "PLAYER NAME", "TEAM NAME", "BATTING AVERAGE");
        while (temp != NULL)
        {
            printf("\n%-20s%-20s%-20f\n", temp->p.name, temp->p.teamname, temp->p.bat_avg);
            temp = temp->next;
        }
    }
}
int main()
{
    int choice;
    NODE *head = NULL, *check;
    char name[20];
    while (1)
    {
        printf("\n1:ADD_DETAILS\n2:SEARCH\n3:DISPLAY_DETAILS\n4EXIT\n");
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            head = ADD_DETAILS(head);
            break;
        case 2:
            printf("\nEnter The Name Of a Player(IN LOWERCASE): ");
            scanf("%s", name);
            check = search(head, name);
            if (check != NULL)
            {
                float newbatavg;
                printf("\nThe Current Batting Average Of Player %s Is %f", check->p.name, check->p.bat_avg);
                printf("\nEnter New Batting Average Of Player %s: ", name);
                scanf("%f", &newbatavg);

                check->p.bat_avg = newbatavg;
                printf("Player %s's Batting Average Has been Updated(PRESS 3 TO CHECK UPDATED LIST)\n", name);
            }
            else
            {
                printf("Player With Name %s Is Not Present In The Linked List", name);
            }
            break;
        case 3:
            DISPLAY(head);
            break;
        case 4:
            exit(0);
        default:
            printf("\nInvalid Choice");
        }
    }
}
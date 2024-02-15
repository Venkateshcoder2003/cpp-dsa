// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// struct student
// {
//     char name[20], USN[20], branch[10];
//     int yoa;
// };

// typedef struct node
// {
//     struct student s;
//     struct node *lptr, *rptr;
// } NODE;
// NODE *ADD_DETAILS(NODE *head)
// {

//     char name[20], usn[10], branch[10];
//     int YOA;
//     NODE *newnode = (NODE *)malloc(sizeof(NODE));
//     newnode->lptr = NULL;
//     printf("\nEnter The Name Of Student: ");
//     scanf("%s", name);
//     strcpy(newnode->s.name, name);
//     printf("\nEnter The USN Of Student: ");
//     scanf("%s", usn);
//     strcpy(newnode->s.USN, usn);
//     printf("\nEnter The BRANCH Of Student: ");
//     scanf("%s", branch);
//     strcpy(newnode->s.branch, branch);
//     printf("\nEnter The  Year Of Admission: ");
//     scanf("%d", &YOA);
//     newnode->s.yoa = YOA;

//     if (head == NULL)
//     {
//         head = newnode;
//         newnode->rptr = NULL;
//     }
//     else
//     {
//         head->lptr = newnode;
//         newnode->rptr = head;
//     }
//     return newnode;
// }
// NODE *DISPLAY(NODE *head)
// {
//     if (head == NULL)
//     {
//         printf("\nLinked List Is Empty");
//         return;
//     }
//     else
//     {
//         NODE *temp = head;
//         printf("\n%-20s%-20s%-20s%-20s\n", "STUDENT NAME", "STUDENT USN", "STUDENT BRANCH", "STUDENT YOA");
//         while (temp != NULL)
//         {
//             printf("%-20s%-20s%-20s%-20d\n", temp->s.name, temp->s.USN, temp->s.branch, temp->s.yoa);
//             temp = temp->rptr;
//         }
//     }
//     return head;
// }
// // NODE *Delete_based_on_USN(NODE *head)
// // {
// //     char usn[20];
// //     NODE *temp = head;
// //     printf("\nEnter The USN: ");
// //     scanf("%s", usn);
// //     if (head == NULL)
// //     {
// //         printf("\nNo Students to delete");
// //         return;
// //     }

// //     else
// //     {
// //         int flag = 0;
// //         while (strcmp(temp->s.USN, usn) != 0)
// //         {
// //             temp = temp->rptr;
// //         }
// //         temp->lptr->rptr = temp->rptr;
// //         if (temp->rptr != NULL)
// //         {
// //             temp->rptr->lptr = temp->lptr;
// //         }
// //         free(temp);
// //     }
// //     return head;
// // }
// NODE *Delete_based_on_USN(NODE *head)
// {
//     char usn[20];
//     NODE *temp = head;

//     printf("\nEnter The USN: ");
//     scanf("%s", usn);

//     if (head == NULL)
//     {
//         printf("\nNo Students to delete");
//         return head;
//     }
//     else
//     {
//         int flag = 0;

//         while (temp != NULL && strcmp(temp->s.USN, usn) != 0)
//         {
//             temp = temp->rptr;
//         }

//         if (temp == NULL)
//         {
//             printf("\nStudent with USN %s not found", usn);
//             return head;
//         }

//         // If the node to be deleted is the head
//         if (temp == head)
//         {
//             head = temp->rptr;
//             if (head != NULL)
//             {
//                 head->lptr = NULL;
//             }
//         }
//         else
//         {
//             temp->lptr->rptr = temp->rptr;
//             if (temp->rptr != NULL)
//             {
//                 temp->rptr->lptr = temp->lptr;
//             }
//         }

//         free(temp);
//     }

//     return head;
// }

// NODE *Display_based_on_branch(NODE *head)
// {
//     char branch1[10];
//     printf("\nEnter The Branch To Delete: ");
//     scanf("%s", branch1);
//     if (head == NULL)
//     {
//         printf("\nLinked List Is Empty");
//         return;
//     }
//     else
//     {
//         NODE *temp = head;
//         int flag = 0;
//         while (temp != NULL)
//         {
//             if (strcmp(temp->s.branch, branch1) == 0)
//             {
//                 printf("%-20s%-20s%-20s%-20d\n", temp->s.name, temp->s.USN, temp->s.branch, temp->s.yoa);
//                 temp = temp->rptr;
//                 flag++;
//             }
//             else
//             {
//                 continue;
//             }
//         }
//         if (flag == 0)
//         {
//             printf("\nFailure, no student from branch %s", branch1);
//         }
//     }
//     return head;
// }
// int main()
// {
//     int choice;
//     NODE *head = NULL;
//     char branch1[10];

//     while (1)
//     {
//         printf("\n1:Add student\n2:Display based on branch\n3:Delete specified USN\n4:Display all\n5:exit\n");
//         printf("\nEnter your choice: ");
//         scanf("%d", &choice);

//         switch (choice)
//         {
//         case 1:
//             head = ADD_DETAILS(head);
//             break;
//         case 2:
//             head = Display_based_on_branch(head);
//             break;
//         case 3:
//             head = Delete_based_on_USN(head);
//         case 4:
//             head = DISPLAY(head);
//             break;
//         case 5:
//             exit(0);
//         default:
//             printf("\nInvalid choice");
//         }
//     }
// }
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    char name[20], USN[20], branch[10];
    int yoa;
};

typedef struct node
{
    struct student s;
    struct node *lptr, *rptr;
} NODE;

// Function to add student details to the linked list
NODE *ADD_DETAILS(NODE *head)
{
    char name[20], usn[20], branch[10];
    int YOA;

    // Allocate memory for a new node
    NODE *newnode = (NODE *)malloc(sizeof(NODE));
    newnode->lptr = NULL;

    // Input student details
    printf("\nEnter The Name Of Student: ");
    scanf("%s", name);
    strcpy(newnode->s.name, name);

    printf("\nEnter The USN Of Student: ");
    scanf("%s", usn);
    strcpy(newnode->s.USN, usn);

    printf("\nEnter The BRANCH Of Student: ");
    scanf("%s", branch);
    strcpy(newnode->s.branch, branch);

    printf("\nEnter The  Year Of Admission: ");
    scanf("%d", &YOA);
    newnode->s.yoa = YOA;

    // Add the new node to the linked list
    if (head == NULL)
    {
        head = newnode;
        newnode->rptr = NULL;
    }
    else
    {
        head->lptr = newnode;
        newnode->rptr = head;
        head = newnode;
    }
    return head;
}

// Function to display all students in the linked list
NODE *DISPLAY(NODE *head)
{
    if (head == NULL)
    {
        printf("\nLinked List Is Empty");
        return head;
    }
    else
    {
        NODE *temp = head;
        printf("\n%-20s%-20s%-20s%-20s\n", "STUDENT NAME", "STUDENT USN", "STUDENT BRANCH", "STUDENT YOA");
        while (temp != NULL)
        {
            printf("%-20s%-20s%-20s%-20d\n", temp->s.name, temp->s.USN, temp->s.branch, temp->s.yoa);
            temp = temp->rptr;
        }
    }
    return head;
}

// Function to delete a student based on USN from the linked list
NODE *Delete_based_on_USN(NODE *head)
{
    char usn[20];
    NODE *temp = head;

    printf("\nEnter The USN: ");
    scanf("%s", usn);

    if (head == NULL)
    {
        printf("\nNo Students to delete");
        return head;
    }
    else
    {
        int flag = 0;

        while (temp != NULL && strcmp(temp->s.USN, usn) != 0)
        {
            temp = temp->rptr;
        }

        if (temp == NULL)
        {
            printf("\nStudent with USN %s not found", usn);
            return head;
        }

        // If the node to be deleted is the head
        if (temp == head)
        {
            head = temp->rptr;
            if (head != NULL)
            {
                head->lptr = NULL;
            }
        }
        else
        {
            temp->lptr->rptr = temp->rptr;
            if (temp->rptr != NULL)
            {
                temp->rptr->lptr = temp->lptr;
            }
        }

        // Free the memory of the node to be deleted
        free(temp);
    }

    return head;
}

// Function to display students based on branch
NODE *Display_based_on_branch(NODE *head)
{
    char branch1[10];
    printf("\nEnter The Branch To Display: ");
    scanf("%s", branch1);

    if (head == NULL)
    {
        printf("\nLinked List Is Empty");
        return head;
    }
    else
    {
        NODE *temp = head;
        int flag = 0;
        printf("\n%-20s%-20s%-20s%-20s\n", "STUDENT NAME", "STUDENT USN", "STUDENT BRANCH", "STUDENT YOA");

        while (temp != NULL)
        {
            if (strcmp(temp->s.branch, branch1) == 0)
            {
                printf("%-20s%-20s%-20s%-20d\n", temp->s.name, temp->s.USN, temp->s.branch, temp->s.yoa);
                temp = temp->rptr;
                flag++;
            }
            else
            {
                temp = temp->rptr;
            }
        }

        if (flag == 0)
        {
            printf("\nNo students from branch %s", branch1);
        }
    }

    return head;
}

int main()
{
    int choice;
    NODE *head = NULL;

    while (1)
    {
        printf("\n1:Add student\n2:Display based on branch\n3:Delete specified USN\n4:Display all\n5:exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            head = ADD_DETAILS(head);
            break;
        case 2:
            head = Display_based_on_branch(head);
            break;
        case 3:
            head = Delete_based_on_USN(head);
            break;
        case 4:
            head = DISPLAY(head);
            break;
        case 5:
            exit(0);
        default:
            printf("\nInvalid choice");
        }
    }
    return 0;
}

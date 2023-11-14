#include <stdio.h>
#include <string.h>

struct car
{
    char name[20];
    int price;
    int model;
};

void Set_Data(struct car c);
void display_data(struct car car1);

int main()
{
    struct car c;
    Set_Data(c);
}

void Set_Data(struct car car1)
{
    char temp[20];
    printf("Enter Car Information: \n");
    printf("Enter Car Name: \n");
    scanf("%s", &temp);
    strcpy(car1.name, temp);
    printf("Enter Car Price: \n");
    scanf("%d", &car1.price);
    printf("Enter Car Model: \n");
    scanf("%d", &car1.model);
    display_data(car1);
}

void display_data(struct car car2)
{
    printf("Diaplaying Car Details: \n");
    printf("CAR NAME: %s\n", car2.name);
    printf("CAR PRICE: %d\n", car2.price);
    printf("CAR MODEL: %d\n", car2.model);
}
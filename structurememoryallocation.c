#include <stdio.h>
#include <string.h>
#pragma pack(1)

struct student
{
    int id1;
    int id2;
    char a;
    char sex;
    float percentage;
};

int main()
{
    struct student record = {1, 2, "VENKI", "MALE", 98.5};
    printf("Size Of Structure Variable Is : %d bytes\n", sizeof(record));

    printf("Address Of id1 is: %u\n", &record.id1);
    printf("Address Of id2 is: %u\n", &record.id2);
    printf("Address of a is: %u\n", &record.a);
    printf("Address Of sex is: %u\n", &record.sex);
    printf("Address Of percentage is: %u\n", &record.percentage);
}
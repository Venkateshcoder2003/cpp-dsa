#include <stdio.h>
#include <string.h>

#pragma pack(1)

struct stu
{
    char a;
    char b;
    int c;
} s;

int main()
{
    printf("Size Of Structure Is: %d", sizeof(s));
}

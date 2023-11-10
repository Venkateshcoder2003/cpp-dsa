#include <stdio.h>
#include <string.h>

#pragma pack(1) // if we not write this line structure padding occurs,if we
// include this line structure packing occurs

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

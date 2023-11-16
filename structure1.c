#include <stdio.h>

struct time
{
    int hour, min, second;
};

struct flight
{
    char name[20];
    struct time t;
};

int main()
{
    struct flight f1, f2;

    printf("Enter Flight 1 Information: \n");
    printf("Enter Flight Name,hour minute and second of Arrival: \n");
    scanf("%s %d %d %d", f1.name, &f1.t.hour, &f1.t.min, &f1.t.second);

    printf("\n");
    printf("Enter Flight 2 Informayion: \n");
    printf("Enter Flight Name ,Hour minute and second of Arrival: \n");
    scanf("%s %d %d %d", f2.name, &f2.t.hour, &f2.t.min, &f2.t.second);

    if (f1.t.hour == f2.t.hour && f1.t.min == f2.t.min && f1.t.second == f2.t.second)
    {
        printf("Both Flights %s and %s will Arrive At Same Time %d:%d:%d", f1.name, f2.name, f1.t.hour, f1.t.min, f1.t.second);
    }
    else
    {
        printf("Both Flights %s and %s Have Different Time Of Arrival %d:%d:%d and %d:%d:%d Respectively", f1.name, f2.name, f1.t.hour, f1.t.min, f1.t.second, f2.t.hour, f2.t.min, f2.t.second);
    }
    return 0;
}
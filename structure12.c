#include <stdio.h>

struct fraction
{
    int num;
    int den;
};
void product_value(struct fraction f1, struct fraction f2, struct fraction f3);
void product_ref(struct fraction *f1, struct fraction *f2, struct fraction *f3);
int main()
{
    struct fraction f1, f2, f3;

    printf("Enter Numerator and Denominator of 1st Fraction : \n");
    scanf("%d%d", &f1.num, &f1.den);

    printf("Enter Numerator and Denominator of 2nd Fraction : \n");
    scanf("%d%d", &f2.num, &f2.den);

    product_value(f1, f2, f3);
    product_ref(&f1, &f2, &f3);
}
void product_value(struct fraction f1, struct fraction f2, struct fraction f3)
{
    f3.num = f1.num * f2.num;
    f3.den = f1.den * f2.den;

    printf("Product Of Two Fraction Using Pass By Value Is: %d/%d\n", f3.num, f3.den);
}
void product_ref(struct fraction *f1, struct fraction *f2, struct fraction *f3)
{
    f3->num = f1->num * f2->num;
    f3->den = f1->den * f2->den;

    printf("Product Of Two Fraction Using Pass By Reference IS: %d/%d", f3->num, f3->den);
}
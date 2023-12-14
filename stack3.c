#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXSIZE 25
typedef struct
{
    char items[MAXSIZE];
    int top;
} STACK;

void PUSH(STACK *s, char data)
{
    s->items[++s->top] = data;
}
char POP(STACK *s)
{
    return (s->items[s->top--]);
}
char PEEK(STACK s)
{
    return (s.items[s.top]);
}
int preced(char sym)
{
    switch (sym)
    {
    case '#':
    case '(':
        return 0;
        break;
    case '+':
    case '-':
        return 1;
        break;
    case '*':
    case '/':
    case '%':
        return 2;
        break;
    case '$':
    case '^':
        return 3;
        break;
    default:
        printf("\nInavlid operator");
    }
}
int main()
{
    STACK s;
    char data, sym, ch;
    s.top = -1;
    int i, p;
    char infix[30], postfix[30];
    printf("\nEnter a valid infix expression : ");
    scanf("%s", infix);
    PUSH(&s, '#');
    for (i = 0; infix[i] != '\0'; i++)
    {
        sym = infix[i];
        if (isalnum(sym))
            postfix[p++] = sym;
        else
        {
            switch (sym)
            {
            case '(':
                PUSH(&s, '(');
                break;
            case ')':
                while ((ch = POP(&s)) != '(')
                {
                    postfix[p++] = ch;
                }
                break;
            default:
                while (preced(sym) <= preced(PEEK(s)))
                {
                    if (sym == PEEK(s) && preced(sym) == 3)
                        break;
                    postfix[p++] = POP(&s);
                }
                PUSH(&s, sym);
            }
        }
    }
    while (PEEK(s) != '#')
    {
        postfix[p++] = POP(&s);
    }
    postfix[p++] = '\0';
    printf("\nResultant postfix expression is : %s", postfix);
    return 0;
}
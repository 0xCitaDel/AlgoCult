#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct stack
{
    int items[MAX];
    int top;
};
typedef struct stack st;

void create_empty_stack(st *s)
{
    s->top = -1;
}

// Check if the stack is full
int isfull(st *s)
{
    if (s->top == MAX - 1)
        return 1;
    else
        return 0;
}

// Check if the stack is empty
int isempty(st *s)
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}

// Add elements into stack
void push(st *s, int data)
{
    if (isfull(s))
        printf("\n STACK FULL \n\n");
    else
    {
        s->top++;
        s->items[s->top] = data;
    }
}

// Remove element from stack
int pop(st *s)
{
    if (isempty(s))
        printf("\n STACK EMPTY \n");
    else
    {
        int res = s->items[s->top];
        printf("Item popped: %d", res);
        s->top--;
    }
    printf("\n");
}

// Print elements of stack
void print_stack(st *s)
{
    printf("Stack: ");
    for (int i = 0; i < s->top; i++)
        printf("%d\t", s->items[i]);
    printf("\n\n");
}

int main()
{
    st stack;
    st *s = &stack;
    create_empty_stack(s);
    push(s, 5);
    push(s, 15);
    push(s, 25);
    push(s, 3);
    push(s, 23);

    push(s, 44);

    print_stack(s);

    pop(s);
    pop(s);
    pop(s);
    pop(s);
    pop(s);
    pop(s);
    pop(s);
    pop(s);

    print_stack(s);

    return 0;
}
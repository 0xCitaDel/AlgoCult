#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef int data;
typedef struct dynamic_stack
{
    data *array;
    int n;
    size_t size;
} stack;

int is_full(stack *s)
{
    if (s->n == s->size - 1)
        return 1;
    else
        return 0;
}

int is_empty(stack *s)
{
    if (s->n == -1)
        return 1;
    else
        return 0;
}

void create_empty_stack(stack *s)
{
    s->array = NULL;
    s->n = -1;
    s->size = 0;
}

void push(stack *s, data data)
{
    if (is_full(s))
    {
        s->size += N;
        s->array = realloc(s->array, sizeof(data) * N);
    }
    s->n++;
    s->array[s->n] = data;
}

data pop(stack *s)
{
    if (is_empty(s))
        printf("\n Stack empty \n");
    else
    {
        data res = s->array[s->n];
        s->n--;
        return res;
    }
}

void display_stack(stack *s)
{
    printf("Stack: ");
    for (int i = 0; i < s->n; i++)
        printf("%d  ", s->array[i]);
    printf("\n");
}

int main()
{
    stack s;
    stack *ps = &s;
    create_empty_stack(ps);
    for (int i = 0; i < 1025; i++)
    {
        push(ps, i + 1);
    }
    display_stack(ps);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define SIZE 6

struct queue
{
    int items[SIZE];
    int rear;
    int front;
};
typedef struct queue queue;

void enqueue(queue *q, int data)
{
    if (q->rear == SIZE - 1)
        printf("\nQueue is Full!!\n");
    else
    {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = data;
        printf("\n Inserted -> %d\n", data);
        printf("\n");
    }
}

int dequeue(queue *q)
{
    if (q->front == -1)
        printf("\n Queue is empty \n");
    else
    {
        int result = q->items[q->front];
        q->front++;
        printf("\n Dequeue: %d \n", result);
        if (q->front > q->rear)
            q->front = q->rear = -1;
        return result;
    }
}

void display(queue *q)
{
    if (q->rear == -1)
        printf("\n Queue is Empty!!! \n");
    else
    {
        printf("Queue elements are: ");
        for (int i = q->front; i <= q->rear; i++)
            printf("%d\t", q->items[i]);
    }
}

int main()
{
    queue qu;
    qu.front = -1;
    qu.rear = -1;
    queue *q = &qu;
 
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    enqueue(q, 6);

    display(q);

    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);


    display(q);

    enqueue(q, 7);
    enqueue(q, 8);
    display(q);





    return 0;
}
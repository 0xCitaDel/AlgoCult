#include <stdio.h>
#include <stdlib.h>

typedef int Data;
typedef struct Node Node;
struct Node {
    Data data;
    Node *next;
};

void printList(Node *list);
void pushList(Node **plist, Data d);

void printList(Node *list){
    for (Node *p = list; p != NULL; p = p->next) {
        printf("%d ", p->data);
    }
    printf("\n");
}

void pushList(Node **plist, Data d){
    Node *p = malloc(sizeof(Node));
    p->data = d;
    p->next = *plist;
    *plist = p;
}

int main() {
    Node *list = NULL;
    Node a = {10}, b = {33}, c = {25};
    list = &a;
    a.next = &b;
    b.next = &c;
    c.next = NULL;

    printList(list);
    pushList(&list, 10);
    printList(list);

    return 0;
}

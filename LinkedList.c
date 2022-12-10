#include <stdio.h>

typedef int Data;
typedef struct Node Node;
struct Node {
    Data data;
    Node *next;
};


int main() {
    Node *list = NULL;
    Node a = {10}, b = {33}, c = {25}, t = {34};
    list = &a;
    a.next = &b;
    b.next = &c;
    c.next = NULL;
    return 0;
}
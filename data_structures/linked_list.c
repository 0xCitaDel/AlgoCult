#include <stdio.h>
#include <stdlib.h>

typedef int Data;
typedef struct Node Node;
struct Node {
    Data data;
    Node *next;
};

void printList(Node *list);
int is_emptyList(Node *list);

void pushList(Node **plist, Data d);
Data popList(Node  **plist);

void printList(Node *list) {
    for (Node *p = list; p != NULL; p = p->next) {
        printf("%d ", p->data);
    }
    printf("\n");
}

void pushList(Node **plist, Data d) {
    Node *p = malloc(sizeof(Node));
    p->data = d;
    p->next = *plist;
    *plist = p;
}

Data popList(Node **plist){
    Node *p = *plist;
    Data res = p->data;
    *plist = p->next;
    free(p);
    return res;
}

int is_emptyList(Node *list) {
    return list == NULL;
}

int main() {
    Data test[] = {21, 5, 77, 44, 6};
    Node *list = NULL;
    printf("Empty: %s\n", is_emptyList(list) ? "YES" : "NO");
    for (size_t i = 0; i < sizeof(test) / sizeof(test[0]); i++) {
        pushList(&list, test[i]);
        printList(list);
    }
    printf("Empty: %s\n", is_emptyList(list) ? "YES" : "NO");

    while (!is_emptyList(list)){
        Data d = popList(&list);
        printf("pop %d :", d);
        printList(list);
    }

    printf("Empty: %s\n", is_emptyList(list) ? "YES" : "NO");
    return 0;
}

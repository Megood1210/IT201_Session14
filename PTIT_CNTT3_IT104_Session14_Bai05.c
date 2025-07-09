#include <stdio.h>
#include <stdlib.h>
// Định nghĩa Node của danh sách liên kết (đơn)
typedef struct Node {
    int data;
    struct Node *next;
}Node;

typedef struct {
    Node* top;
}Stack;

void intitStack(Stack* s) {
    s->top = NULL;
}

Node* creatNewNode( int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = value;
    node->next = NULL;
    return node;
}
void push(Stack* s, int value) {
    Node* newNode = creatNewNode(value);
    newNode->next = s->top;
    s->top = newNode;
}
int peek(Stack* s) {
    if (s->top == NULL) {
        return -1;
    }
    return s->top->data;
}
void printStack(Stack* s) {
    Node* temp = s->top;
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    Stack s;
    intitStack(&s);
    for (int i=1; i<=5; i++) {
        push(&s, i);
    }
    printStack(&s);

    printf("%d", peek(&s));
    return 0;
}

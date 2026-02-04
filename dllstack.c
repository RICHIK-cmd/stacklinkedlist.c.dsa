#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};
struct Node* top = NULL; 
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void push(int data) {
    struct Node* newNode = createNode(data);

    if (top != NULL) {
        newNode->next = top;
        top->prev = newNode;
    }

    top = newNode;
    printf("Pushed %d\n", data);
}
void pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }
    struct Node* temp = top;
    printf("Popped %d\n", temp->data);
    top = top->next;
    if (top != NULL)
        top->prev = NULL;
    free(temp);
}
void peek() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element: %d\n", top->data);
}
void display() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct Node* temp = top;
    printf("Stack (Top to Bottom): ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    push(10);
    push(20);
    push(30);

    display();
    peek();

    pop();
    display();

    return 0;
}

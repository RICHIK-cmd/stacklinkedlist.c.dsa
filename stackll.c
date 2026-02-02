#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
void linkedlisttraversal (struct Node *ptr) {
    while (ptr != NULL){
    printf ("ELEMENT = %d\n", ptr ->data);
    ptr = ptr ->next;
    }
}
int isEmpty(struct Node *top) {
    if (top==NULL){
        return 1;
    }
    else {return 0;}
}
int isFull(struct Node *top){
    struct Node *p = (struct Node *)malloc(sizeof(struct Node ));
    if (p == NULL){
        return 1;
    }
    else {return 0;}
}
struct Node *push(struct Node *top, int x){
    if (isFull(top)){
        printf ("STACK OVERFLOW!\n");
    }
    else {
        struct Node *n = (struct Node *)malloc(sizeof(struct Node ));
        n->data = x;
        n->next=top;
        top=n;
        return n;
    }
}
int pop(struct Node **top){
    if (isEmpty(*top)){
        printf ("STACK UNDERFLOW!\n");
    }
    else {
        struct Node *n =*top;
        *top = (*top)->next;
        int x = n->data;
        free(n);
        return x;
    }
}
int main(){
    struct Node *top = NULL;
    top = push(top, 45);
    top = push(top, 56);
    int element = pop(&top);
    printf("POPPED ELEMENT =%d\n", element);
    linkedlisttraversal(top);
    return 0;
}
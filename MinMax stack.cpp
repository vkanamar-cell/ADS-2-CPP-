#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int stack[MAX];
int minStack[MAX];
int maxStack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }

    top++;
    stack[top] = value;

    if (top == 0 || value < minStack[top - 1])
        minStack[top] = value;
    else
        minStack[top] = minStack[top - 1];

    if (top == 0 || value > maxStack[top - 1])
        maxStack[top] = value;
    else
        maxStack[top] = maxStack[top - 1];

    printf("%d pushed into stack\n", value);
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }

    printf("%d popped from stack\n", stack[top]);
    top--;
}

void getMin() {
    if (top == -1)
        printf("Stack is empty\n");
    else
        printf("Minimum = %d\n", minStack[top]);
}

void getMax() {
    if (top == -1)
        printf("Stack is empty\n");
    else
        printf("Maximum = %d\n", maxStack[top]);
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack: ");
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Min-Max Stack ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Get Minimum\n");
        printf("4. Get Maximum\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                getMin();
                break;

            case 4:
                getMax();
                break;

            case 5:
                display();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

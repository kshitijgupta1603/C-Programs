#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define the Stack structure
typedef struct {
    Node* top;
} Stack;

// Initialize the stack
void initStack(Stack* stack) {
    stack->top = NULL;
}

// Check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// Push an element onto the stack
void push(Stack* stack, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

// Pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow: Cannot pop element, stack is empty.\n");
        return -1;
    }
    int value = stack->top->data;
    Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return value;
}

// Display the stack
void displayStack(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    Node* current = stack->top;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Free all memory used by the stack
void freeStack(Stack* stack) {
    while (!isEmpty(stack)) {
        pop(stack);
    }
}

// Main function
int main() {
    Stack stack;
    initStack(&stack);
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    displayStack(&stack);
    int poppedElement = pop(&stack);
    printf("Popped element: %d\n", poppedElement);
    displayStack(&stack);
    freeStack(&stack);
    return 0;
}

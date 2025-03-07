#include <stdio.h>
#include <stdlib.h>
#include<limits.h>

typedef struct
{
    int* arr;
    int top;
    int capacity;
    int min;
    int max;
} Stack;

void init_stack(Stack* stack, int capacity);
void push(Stack* stack, int data);
void pop(Stack* stack);
int top(Stack* stack);
int getMin(Stack* stack);
int getMax(Stack* stack);
void free_stack(Stack* stack);

int main() 
{
    Stack stack;
    init_stack(&stack, 100);

    int choice, data;
    while (1) 
    {
        printf("\n1. Push\n2. Pop\n3. Top\n4. Get Min\n5. Get Max\n6. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                push(&stack, data);
                break;

            case 2:
                pop(&stack);
                break;

            case 3:
                printf("Top: %d\n", top(&stack));
                break;

            case 4:
                printf("Min: %d\n", getMin(&stack));
                break;

            case 5:
                printf("Max: %d\n", getMax(&stack));
                break;

            case 6:
                free_stack(&stack);
                return 0;

            default:
                printf("Invalid choice, try again.\n");
        }
    }
}

void init_stack(Stack* stack, int capacity) 
{
    stack->arr = (int*)malloc(capacity * sizeof(int));
    stack->top = -1;
    stack->capacity = capacity;
    stack->min = INT_MAX;
    stack->max = INT_MIN;
}

void push(Stack* stack, int data) 
{
    if (stack->top == stack->capacity - 1) 
        return;

    stack->arr[++stack->top] = data;

    if (stack->top == 0) 
    {
        stack->min = data;
        stack->max = data;
    } 
    else 
    {
        if (data < stack->min) 
            stack->min = data;

        if (data > stack->max) 
            stack->max = data;
    }
}

void pop(Stack* stack) 
{
    if (stack->top == -1) 
        return;

    int popped = stack->arr[stack->top--];

    if (stack->top == -1) 
    {
        stack->min = INT_MAX;
        stack->max = INT_MIN;
    } 
    else 
    {
        stack->min = stack->arr[0];
        stack->max = stack->arr[0];

        for (int i = 1; i <= stack->top; i++) 
        {
            if (stack->arr[i] < stack->min) 
                stack->min = stack->arr[i];

            if (stack->arr[i] > stack->max) 
                stack->max = stack->arr[i];
        }
    }
}

int top(Stack* stack) 
{
    if (stack->top != -1) 
        return stack->arr[stack->top];
    return -1;
}

int getMin(Stack* stack) 
{
    if (stack->top != -1) 
        return stack->min;
    return -1;
}

int getMax(Stack* stack) 
{
    if (stack->top != -1) 
        return stack->max;
    return -1;
}

void free_stack(Stack* stack) 
{
    free(stack->arr);
}

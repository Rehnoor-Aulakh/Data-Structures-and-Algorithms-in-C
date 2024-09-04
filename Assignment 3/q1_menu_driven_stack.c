#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Stack
{
    int capacity;
    int top;
    int *a;
};

struct Stack* createStack(int capacity)
{
    struct Stack *st = malloc(sizeof(struct Stack));
    st->capacity = capacity;
    st->top = -1;
    st->a = malloc(sizeof(int) * capacity);
    printf("Stack Created Successfully\n");
    return st;
}

int isEmpty(struct Stack *st)
{
    return (st->top == -1);
}

int isFull(struct Stack *st)
{
    return (st->top == st->capacity - 1);
}

void push(struct Stack *st, int val)
{
    if (isFull(st))
    {
        printf("Stack Overflow!!!\n");
        return;
    }
    st->top++;
    st->a[st->top] = val;
    printf("%d inserted\n", val);
}

int pop(struct Stack *st)
{
    if (isEmpty(st))
    {
        printf("Stack Underflow\n");
        return INT_MIN;
    }
    int val = st->a[st->top];
    st->top--;
    return val;
}

int peek(struct Stack *st)
{
    if (isEmpty(st))
    {
        printf("Stack Underflow\n");
        return INT_MIN;
    }
    return st->a[st->top];
}

void displayRecursive(struct Stack *st)
{
    if (isEmpty(st))
    {
        printf("\n");
        return;
    }
    int val = pop(st);
    printf("%d ", val);
    displayRecursive(st);
    push(st, val);
}

void freeStack(struct Stack *st)
{
    free(st->a);
    free(st);
}

int main()
{
    struct Stack *st = NULL;  // Initialize stack pointer to NULL

    while (1)
    {
        printf("Press 1 to Create Stack\n");
        printf("Press 2 to Push\n");
        printf("Press 3 to Pop\n");
        printf("Press 4 to Check if stack is empty\n");
        printf("Press 5 to Check if stack is full\n");
        printf("Press 6 to Display\n");
        printf("Press 7 to Peek\n");
        printf("Press 8 to Exit\n");
        int choice;
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        printf("\n");

        if (choice == 8)
        {
            if (st != NULL) freeStack(st); // Free allocated memory before exiting
            break;
        }

        switch (choice)
        {
            case 1:
            {
                if (st != NULL) freeStack(st); // Free old stack if re-creating
                printf("Enter Capacity of Stack: ");
                int capacity;
                scanf("%d", &capacity);
                st = createStack(capacity);
                break;
            }
            case 2:
            {
                if (st != NULL && !isFull(st))
                {
                    printf("Enter the element you want to push: ");
                    int val;
                    scanf("%d", &val);
                    push(st, val);
                    printf("\n%d pushed successfully\n", val);
                }
                else
                {
                    printf("Stack Overflow or Stack not created!!!\n");
                }
                break;
            }
            case 3:
            {
                if (st != NULL && !isEmpty(st))
                {
                    int popped = pop(st);
                    if (popped != INT_MIN)
                        printf("Element Popped Successfully: %d\n", popped);
                }
                else
                {
                    printf("Stack Underflow or Stack not created!!!\n");
                }
                break;
            }
            case 4:
            {
                if (st != NULL)
                {
                    if (isEmpty(st))
                    {
                        printf("Stack is Empty\n");
                    }
                    else
                    {
                        printf("Stack is not Empty\n");
                    }
                }
                else
                {
                    printf("Stack not created!!!\n");
                }
                break;
            }
            case 5:
            {
                if (st != NULL)
                {
                    if (isFull(st))
                    {
                        printf("Stack is Full\n");
                    }
                    else
                    {
                        printf("Stack is not full\n");
                    }
                }
                else
                {
                    printf("Stack not created!!!\n");
                }
                break;
            }
            case 6:
            {
                if (st != NULL)
                {
                    printf("Displaying Stack:\n");
                    displayRecursive(st);
                }
                else
                {
                    printf("Stack not created!!!\n");
                }
                break;
            }
            case 7:
            {
                if (st != NULL)
                {
                    int topVal = peek(st);
                    if (topVal != INT_MIN)
                        printf("Top Element: %d\n", topVal);
                }
                else
                {
                    printf("Stack not created!!!\n");
                }
                break;
            }
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}

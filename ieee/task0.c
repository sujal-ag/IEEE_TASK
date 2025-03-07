#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *prev, *next;
} Node;

typedef struct LinkedList
{
    Node *head, *tail;
} LinkedList;

void init_linkedlist(LinkedList *list);
Node *create_node(int data);
void insert_head(LinkedList *list, int data);
void insert_tail(LinkedList *list, int data);
void print_forward(LinkedList *list);
void print_backward(LinkedList *list);
void free_list(LinkedList *list);

int main()
{
    LinkedList list;
    init_linkedlist(&list);

    int choice, data;
    while (1)
    {
        printf("\n1. Insert at Head\n2. Insert at Tail\n3. Print Forward\n4. Print Backward\n5. Exit\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter data: ");
            scanf("%d", &data);
            insert_head(&list, data);
        }
        else if (choice == 2)
        {
            printf("Enter data: ");
            scanf("%d", &data);
            insert_tail(&list, data);
        }
        else if (choice == 3)
            print_forward(&list);
        else if (choice == 4)
            print_backward(&list);
        else if (choice == 5)
        {
            free_list(&list);
            return 0;
        }
        else
            printf("Invalid choice, try again.\n");
    }
}

void init_linkedlist(LinkedList *list)
{
    list->head = list->tail = NULL;
}

Node *create_node(int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (!new_node) return NULL;

    new_node->data = data;
    new_node->prev = new_node->next = NULL;
    return new_node;
}

void insert_head(LinkedList *list, int data)
{
    Node *new_node = create_node(data);
    if (!new_node) return;

    if (!list->head)
        list->head = list->tail = new_node;
    else
    {
        new_node->next = list->head;
        list->head->prev = new_node;
        list->head = new_node;
    }
}

void insert_tail(LinkedList *list, int data)
{
    Node *new_node = create_node(data);
    if (!new_node) return;

    if (!list->tail)
        list->head = list->tail = new_node;
    else
    {
        new_node->prev = list->tail;
        list->tail->next = new_node;
        list->tail = new_node;
    }
}

void print_forward(LinkedList *list)
{
    Node *temp = list->head;
    printf("Forward: ");

    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void print_backward(LinkedList *list)
{
    Node *temp = list->tail;
    printf("Backward: ");

    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

void free_list(LinkedList *list)
{
    Node *temp = list->head;
    while (temp)
    {
        Node *next = temp->next;
        free(temp);
        temp = next;
    }
    list->head = list->tail = NULL;
}

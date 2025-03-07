#include <stdio.h>
#include <stdlib.h>

typedef struct Interval
{
    int start, end;
    struct Interval* next;
} Interval;

Interval* createInterval(int start, int end);
void addInterval(int start, int end);
void getIntervals();

Interval* head = NULL;

int main()
{
    addInterval(1, 5);
    addInterval(6, 8);
    addInterval(4, 7);
    getIntervals();
    return 0;
}

Interval* createInterval(int start, int end)
{
    Interval* newNode = (Interval*)malloc(sizeof(Interval));
    newNode->start = start;
    newNode->end = end;
    newNode->next = NULL;
    return newNode;
}

void addInterval(int start, int end)
{
    Interval* curr = head, *prev = NULL;
    
    while (curr && curr->end < start)
    {
        prev = curr;
        curr = curr->next;
    }
    
    while (curr && curr->start <= end)
    {
        start = start < curr->start ? start : curr->start;
        end = end > curr->end ? end : curr->end;
        Interval* temp = curr;
        curr = curr->next;
        free(temp);
    }
    
    Interval* newNode = createInterval(start, end);
    newNode->next = curr;
    
    if (prev)
        prev->next = newNode;
    else
        head = newNode;
}

void getIntervals()
{
    Interval* temp = head;
    printf("[");
    while (temp)
    {
        printf("[%d, %d]", temp->start, temp->end);
        temp = temp->next;
        if (temp) printf(", ");
    }
    printf("]\n");
}
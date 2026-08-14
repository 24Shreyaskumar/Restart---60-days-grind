#include <stdio.h>
#include <stdlib.h>
#define allocate_mem (struct Node *)malloc(sizeof(struct Node))

struct Node
{
    int val;
    struct Node *next;
};

struct Node *reverse(struct Node *head)
{
    struct Node *cur = head;
    struct Node *prev = NULL;

    while (cur)
    {
        struct Node *next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    return prev;
}

void printList(struct Node *head)
{
    struct Node *it = head;
    while (it)
    {
        printf("%d ", it->val);
        it = it->next;
    }
    printf("\n");
    return;
}

void freeList(struct Node *head)
{
    while (head)
    {
        struct Node *next = head;
        free(head);
        head = next;
    }
    return;
}

int main()
{
    struct Node *head = allocate_mem;
    head->val = 0;
    head->next = NULL;
    struct Node *cur = head;

    for (int i = 1; i <= 5; i++)
    {
        struct Node *node = allocate_mem;
        node->val = i;
        node->next = NULL;
        cur->next = node;
        cur = node;
    }

    head = reverse(head);
    printList(head);
    freeList(head);

    return 0;
}
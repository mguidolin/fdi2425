#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

int list2array(struct Node* head, int *output);

void print_array(int *array, int size);
void print_list(struct Node* head);
struct Node* new_node(int data);
void free_list(struct Node* head);

struct Node* insert_head(struct Node* head, int data);
void insert_after(struct Node* prev, int data);
struct Node* insert_tail(struct Node* head, int data);

int main()
{
    struct Node* head = NULL;
    head = insert_tail(head, 21);
    head = insert_tail(head, -55);
    head = insert_tail(head, 69);
    head = insert_tail(head, -14);

    printf("Input list:  ");
    print_list(head);

    int output[100];
    int size = list2array(head, output);

    printf("Output array: ");
    print_array(output, size);

    free_list(head);
    return 0;
}

int list2array(struct Node* head, int *output)
{
    // variable to keep track of the number of copied elements
    int cnt = 0;

    while (head != NULL)
    {
        // copy the node's data into the array
        output[cnt++] = head->data;
        // move to the next node
        head = head->next;
    }

    return cnt;
}

void print_array(int *array, int size)
{
    printf("[ ");
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("]\n");
}

void print_list(struct Node* head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

struct Node* new_node(int data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));

    if (node != NULL)
    {
        node->data = data;
        node->next = NULL;
    }

    return node;
}

void free_list(struct Node* head)
{
    while (head != NULL)
    {
        struct Node* tmp = head;
        head = head->next;
        free(tmp);
    }
}

struct Node* insert_head(struct Node* head, int data)
{
    struct Node* new_head = new_node(data);
    new_head->next = head;

    return new_head;
}

void insert_after(struct Node* prev, int data)
{
    if (prev == NULL)
    {
        return;
    }

    struct Node* node = new_node(data);
    node->next = prev->next;
    prev->next = node;
}

struct Node* insert_tail(struct Node* head, int data)
{
    if (head == NULL)
    {
        return new_node(data);
    }

    struct Node* last = head;
    while (last->next != NULL)
    {
        last = last->next;
    }

    insert_after(last, data);
    return head;
}

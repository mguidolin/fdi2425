#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    double data;
    struct Node* next;
};

bool min_data_list(struct Node *head , double* min);
bool max_data_list(struct Node *head , double* max);
void normalize_list(struct Node *head , double min , double max);

void print_list(struct Node* head);
struct Node* new_node(double data);
void free_list(struct Node* head);

struct Node* insert_head(struct Node* head, double data);
void insert_after(struct Node* prev, double data);
struct Node* insert_tail(struct Node* head, double data);

int main()
{
    struct Node* head = NULL;
    head = insert_tail(head, 2.1);
    head = insert_tail(head, -5.5);
    head = insert_tail(head, 6.9);
    head = insert_tail(head, -1.4);

    printf("Original list:   ");
    print_list(head);

    double min, max;
    min_data_list(head, &min);
    max_data_list(head, &max);

    normalize_list(head, min, max);

    printf("Normalized list: ");
    print_list(head);

    free_list(head);
    return 0;
}

bool min_data_list(struct Node *head , double* min)
{
    if (head == NULL)
    {
        return false;
    }

    *min = head->data;
    while (head != NULL)
    {
        if (head->data < *min)
        {
            *min = head->data;
        }
        head = head->next;
    }
    return true;
}

bool max_data_list(struct Node *head , double* max)
{
    if (head == NULL)
    {
        return false;
    }

    *max = head->data;
    while (head)
    {
        if (head->data > *max)
        {
            *max = head->data;
        }
        head = head->next;
    }
    return true;
}

void normalize_list(struct Node *head , double min , double max)
{
    if (head == NULL || min == max)
    {
        return;
    }

    while (head != NULL)
    {
        head->data = (head->data - min) / (max - min);
        head = head->next;
    }
}

void print_list(struct Node* head)
{
    while (head != NULL)
    {
        printf("%.2f -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

struct Node* new_node(double data)
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

struct Node* insert_head(struct Node* head, double data)
{
    struct Node* new_head = new_node(data);
    new_head->next = head;

    return new_head;
}

void insert_after(struct Node* prev, double data)
{
    if (prev == NULL)
    {
        return;
    }

    struct Node* node = new_node(data);
    node->next = prev->next;
    prev->next = node;
}

struct Node* insert_tail(struct Node* head, double data)
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

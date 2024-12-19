#include <stdio.h>
#include <stdlib.h>

// #define DEBUG

struct Node
{
    int value;
    struct Node* next;
};

void print_list(struct Node* head);
struct Node* new_node(int value);

struct Node* insert_head(struct Node* head, int value);
void insert_after(struct Node* prev, int value);
struct Node* insert_tail(struct Node* head, int value);

struct Node* remove_head(struct Node* head);
void remove_after(struct Node* prev);
struct Node* remove_tail(struct Node* head);

void delete_list(struct Node* head);
struct Node* find_node(struct Node* head, int value);

int main()
{
    struct Node* head = new_node(10);
    print_list(head);

    head = insert_head(head, 20);
    print_list(head);

    insert_after(head->next, 30);
    print_list(head);

    head = insert_tail(head, 40);
    print_list(head);

    head = insert_tail(head, 50);
    print_list(head);

    head = insert_tail(head, 60);
    print_list(head);

    head = insert_tail(head, 70);
    print_list(head);

    remove_after(head);
    print_list(head);

    remove_after(find_node(head, 42));
    print_list(head);

    remove_after(find_node(head, 50));
    print_list(head);

    head = remove_head(head);
    print_list(head);

    head = remove_tail(head);
    print_list(head);

    delete_list(head);

    return 0;
}

void print_list(struct Node* head)
{
    while (head != NULL)
    {
#ifdef DEBUG
        printf("(%p -> %p) ", head, head->next);
#endif
        printf("%d -> ", head->value);
        head = head->next;
    }
    printf("NULL\n");
}

struct Node* new_node(int value)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));

    if (node != NULL)
    {
        node->value = value;
        node->next = NULL;
    }

    return node;
}

struct Node* insert_head(struct Node* head, int value)
{
    struct Node* new_head = new_node(value);
    new_head->next = head;

    return new_head;
}

void insert_after(struct Node* prev, int value)
{
    if (prev == NULL)
    {
        return;
    }

    struct Node* node = new_node(value);
    node->next = prev->next;
    prev->next = node;
}

struct Node* insert_tail(struct Node* head, int value)
{
    if (head == NULL)
    {
        return insert_head(head, value);
    }

    struct Node* last = head;
    while (last->next != NULL)
    {
        last = last->next;
    }

    insert_after(last, value);

    return head;
}

struct Node* remove_head(struct Node* head)
{
    if (head == NULL)
    {
        return NULL;
    }

    struct Node* old_head = head;
    head = head->next;

    free(old_head);

    return head;
}

void remove_after(struct Node* prev)
{
    if (prev == NULL || prev->next == NULL)
    {
        return;
    }

    struct Node* node_to_remove = prev->next;
    prev->next = node_to_remove->next;

    free(node_to_remove);
}

struct Node* remove_tail(struct Node* head)
{
    if (head == NULL)
    {
        return NULL;
    }

    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }

    struct Node* tail = head;
    struct Node* prev = NULL;
    while (tail->next != NULL)
    {
        prev = tail;
        tail = tail->next;
    }

    remove_after(prev);

    return head;
}

void delete_list(struct Node* head)
{
    struct Node* current = NULL;

    while (head != NULL)
    {
        current = head;
        head = head->next;
#ifdef DEBUG
        printf("Free node @ %p: (value = %d, next = %p)\n", current, current->value, current->next);
#endif

        free(current);
    }
}

struct Node* find_node(struct Node* head, int value)
{
    while (head != NULL)
    {
        if (head->value == value)
        {
            return head;
        }

        head = head->next;
    }

    return NULL;
}

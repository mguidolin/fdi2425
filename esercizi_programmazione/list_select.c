#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* list_select(struct Node *data_head, struct Node *pos_head);

void print_list(struct Node* head);
struct Node* new_node(int data);
void free_list(struct Node* head);

struct Node* insert_head(struct Node* head, int data);
void insert_after(struct Node* prev, int data);
struct Node* insert_tail(struct Node* head, int data);

int main()
{
    struct Node* data_head = NULL;
    data_head = insert_tail(data_head, 21);
    data_head = insert_tail(data_head, -55);
    data_head = insert_tail(data_head, 69);
    data_head = insert_tail(data_head, -14);

    struct Node* pos_head = NULL;
    pos_head = insert_tail(pos_head, 3);
    pos_head = insert_tail(pos_head, 0);

    printf("Input data list: ");
    print_list(data_head);
    printf("Input pos list:  ");
    print_list(pos_head);

    struct Node* sel_head = list_select(data_head, pos_head);

    printf("Output list:    ");
    print_list(sel_head);

    free_list(data_head);
    free_list(pos_head);
    free_list(sel_head);
    return 0;
}

struct Node* list_select(struct Node *data_head, struct Node *pos_head)
{
    // if either list is empty, return NULL
    if (data_head == NULL || pos_head == NULL)
    {
        return NULL;
    }

    // pointer to the head of the new list to return
    struct Node* new_head = NULL;

    // iterate through the pos_head list
    while (pos_head != NULL)
    {
        // iterate through the data_head list until reaching the node corresponding to the specified index
        int idx = pos_head->data;
        struct Node* node_to_add = data_head;
        for (int i = 0; i < idx; ++i)
        {
            node_to_add = node_to_add->next;
        }

        // insert the selected node's data into the new list
        new_head = insert_tail(new_head, node_to_add->data);
        // move to the next position
        pos_head = pos_head->next;
    }

    return new_head;
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

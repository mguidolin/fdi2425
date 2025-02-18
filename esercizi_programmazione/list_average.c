#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

float get_list_average(struct Node* head);
struct Node* list_average(struct Node *head);

void print_list(struct Node* head);
struct Node* new_node(int data);
void free_list(struct Node* head);

struct Node* insert_head(struct Node* head, int data);
void insert_after(struct Node* prev, int data);
struct Node* insert_tail(struct Node* head, int data);

int main()
{
    struct Node* head1 = NULL;
    head1 = insert_tail(head1, 21);
    head1 = insert_tail(head1, -55);
    head1 = insert_tail(head1, 69);
    head1 = insert_tail(head1, -14);

    struct Node* avg1 = list_average(head1);

    printf("Input list:  ");
    print_list(head1);
    printf("Output list: ");
    print_list(avg1);

    struct Node* head2 = NULL;
    head2 = insert_tail(head2, 2);
    head2 = insert_tail(head2, 2);
    head2 = insert_tail(head2, 0);

    struct Node* avg2 = list_average(head2);

    printf("Input list:  ");
    print_list(head2);
    printf("Output list: ");
    print_list(avg2);

    free_list(head1);
    free_list(avg1);
    free_list(head2);
    free_list(avg2);
    return 0;
}

float get_list_average(struct Node* head)
{
    if (head == NULL)
    {
        return 0.;
    }

    // variables to store sum and number of elements
    int sum = 0;
    int cnt = 0;
    // iterate through the list
    while (head != NULL)
    {
        // add current node's value to the same
        sum += head->data;
        // increase the node counter
        ++cnt;
        // move to the next node
        head = head->next;
    }

    // return the computed average as a float
    return (float)sum / cnt;
}

struct Node* list_average(struct Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    // compute the average of the list
    float avg = get_list_average(head);
    // initialize the new list to return
    struct Node* new_head = NULL;

    // iterate through the input list
    while (head != NULL)
    {
        // if the node's value is greater than the average...
        if (head->data > avg)
        {
            // ... add it to the new list
            new_head = insert_tail(new_head, head->data);
        }
        // move to the next node
        head = head->next;
    }

    // return the filtered list
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

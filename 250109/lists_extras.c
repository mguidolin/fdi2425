#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

int sum_list(struct Node* head);
struct Node* square_list(struct Node* head);
struct Node* merge_lists(struct Node* head1, struct Node* head2);
struct Node* order_list(struct Node* head);
struct Node* deep_copy_list(struct Node* head);

int main()
{
    struct Node* head2 = new_node(100);

    // create a new list
    struct Node* list = new_node(10);

    // populate with some values and print it
    list = insert_head(list, 2);
    list = insert_tail(list, 4);
    list = insert_tail(list, 5);
    list = insert_tail(list, 6);
    list = insert_tail(list, 7);
    printf("List values: ");
    print_list(list);

    // sum of the list values
    int sum = sum_list(list);
    printf("The sum of the values is: %d\n", sum);

    // new list with squared elements
    struct Node* squared = square_list(list);
    printf("Squared list: ");
    print_list(squared);

    // create a new list
    struct Node* list2 = new_node(-2);

    // populate with some values and print it
    list2 = insert_head(list2, -7);
    list2 = insert_tail(list2, 3);
    list2 = insert_tail(list2, -5);
    list2 = insert_head(list2, 0);
    printf("\nList2 values: ");
    print_list(list2);

    // merging lists
    struct Node* merged = merge_lists(list, list2);
    printf("\nMerged list: ");
    print_list(merged);
    // print also list values to check it is not modified
    printf("List values: ");
    print_list(list);

    // organize list, before even, after odd
    struct Node* ordered = order_list(merged);
    printf("\nList ordered: ");
    print_list(ordered);
    ordered = order_list(squared);
    printf("Squared ordered: ");
    print_list(ordered);

    // clear memory
    delete_list(list);
    delete_list(list2);
    delete_list(squared);
    delete_list(merged);
    delete_list(ordered);

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

// returns the sum of all the values in the list
int sum_list(struct Node* head)
{
    int sum = 0;

    while(head != NULL)
    {
        sum += head->value;
        head = head->next;
    }

    return sum;
}

// returns a new list with squared values
struct Node* square_list(struct Node* head)
{
    struct Node* new_head = NULL;

    while(head != NULL)
    {
        new_head = insert_tail(new_head, pow(head->value, 2));
        head = head->next;
    }

    return new_head;
}

// merges two lists attacching head2 to the tail of head1
struct Node* merge_lists(struct Node* head1, struct Node* head2)
{
    // head1 is a copy of the original list pointer. So the list pointer in main
    // will point to the same address after the function, even though we cycle to
    // the tail of list

    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    // // *** version 1 ***
    // // here head_merged will point to the same address as the original head1 (list from main).
    // // Therefore, all the changes to head_merged will be the same also for list
    // struct Node* head_merged = head1;

    // while (head1->next != NULL)
    // {
    //     head1 = head1->next;
    // }

    // head1->next = head2;

    // *** version 2 ***
    // instead of pointing to the same address as head1, make a deep copy of it
    struct Node* head1_copy = deep_copy_list(head1);

    // let's create a deep copy also for head2, to keep things separate
    // if we don't make a deep copy, code will work anyway but we will have
    // segmentation fault issues when deleting lists in main()
    struct Node* head2_copy = deep_copy_list(head2);

    // go to head1_copy tail and attach head2
    struct Node* head_merged = head1_copy;
    while (head1_copy->next != NULL)
    {
        head1_copy = head1_copy->next;
    }

    head1_copy->next = head2_copy;

    return head_merged;
}

// organize list, before even, after odd
struct Node* order_list(struct Node* head)
{
    struct Node* even_list = NULL; //even numbers
    struct Node* odd_list = NULL; //odd numbers

    while(head != NULL)
    {
        // *** version 1 ***
        // if (head->value %2 == 0)
        // {
        //     even_list = insert_tail(even_list, head->value);
        // }
        // else
        // {
        //     odd_list = insert_tail(odd_list, head->value);
        // }

        // *** version 2 ***
        (head->value % 2 == 0) ? (even_list = insert_tail(even_list, head->value)) : (odd_list = insert_tail(odd_list, head->value));

        head = head->next;
    }

    return merge_lists(even_list, odd_list);
}

// create a deep copy of a list
struct Node* deep_copy_list(struct Node* head)
{
    struct Node* head_copy = NULL;

    while (head!= NULL)
    {
        head_copy = insert_tail(head_copy, head->value);
        head = head->next;
    }

    return head_copy;
}

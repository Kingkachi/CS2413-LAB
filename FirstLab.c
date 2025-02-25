#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode *current = &dummy;

    while (current->next != NULL) {
        if (current->next->val == val) {
            current->next = current->next->next;
        } else {
            current = current->next;
        }
    }
    return dummy.next;
}

// Helper function to create a linked list (for testing)
struct ListNode* createLinkedList(int arr[], int size) {
    struct ListNode *head = NULL;
    struct ListNode *tail = NULL;
    for (int i = 0; i < size; i++) {
        struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = arr[i];
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

// Helper function to print a linked list (for testing)
void printLinkedList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Example usage
    int arr[] = {1, 2, 6, 3, 4, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    struct ListNode* head = createLinkedList(arr, size);

    printf("Original list: ");
    printLinkedList(head);

    int valToRemove = 6;
    head = removeElements(head, valToRemove);

    printf("List after removing %d: ", valToRemove);
    printLinkedList(head);

    // Clean up memory (important to avoid memory leaks)
    struct ListNode* current = head;
    while (current != NULL) {
        struct ListNode* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}

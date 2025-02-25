#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode dummy = {0, head}; 
    struct ListNode* prev = &dummy;

    while (head) {
        if (head->val != val) {
            prev->next = head;
            prev = head;
        }
        head = head->next;
    }
    prev->next = NULL;
    return dummy.next;
}

// Helper function to create a node
struct ListNode* createNode(int val) {
    struct ListNode* node = malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Helper function to print the list
void printList(struct ListNode* head) {
    while (head) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(6);
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(4);
    head->next->next->next->next->next = createNode(5);
    head->next->next->next->next->next->next = createNode(6);

    printf("Original List: ");
    printList(head);

    head = removeElements(head, 6);

    printf("After Removal: ");
    printList(head);

    return 0;
}

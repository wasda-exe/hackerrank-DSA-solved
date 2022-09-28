

/*
 * Complete the 'reverse' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts INTEGER_SINGLY_LINKED_LIST llist as parameter.
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
typedef SinglyLinkedListNode Node;
SinglyLinkedListNode* reverse(SinglyLinkedListNode* head) {
    if (head == NULL) {
        return head;
    }
    // Node * ptr, *next, *temp;
    Node * ptr = head;
    Node * next = head->next;
    head->next = NULL;
    while (next->next != NULL) {
        Node * temp = next->next;
        next->next = ptr;
        ptr = next;
        next = temp;
    }
    next->next = ptr;
    return next;
}




// Complete the insertNodeAtHead function below.

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
SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* llist, int data) {
    Node * newHead = new Node(data);
    nullptr_t nothing;
    if(llist != nothing)
    {
    newHead->next = llist;
    // llist = newHead;
    }
    return newHead;
}


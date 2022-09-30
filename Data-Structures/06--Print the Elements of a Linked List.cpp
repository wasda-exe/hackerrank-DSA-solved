

// Complete the printLinkedList function below.

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
void printLinkedList(SinglyLinkedListNode* head) {
    Node * ptr = head;
    while(ptr != nullptr)
    {
    cout << ptr->data << endl;
    ptr = ptr->next;
    }
}


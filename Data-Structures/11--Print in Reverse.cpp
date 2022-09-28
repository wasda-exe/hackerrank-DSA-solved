

/*
 * Complete the 'reversePrint' function below.
 *
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
void reversePrint(SinglyLinkedListNode* head) {
    if(head == nullptr)
        return;
    reversePrint(head->next);
    cout << head->data << endl;
}


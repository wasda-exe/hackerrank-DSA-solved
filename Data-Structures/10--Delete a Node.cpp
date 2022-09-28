

/*
 * Complete the 'deleteNode' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST llist
 *  2. INTEGER position
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

SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int pos) {
    if(head == nullptr)
        return nullptr;
    int curr = -1;
    Node *ptr = head, *prev = head;
    while (ptr != nullptr) {
        curr++;
        cout << curr << endl;
        if(pos == 0)
        {
            return ptr->next;
        }
        if (curr == pos) {
            prev->next = ptr->next;
            // delete ptr;
            ptr = prev->next;
            cout << "meow" << ptr->data << endl;
            return head;
        }
        prev = ptr;
        ptr = ptr->next;
    }
    return head;
}


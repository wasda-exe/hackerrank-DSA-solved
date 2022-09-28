

// Complete the insertNodeAtTail function below.

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
SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
    Node * temp = new Node(data), *ptr = head;
    
    if(head == nullptr)
    {
        return temp; // can't add anything to a given NULL
    }
    else
    while(ptr->next != nullptr)
    {
        ptr=ptr->next;
    }
    ptr->next = temp;
    return head;
}


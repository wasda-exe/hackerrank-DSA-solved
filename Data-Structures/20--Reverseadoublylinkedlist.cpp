// void swapNodePtr(&rA, &rB)
// {
//     DoublyLinkedListNode *temp = rA;
//     rA = rB;
//     rB = temp;
// }
typedef DoublyLinkedListNode Node;
// v1 pointer logic
DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) {
    // swapNodePtr(prev, next);
    auto itr = llist;
    Node* prev = nullptr;
    while(itr != nullptr)
    {
        // hackerrank is drunk. functions don't work rn.
    Node *temp = itr->prev;
    itr->prev = itr->next;
    itr->next = temp;
        prev = itr;
        itr = itr->prev;
    }
    return prev;
}

// v2 recursive. kinda off the whole doubly linked list tho
DoublyLinkedListNode* reverse(DoublyLinkedListNode* head) {
    if(head == nullptr)
    {
        return nullptr;
    }
    Node *temp = head->prev;
    head->prev = head->next;
    head->next = temp;
    // if previous now equals nullptr, then this is the newhead
    if(head->prev == nullptr)
    {
        return head;
    }
    // if we never encountered new head, simply pass to head->prev
    return reverse(head->prev);
}

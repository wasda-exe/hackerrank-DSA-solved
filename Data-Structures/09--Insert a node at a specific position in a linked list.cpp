

/*
 * Complete the 'insertNodeAtPosition' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST llist
 *  2. INTEGER data
 *  3. INTEGER position
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
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    Node * temp = new Node(data), *ptr = llist;
    // int curr = 0;
    int curr = 0;
    if(llist == nullptr)
        return temp;
    if(position == 0)
    {
        temp->next = llist;
        return temp;
    }
    for (; curr < position - 1; curr++) {
        ptr = ptr->next;
        // NO
        // always leaves ptr on value equiv to pos ++curr
        // now leaves on one before
    }
    temp->next = ptr->next;
    ptr->next = temp;
    return llist;
}


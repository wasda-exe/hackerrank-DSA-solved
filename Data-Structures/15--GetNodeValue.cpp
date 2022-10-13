

/*
 * Complete the 'getNode' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST llist
 *  2. INTEGER positionFromTail
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
// v1 iterative
typedef SinglyLinkedListNode Node;
int getNode(SinglyLinkedListNode* llist, int positionFromTail) {
    int pos = positionFromTail;
    auto curr = llist;
    vector <int> vnSeen;
    while(curr != nullptr)
    {
        vnSeen.push_back(curr->data);
        curr = curr->next;
    }
    // n - 1 - i
    return vnSeen[vnSeen.size() - 1 - pos];    
}

// v2 recursive
int getNode(SinglyLinkedListNode* llist, int positionFromTail) {
    static int currPositionFromTail;
    if (llist == nullptr) {
        return 0;
    }
    if (llist->next == nullptr) {
        currPositionFromTail = 0;
        return llist->data;
    }
    int val = getNode(llist->next, positionFromTail);
    currPositionFromTail++;
    if (currPositionFromTail == positionFromTail) {
        return llist->data;
    }
    return val;
}

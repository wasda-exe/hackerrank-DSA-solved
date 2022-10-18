/*
 * Complete the 'removeDuplicates' function below.
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
// for args passed, links the passed node to it's next node;

// v2 recursive
Node* nextNodeAttached(Node *head, int prevVal)
{
    if(head == nullptr)
        return nullptr;
    Node *nextGoodNode;
    // curr node may be good or bad.
    // accordingly, we will consider whether head will
    // be allowed to get taken into list 
    // i.e., if we will be determining what head's next is now
    // instead of skipping past head, and asking what
    // we can get instead of head;
    if(head->data != prevVal)
    {
        // head unique, thus, include
        prevVal = head->data; // update as last seen unique val
    head->next = nextNodeAttached(head->next, prevVal);
// nextGoodNode = nextNodeAttached(head->next, prevVal);
    nextGoodNode = head;
        // either return here, or set head->next as the nextGoodNode;
        // head is a good node, and already inducted into list
        // head->next will get the return of nextNodeAttatched
        // which is guaranteed to be a good node.
    // nextGoodNode = head->next;
    }
    else {
        // head is not unique, and invalid.
        // thus, not allowed in list
        nextGoodNode = nextNodeAttached(head->next, prevVal);
    }
    
    // Node* nextGoodNode = nextNodeAttached(head->next, prevVal);
    return nextGoodNode;
}
SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* head) {
    // v2 recursive
    nextNodeAttached(head, -1);
    return head;
    // v1 Iterative
    // if(!head)
    //     return nullptr;
    // SinglyLinkedListNode* curr = head;
    // SinglyLinkedListNode* prev = head;
    // int prevVal = -1;    
    // while(curr != nullptr)
    // {
    //     if(prevVal != curr->data)
    //     {
    //         prevVal = curr->data;
    //         prev = curr;
    //         curr = curr->next;
    //     }
    //     else
    //     {
    //         prev->next = curr->next;
    //         free(curr);
    //         curr = prev->next;
    //     }
    // }
    // return head;
}

// v3 recursive

/*
In my recursive I took curr as "the current node being scanned". Prev was the node that had been scanned and was correct.
I could have also considered curr as "the current correct node", and next as the "possible option for next node"
*/

// v4 iterative

/*
I did not need to hold prevVal. I could have used the value as curr->data (if curr is the currently accepted node).
Moreover, I could have iterated thro the list separate from everything, even separate from the remove procedure.
I could have implemented curr->next->next s as well. And, thus, solved the whole problem using only one pointer.
  Basically, it works because you always delete a node if you see it is redundant. Set temp = curr->next; curr->next = curr->next->next; delete temp;
*/

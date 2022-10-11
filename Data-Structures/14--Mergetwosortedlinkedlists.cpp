

// Complete the mergeLists function below.

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
// v1 recursive
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* h1, SinglyLinkedListNode* h2) {
    if (!h1 && !h2)
        return NULL;
    if (!h1 && h2)
        return h2;
    if (!h2 && h1)
        return h1;
    
    if(h1->data <= h2->data)
    {
        h1->next = mergeLists(h1->next, h2);
        return h1;
    }
    else
    {
        h2->next = mergeLists(h1, h2->next);        
        return h2;
    }
}

//v2 iterative
// SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
//     Node* itr1 = head1;
//     Node* itr2 = head2;
//     Node *itrHead, * itr = NULL;
//     // while neither is null
//     while(itr1 && itr2)
//     {
//         Node *temp;
//         if(itr1->data <= itr2->data)
//         {
//             temp = new Node(itr1->data);
//             itr1 = itr1->next;
//         }
//         else
//         {
//             temp = new Node(itr2->data);
//             itr2 = itr2->next;            
//         }
        
//         if(itr == NULL)
//         {
//             itr = temp;
//             itrHead = itr;
//         }
//         else{
//             itr ->next = temp;
//             itr = temp;
//         }
//     }
//     while(itr1 && !itr2)
//     {
//         Node *temp = new Node(itr1->data);
        
//         if(itr == NULL)
//         {
//             itr = temp;
//             itrHead = itr;
//         }
//         else{
//             itr ->next = temp;
//             itr = temp;
//         }
//         itr1 = itr1->next;
//     }
//     while(itr2 && !itr1)
//     {
//         Node *temp = new Node(itr2->data);
        
//         if(itr == NULL)
//         {
//             itr = temp;
//             itrHead = itr;
//         }
//         else{
//             itr ->next = temp;
//             itr = temp;
//         }
//         itr2 = itr2->next;
//     }
//     return itrHead;
// }


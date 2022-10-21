/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

// floyd's cycle detection O(n) time constant space
// advantage that you can also detect the merge point (or start of cycle)
// hence you can also count nummber of elements in cycle
// v1 turtle hare (fast-slow) method
typedef SinglyLinkedListNode Node;
bool has_cycle(SinglyLinkedListNode* head) {
    Node *f = head;
    Node *s = head;
    while(f != nullptr && f->next != nullptr)
    {
        // if(f->next == s) // incorrect reasoning -> we may end up deref NULL
        // if(f == s) // can't use -> init involves f == s
      
//         if(f->next == s)
//             return 1;
//         s = s->next;
//         f = f->next->next;
      
        s = s->next;
        f = f->next->next;
        if(f == s)
             return 1;
    }
    return 0;
}
/*
You could also use the f == s condition
if we put the if after our pointer increments.

Here we'd assume our starting condition is fine, and check the loop invariant we get at the end.
Having entered the loop, we are guaranteed to be able to check f's val
*/


// O(n) time O(n) space
// v2 you could hash the nodes and check if they have been seen before
typedef SinglyLinkedListNode Node;
bool has_cycle(SinglyLinkedListNode* head) {
    Node *itr = head;
    unordered_set <Node*> pNodeSet;
    while(itr) // want scan last node
    {
        // insertion failed as seen before
        if(pNodeSet.insert(itr).second == 0)
            return 1;
        itr=itr->next;
    }
    return 0;
}

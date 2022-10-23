#include <bits/stdc++.h>

using namespace std;

class DoublyLinkedListNode {
    public:
        int data;
        DoublyLinkedListNode *next;
        DoublyLinkedListNode *prev;

        DoublyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
            this->prev = nullptr;
        }
};

class DoublyLinkedList {
    public:
        DoublyLinkedListNode *head;
        DoublyLinkedListNode *tail;

        DoublyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            DoublyLinkedListNode* node = new DoublyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
                node->prev = this->tail;
            }

            this->tail = node;
        }
};

void print_doubly_linked_list(DoublyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_doubly_linked_list(DoublyLinkedListNode* node) {
    while (node) {
        DoublyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

/*
 * Complete the 'sortedInsert' function below.
 *
 * The function is expected to return an INTEGER_DOUBLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_DOUBLY_LINKED_LIST llist
 *  2. INTEGER data
 */

/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */

typedef DoublyLinkedListNode Node;
// v1 iterative
// DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) {
//     Node *temp = new Node(data);
//     Node *itr = head;
//     // if data before head // equality rm for stable
//     if(data < head->data)
//     {
//         temp->next = head;
//         head->prev = temp;
//         return temp;
//     }
//     // for all cases, not include last node
//     while(itr->next != nullptr)
//     {
//         // if(itr->data > data) // insert at prev
//         if(data < itr->data) // insert at prev
//         {
//             itr->prev->next = temp;
//             temp->prev = itr->prev;
            
//             temp->next = itr;
//             itr->prev = temp;
            
//             return head;
//         }
//         itr = itr->next;
//     }
//     // we now are at last node
//     // data greater than last node
//     if(data < itr->data)
//     {
//         itr->prev->next = temp;
//         temp->prev = itr->prev;
            
//         temp->next = itr;
//         itr->prev = temp;
//     }
//     else
//     {
//         itr->next = temp;
//         temp->prev = itr;
//     }
//     return head;
// }


// v2 iterative, with 2 pointers for dry
DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) {
    Node *temp = new Node(data);
    // Node *itr = head;
    // if data before head // equality rm for stable
    if(data < head->data)
    {
        temp->next = head;
        head->prev = temp;
        return temp;
    }
    
    Node* n1 = nullptr; // for keeping last node, even if n2 become null
    Node* n2 = head;
    // if data strictly less than n2's. then quit.
    // while(n2 != nullptr && data < n2->data)
    while(n2 != nullptr && data < n2->data)    
    {
        n1 = n2;
        n2 = n2->next;
    }    
    // data is greater or equal n2.
    if(n2 == nullptr)
    {
        n1->next = temp;
        temp->prev = n1;
    }
    // data strictly less than n2's.
    else {
        // n2->prev->next = temp;
        // temp->prev = n2->prev;
        
        // temp->next = n2;
        // n2->prev = temp;
        n1->next = temp;
        temp->prev = n1;
        
        n2->prev = temp;
        temp->next = n2;
    }
    return head;
}

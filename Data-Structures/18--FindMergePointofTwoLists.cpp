#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

// Complete the findMergeNode function below.

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
// v1 hashing
// int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
//     unordered_set<Node *> pNS;
//     // guaranteed not reach null until 
//     Node *itr1 = head1;
//     Node *itr2 = head2;
//     while(true)
//     {
//         // cout << "hee" << endl;
//         if(itr1 != nullptr)
//         {
//             // cout << itr1->data << endl;
//             if(!pNS.insert(itr1).second) //insertion fail
//             {
//                 // cout << "me" << itr1->data << endl;                
//                 return itr1->data;
//             }
//             itr1 = itr1->next;
//         }  
//         if(itr2 != nullptr)
//         {
//             // cout << itr2->data << endl;            
//             if(!pNS.insert(itr2).second)            
//             {
//                 // cout << "ll" << itr1->data << endl;                                
//                 return itr2->data;            
//             }
//             itr2 = itr2->next;            
//         }
//     }
//     return -1;
// }

// v2 kinda like floyd's cycle detection
int findMergeNode(SinglyLinkedListNode* h1, SinglyLinkedListNode* h2) {
    Node *ptr1 = h1;
    Node *ptr2 = h2;    
    while(ptr1 != ptr2)
    {      
        // for ptrA
        // if(ptr1 == nullptr)
        // {
        //     ptr1 = h2;
        // }
        // v3
        // the job becomes to get the node to next node
        // this also ensures proper counting thro only valid nodes
        if(ptr1->next == nullptr)
        {
            ptr1 = h2;
        }
        else
        {
            ptr1 = ptr1->next;
        }
        // in v3, we are guaranteed to be on next node
        // if h1 is considered 1th node, we are calculating a + b + c here.
        // we still put cntA++ here.
        
        // for B
        if(ptr2->next == nullptr)
        {
            ptr2 = h1;
        }
        else
        {
            ptr2 = ptr2->next;
        }
    }
    return ptr1->data;
}






int main()

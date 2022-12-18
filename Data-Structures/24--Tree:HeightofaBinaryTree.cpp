#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }
/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
  // v1 recur
    int height(Node* root) {
        // Write your code here.
        if(root->left == nullptr && root->right == nullptr)
        {
            return 0;
        }
        // for the three cases of existing children (01 01)
        // (0,0) is base case, where the height of that tree
        // is 0;
        
        // so, this function, gives us the height of the given tree
        int lHeight = 0, rHeight = 0;
        if(root->left != nullptr) // if left has more nodes
        {
            lHeight = height(root->left);
        }
        if(root->right != nullptr)
        {
            rHeight = height(root->right);
        }
        return 1 + max(lHeight, rHeight);
    }
  
  // v2 iterative (BFS)
  int height(Node* root) {
        queue <Node *> q;
        int size = 1, height = -1;
        q.push(root);
        while(size != 0)
        {
            for(int i = 0; i < size; i++)
            {
                if(q.front()->left != nullptr)
                    q.push(q.front()->left);   
                if(q.front()->right != nullptr)
                    q.push(q.front()->right);
                q.pop();   
            }
            size = q.size();
            height++;
        }
        return height;
    }
  

}; //End of Solution

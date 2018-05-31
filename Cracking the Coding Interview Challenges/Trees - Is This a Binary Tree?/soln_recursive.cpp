

/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/
#include<climits>

    bool checkBST(Node* root,int &min,int &max){
       
       // empty node (parent will be a leaf node): do nothing.
       if(root==NULL)
       {
           return true;
       }
       // Check if the current node's data adheres to the sub-trees' min & max values 
       if(root-> data <= min || root-> data >= max)
           return false;
       
       bool res = true;
       
       //Process the left sub-tree if it exists
       if(root->left != NULL)
       {
         /* recursively process the left-sub tree. 
          Update the new max to be the current root's value. This is because all the nodes inside this left-subtree MUST be 
          lesser than the root node if this is a BST */
         res = res && checkBST(root->left, min, root->data);  
         
         //Check if the left child is < the current root's value
         if(root->left->data >= root->data)
             return false;
       }
       
       //Process the right subtree if it exists & only if the left sub-tree is a BST (to avoid wasting time)
       if(res && root->right!=NULL)
       {
         //Check if the right child is > the current root's value
         if(root->right->data <= root->data)
               return false;
          
         /* recursively process the right-sub tree. 
          Update the new min to be the current root's value. This is because all the nodes inside this right-subtree MUST be 
          greater than the root node if this is a BST */
         res = checkBST(root->right, root->data, max);
       }
       return res;
    }
  
	bool checkBST(Node* root) {
       int min = INT_MIN;
       int max = INT_MAX; 
       return checkBST(root, min, max);
	}

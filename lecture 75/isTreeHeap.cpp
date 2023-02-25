// step-1: check CBT
//         check max heap order--1.Both child
//                               2.only left child
//                               3.both child NULL
//time complexity O(N)
//space complexity O(N)

class Solution 
{
  public:
  
 bool isMaxOrder(struct Node* root)
  {
      if(root->left == NULL && root->right == NULL)return true;
      
      if(root->right == NULL)
          return (root->data > root->left->data);
      else
      {
          bool left=isMaxOrder(root->left);
          bool right=isMaxOrder(root->right);
          
          return (left && right &&
          (root->data > root->right->data && root->data > root->left->data));
      }
  }
  
  bool isCBT(struct Node* root , int index , int cnt)
  {
      if(root==NULL)return true;
      
      if(index>=cnt)return false;
      else
      {
          bool left=isCBT(root->left,2*index+1,cnt);
          bool right=isCBT(root->right,2*index+2,cnt);
          
          return (left && right);
      }
  }
  
  int countNodes(struct Node* root)
  {
      if(root==NULL)return 0;
      int ans=1+countNodes(root->left)+countNodes(root->right);
      return ans;
  }
  
    bool isHeap(struct Node* tree) 
    {
        int index=0;
        
        int totalCount=countNodes(tree);
        
        if(isCBT(tree,index,totalCount) && isMaxOrder(tree))
           return true;
        else 
           return false;
    }
};
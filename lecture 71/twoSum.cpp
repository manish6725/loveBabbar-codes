void inorder(BinaryTreeNode<int>* root,vector<int>&ans)
{
    if(root==NULL)return;

    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}
bool twoSumInBST(BinaryTreeNode<int>* root, int target)
 {
	vector<int>ans;
    inorder(root,ans);

    int i=0,j=ans.size()-1;

    while(i<j)
    {
        int sum=ans[i]+ans[j];

        if(sum==target)return true;
        else if(sum>target)j--;
        else i++;
    }
    return false;
}
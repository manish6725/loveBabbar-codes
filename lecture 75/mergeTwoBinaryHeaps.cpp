// step 1: dono vectors ko merge krke new vector ans create kro
// step 2: heapify lgado 0 index based
// time complexity--

class Solution
{
    public:
    
    void heapify(vector<int>&ans , int n , int i)
    {
        int largest = i;
        int left=2*i+1;
        int right=2*i+2;
        
        if(left<n && ans[left]>ans[largest])
            largest=left;
            
        if(right<n && ans[right]>ans[largest])
            largest=right;
            
        if(largest != i)
        {
            swap(ans[largest],ans[i]);
            heapify(ans,n,largest);
        }
    }
    
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
    {
       vector<int>ans;
       
       for(auto i:a)
       ans.push_back(i);
       
       for(auto i:b)
       ans.push_back(i);
       
       int size=ans.size();
       
       for(int i=size/2-1 ; i>=0 ; i--)
           heapify(ans,size,i);
       
       return ans;
    }
};
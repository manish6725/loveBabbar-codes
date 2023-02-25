// Approach 1-
//            sort array in increasing order-O(nlogn)
//            return ans=arr[k-1]-O(1)
//            TC-O(nlogn)

// Approach 2-using heap
//            for first k elements , create maxheap
//            for rest elements -- if(element<heap.top())
//                                 heap.pop()
//                                 heap.push(element)
//            return ans=heap.top()                     

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) 
    {
       priority_queue<int>pq;
       
       for(int i=l ; i<k ; i++)
           pq.push(arr[i]);
       
       for(int i=k ; i<=r ; i++)
       {
           if(arr[i]<pq.top())
           {
               pq.pop();
               pq.push(arr[i]);
           }
       }
       
       int ans=pq.top();
       
       return ans;
    }
};

// Note:- for largest Kth element use minHeap
// step-1: create minHeap
// step-2: take two minimum elements
// step-3: add them and push to heap , and add sum to cost
// step-4: return cost

class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n)
    {
       long long cost=0;
       
       priority_queue<long long , vector<long long>, greater<long long>>pq;
       
       for(int i=0 ; i<n ; i++)
           pq.push(arr[i]);
           
       while(pq.size()>1)
       {
          long long a=pq.top();
          pq.pop();
        
          long long b=pq.top();
          pq.pop();
        
          long long sum=a+b;
          
          cost=cost+sum;
          
          pq.push(sum);
       }
       return cost;
    }
};
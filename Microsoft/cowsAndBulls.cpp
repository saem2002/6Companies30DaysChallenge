class Solution {
public:

    void helper(int k,int n,vector<vector<int>> & ans,vector<int>  store,int sum,int num)
    {
        if( sum>n){ return;}
        if( sum==n)
        {
            cout<<sum<<" "<<n<<" "<<k<<" "<<num<<" ";
            if(store.size()==k){
                ans.push_back(store);
            }
            
            return ;
        }
        
        for(int i=num;i<=9;i++)
        {
            store.push_back(i);
            helper(k,n,ans,store,sum+i,i+1);
            store.pop_back();
        }
       
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        vector<int> store;
        helper(k,n,ans,store,0,1);
        return ans;
        
    }
};
class Solution {
public:
     vector<int> rec(int ind , vector<int> &nums ,vector<vector<int>> &dp) 
     {   int n = nums.size();
         if( ind == n ) { return {}; } 
         if(dp[ind].size()!=0)return dp[ind]; 
         vector<int> ans;
         for( int j  = ind +1 ; j < n ; ++j )
         {
             if( nums[j]%nums[ind]) continue;
             auto res = rec(j,nums,dp);
             if( res.size()>=size(ans)) ans = res;

         }
         ans.push_back(nums[ind]);
         return dp[ind] = ans;
     }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int n = nums.size();
        for( int i = 0 ; i < nums.size() ; ++i )
        {  vector<vector<int>> dp(n);
            vector<int> res; 
            res = rec(i,nums ,dp);
            if( res.size() >= ans.size() ) ans = res;
        }
        return ans;
        
    }
};
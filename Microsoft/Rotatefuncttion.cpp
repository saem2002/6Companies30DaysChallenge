class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        
        int n = nums.size();
        
        int sum = 0;
        int prev = 0;
        for(int i = 0;i< n;i++)
        {
            sum+=nums[i];
            prev += i*nums[i];
        }
        // cout << sum << endl;
        int ans = prev;
        int curr ;
        for(int i =1;i<n;i++)
        {
            curr = prev +sum - (n*nums[n-i]);
            cout << curr << endl;
            ans = max(ans,curr);
            prev = curr;
        }
        return ans;
    }
};
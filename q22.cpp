/*
Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0, n = nums.size();
        vector<int> dp(n+1,0);
        for(int i=1; i<=n;i++){
            dp[i] = dp[i-1]+nums[i-1];
        }
        for(int i=0; i<n; i++){
            for(int j=i+1; j<=n;j++){
                if(dp[j]-dp[i]==k)
                    res++;
            }
        }
        return res;
        
    }
};

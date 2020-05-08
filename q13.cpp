/*
Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int res = 0, sum = 0;
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size();i++){
            sum += (nums[i]==0)?-1:1;
            if(sum==0)
                res = i+1;
            else if(mp.find(sum)!=mp.end()){
                if(res<i-mp[sum])
                    res = i - mp[sum];
            }
            else
                mp[sum] = i;
        }
        return res;
    }
};

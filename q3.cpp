/*
  Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, res = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            res = max(res,sum);
            if(sum < 0)
                sum = 0;
        }
        return res;
    }
};

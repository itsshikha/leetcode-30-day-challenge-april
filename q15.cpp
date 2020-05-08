/*
Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.size()==0){
            return {};
        }
        if(nums.size()==1){
            return {1};
        }
        vector<int> res(nums.size(),1);
        for(int i=1; i<nums.size();i++){
            res[i] = res[i-1]*nums[i-1];
        }
        int prev = nums[nums.size()-1];
        int curr;
        nums[nums.size()-1] = 1;
        for(int i=nums.size()-2; i>=0;i--){
            curr = nums[i];
            nums[i] = nums[i+1]*prev;
            prev = curr;
        }
        for(int i=0; i<nums.size();i++){
            res[i] = res[i]*nums[i];
        }
        return res;
    }
};

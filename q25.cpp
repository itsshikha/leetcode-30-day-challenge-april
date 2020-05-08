/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

 
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int last_i = nums.size()-1;
        if(last_i<=0)
            return true;
        int max_pos = 0;
        for(int i=0; i<=last_i&&i<=max_pos;i++){
            max_pos = max(max_pos, i+nums[i]);
            if(max_pos>=last_i)
                return true;
        }
        return false;
    }
};

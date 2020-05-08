/*
  Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0,size = nums.size();
        while(i<size-1){
            if(nums[i] == 0){
                int j=i+1;
                while(j<nums.size()-1&&nums[j]==0)
                    j++;
                nums[i] = nums[j];
                nums[j] = 0;
            }
            i++;
        }
    }
};

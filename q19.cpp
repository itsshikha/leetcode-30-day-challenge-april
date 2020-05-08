/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1, n = high + 1;
        if(high<0)
            return -1;
        while(low<=high){
            //cout<<low<<" "<<high<<endl;
            int mid = (low+high)/2;
            if(nums[low]==target)
                return low;
            if(nums[mid]==target)
                return mid;
            if(nums[high]==target)
                return high;
            if(nums[0]<nums[mid]){
                //cout<<"c"<<endl;
                if(nums[mid]>target && nums[low]<target)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else{
                if(nums[mid]<target && nums[high]>target)
                    low = mid + 1;
                else
                    high = mid -1;
            }
            
        }
        return -1;
    }
};

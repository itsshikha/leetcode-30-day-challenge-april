/*
We have a collection of stones, each stone has a positive integer weight.

Each turn, we choose the two heaviest stones and smash them together.  Suppose the stones have weights x and y with x <= y.  The result of this smash is:

If x == y, both stones are totally destroyed;
If x != y, the stone of weight x is totally destroyed, and the stone of weight y has new weight y-x.
At the end, there is at most 1 stone left.  Return the weight of this stone (or 0 if there are no stones left.)
*/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        make_heap(stones.begin(),stones.end());
        while(stones.size()>1){
            int st1 = stones.front();
            pop_heap(stones.begin(), stones.end()); 
            stones.pop_back();
            int st2 = stones.front();
            pop_heap(stones.begin(), stones.end()); 
            stones.pop_back();
            if(st1 != st2){
                stones.push_back(abs(st1-st2));  
                push_heap(stones.begin(), stones.end()); 
            }
        }
        if(stones.size())
            return stones[0];
        return 0;
    }
};

Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int res = INT_MAX, i = m;
        while(1){
            if(res==0)
                break;
            res = res&i;
            if(i==n)
                break;
            i++;
        }
        return res;
    }
};

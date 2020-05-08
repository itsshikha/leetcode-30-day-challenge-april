/*
  Say you have an array prices for which the ith element is the price of a given stock on day i.

  Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

  Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
            return 0;
        int res = 0;
        int flag = 1, price;
        for(int i=0; i<prices.size(); i++){
            if(i == prices.size()-1){
                if(flag == 0 && prices[i]>price)
                    res += prices[i] - price;
                break;
            }
            if(prices[i]<prices[i+1] && flag==1){
                price = prices[i];
                flag = 0;
                continue;
            }
            if(prices[i]>prices[i+1] && flag == 0){
                res+=prices[i]-price;
                flag = 1;
            }
            
        }
        return res;
    }
};

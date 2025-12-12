/*
o(n), o(1)

brute force would be to iterate using two loops and find the pair which gives the highest profit o(n^2),o(1)

optimized would be to keep track of the minimum price seen so far and calculate the profit at each step
and update the maximum profit accordingly

*/

    int maxProfit(vector<int>& prices) {
        int min = INT_MAX, ans = 0;
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < min){
                min = prices[i];
            }else{
                if(prices[i]-min > ans)
                    ans = prices[i]-min;
            }
        }
        return ans;
    }
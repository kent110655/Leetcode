class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i-1]<prices[i])
            {
                profit+=prices[i]-prices[i-1];
            }
        }
        return profit;
    }
};

/*
Comment:
利用Greedy
只要有漲幅(遞增)就買進買出！
時間複雜度：Ｏ(n)
*/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int N = prices.size();
        if(N == 0 || k == 0)
            return 0;
        int MaxProfit = 0;
        vector<vector<int>> state(k, vector<int>{INT_MIN, 0});
        for(auto p : prices)
        {
            state[0][0] = max(state[0][0], -p);
            state[0][1] = max(state[0][1], state[0][0] + p);
            MaxProfit = state[0][1];
            for(int i = 1; i < k; i++)
            {
                state[i][0] = max(state[i][0], state[i-1][1] - p);
                state[i][1] = max(state[i][1], state[i][0] + p);
                MaxProfit = max(MaxProfit, state[i][1]);
            }
        }
        return MaxProfit;
    }
};

/*
Comment:
利用狀態機求出轉換式。
state[i][t]:第i次交易狀態最大收益(t=0則是hold, t=1則是sold)
state[0][0] (hold1)是邊界條件需要特別注意。
(把LC123的解法改成多次即可)
時間複雜度：Ｏ(nk)
空間複雜度：Ｏ(k)
*/

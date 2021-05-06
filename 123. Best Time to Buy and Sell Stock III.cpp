class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int N = prices.size();
        int hold1 = INT_MIN;
        int sold1 = 0;
        int hold2 = INT_MIN;
        int sold2 = 0;
        for(auto p : prices)
        {
            hold1 = max(hold1, - p);
            sold1 = max(sold1, hold1 + p);
            hold2 = max(hold2, sold1 - p);
            sold2 = max(sold2, hold2 + p);
        }
        return max(sold1, sold2);
    }
};
/*
Algo 3:
Comment:
利用狀態機求出轉換式。
優化Algo2 空間降維
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(1)
*/

/*
Algo 2:
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int N = prices.size();
        vector<int> hold1(N + 1, INT_MIN);
        vector<int> sold1(N + 1, 0);
        vector<int> hold2(N + 1, INT_MIN);
        vector<int> sold2(N + 1, 0);
        for(int i = 1; i <= N; i++)
        {
            hold1[i] = max(hold1[i-1], - prices[i-1]);
            sold1[i] = max(sold1[i-1], hold1[i-1] + prices[i-1]);
            hold2[i] = max(hold2[i-1], sold1[i-1] - prices[i-1]);
            sold2[i] = max(sold2[i-1], hold2[i-1] + prices[i-1]);
        }
        return max(sold1[N], sold2[N]);
    }
};
Comment:
利用狀態機求出轉換式。
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(n)
*/

/*
Algo 1:
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int N = prices.size();
        int profit = INT_MIN;
        for(int i = 1; i < N-2; i++)
        {
            profit = max(profit, 
                         MaxProfit(prices, 0, i) + MaxProfit(prices, i+1, N-1));
        }
        return max(profit, MaxProfit(prices, 0, N-1));
    }
private:
    int MaxProfit(vector<int>& prices, int start, int end)
    {
        int maxProfit = 0;
        int minPrice = INT_MAX;
        for(int i = start; i <= end; i++)
        {
            minPrice = min(minPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }
        return maxProfit;
    }
};
Comment:
遍尋整個prices，分割成兩部分，分別去找各自的一次交易最大收益
最終比較結果即可。
TLE。
時間複雜度：Ｏ(n^2)
空間複雜度：Ｏ(1)
*/

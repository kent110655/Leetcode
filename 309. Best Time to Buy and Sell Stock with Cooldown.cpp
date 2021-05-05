class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int N = prices.size();
        int hold = INT_MIN;
        int rest = 0;
        int sold = 0;
        for(int p : prices)
        {
            hold = max(rest - p, hold);
            rest = max(sold, rest);
            sold = hold + p;
        }
        return max(rest, sold);
    }
};

/*
Algo 2:
Comment:
空間降維Ｏ(n) -> Ｏ(1)
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(1)
*/

/*
Algo 1:
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int N = prices.size();
        vector<int> hold(N+1);
        vector<int> sold(N+1);
        vector<int> rest(N+1);
        hold[0] = INT_MIN;
        rest[0] = 0;
        sold[0] = 0;
        for(int i = 1; i <= N; i++)
        {
            hold[i] = max(rest[i-1] - prices[i-1], hold[i-1]);
            rest[i] = max(sold[i-1], rest[i-1]);
            sold[i] = hold[i-1] + prices[i-1];
        }
        return max(rest[N], sold[N]);
    }
};
Comment:
hold[i]:第i個屬於買了不賣的狀態時的最大收益
rest[i]:第i個屬於賣了以後不動作的狀態時的最大收益
sold[i]:第i個屬於剛賣了的狀態時的最大收益
(畫出狀態機轉換式比較好寫轉換式)
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(n)
*/

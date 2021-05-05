class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int hold = INT_MIN;
        int sold = 0;
        for(int& p : prices)
        {
            hold = max(hold, sold - p - fee);
            sold = max(sold, hold + p);
        }
        return sold;
    }
};
/*
Comment:
hold[i]:第i個屬於手上有股的狀態時的最大收益
sold[i]:第i個屬於手上沒股的狀態時的最大收益
(畫出狀態機轉換式比較好寫轉換式)
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(1)
*/

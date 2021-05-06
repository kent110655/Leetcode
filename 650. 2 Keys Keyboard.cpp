class Solution {
public:
    int minSteps(int n) {
        if(n == 1)
            return 0;
        int ans = 0;
        for(int i = 2; i <= n; i++)
        {
            while(n % i == 0)
            {
                n /= i;
                ans += i;
            }
        }
        return ans;
    }
};
/*
Comment:
利用Greedy實作
遍尋n的質因數
因為質數的運算數為質數本身
所以當確定質因數時可以直接確定ans要加上質因數。
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(1)
*/

/*
Algo 2:
class Solution {
public:
    int minSteps(int n) {
        if(n == 1)
            return 0;
        vector<int> dp(n+1);
        dp[2] = 2;
        for(int i = 2; i <= n; i++)
        {
            dp[i] = i;
            for(int j = 2; j <= i/2; j++)
            {
                if(i % j == 0)
                {
                    dp[i] = dp[j] + i / j;
                }
            }
        }
        return dp[n];
    }
};
Comment:
使用DP實作
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(n)
*/

/*
Algo 1:
class Solution {
public:
    int minSteps(int n) {
        if(n == 1)
            return 0;
        for(int i = 2; i <= n; i++)
        {
            if(n % i == 0)
                return minSteps(n / i) + i;
        }
        return -1;
    }
};
Comment:
觀察規律！
每個操作就是在原本的數乘以某數
所以可以看成n的因數分解(n = a * b * c ...)
所求為 n=a的值 ＋ n=b的值 ＋ n=b的值...
使用Recursion求解。
時間複雜度：Ｏ(log n ~ n)
空間複雜度：Ｏ(log n)
*/

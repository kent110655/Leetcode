class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int N = pairs.size();
        sort(pairs.begin(), pairs.end(), 
             [](vector<int>& a,vector<int>& b)
             { 
                 return a[1] < b[1];
             }
            );
        int end = pairs[0][1];
        int count = 1;
        for(int i = 1; i < N; i++)
        {
            if(pairs[i][0] > end)
            {
                count++;
                end = pairs[i][1];
            }
        }
        return count;
    }
};
/*
Algo 2:
Comment:
以尾端數大小去Sort。
再以Greedy去找符合條件的數量即可。
時間複雜度：Ｏ(nlogn)
空間複雜度：Ｏ(1)
*/

/*
Algo 1:
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int N = pairs.size();
        sort(pairs.begin(), pairs.end());
        vector<int> dp(N,1);
        for(int i = 0; i < N; i++)
        {
            for(int t = 0; t < i; t++)
            {
                if(pairs[t][1] < pairs[i][0])
                {
                    dp[i] = max(dp[i], dp[t]+1);
                }
            }
        }
        return dp[N-1];
    }
};
Comment:
DP解法。
dp[i] = max(dp[t] | t<i && nums[t] < nums[i])
ans = max(dp[i] | i = 0~end)
時間複雜度：Ｏ(n^2)
空間複雜度：Ｏ(n)
*/

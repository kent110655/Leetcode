class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int N = nums.size();
        vector<int> dp;
        for(int i = 0; i < N; i++)
        {
            auto it = lower_bound(dp.begin(), dp.end(), nums[i]);
            if(it == dp.end()) 
                dp.push_back(nums[i]);
            else
                *it = nums[i];
        }
        return dp.size();
    }
};
/*
Algo 3:
Comment:
同Algo 2作法，Binary Search部分改成STL內建的lower_bound()
時間複雜度：Ｏ(nlogn) (因為Binary search : logn)
空間複雜度：Ｏ(n)
*/

/*
Algo 2:
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int N = nums.size();
        vector<int> dp;
        dp.push_back(nums[0]);
        for(int i = 1; i < N; i++)
        {
            int it = BinarySearch(dp, 0, dp.size()-1, nums[i]);
            if(it == dp.size()) 
                dp.push_back(nums[i]);
            else
                dp[it] = nums[i];
        }
        return dp.size();
    }
private:
    int BinarySearch(vector<int>& dp, int start, int end, int val)
    {
        if(val > dp[dp.size()-1])
            return dp.size();
        while(start < end)
        {
            int mid = start + (end - start) / 2;
            if(dp[mid] == val)
                return mid;
            else if(dp[mid] > val)
                end = mid;
            else
                start = mid + 1;
        }
        return start;
    }
};
Comment:
DP解法
dp[i]：當len = i+1 時，他的最佳結尾數字。
DP loop中：
搜尋新的數字val在dp[]中的哪個區間(使用Binary Search)
Case 1: dp[t-1] < val < dp[t]
則代表在len=t的時候val是更好的結尾數字
所以dp[t] = val (更新最佳結尾數字)
Case 2: val比dp中的所有數字都大(val > dp[...])
則代表可以接續在子串後面增加一個新的結尾
所以dp.push_back(val) (新增原本長度+1的新結尾)
-> 最終dp[]的len即為LIS。
時間複雜度：Ｏ(nlogn) (因為Binary search : logn)
空間複雜度：Ｏ(n)
https://www.youtube.com/watch?v=l2rCz7skAlk
*/

/*
Algo 1:
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int N = nums.size();
        vector<int> dp(N, 1);
        for(int i = 1; i < N; i++)
        {
             for(int t = 0; t < i; t++)
             {
                 if(nums[t] < nums[i])
                 {
                     dp[i] = max(dp[i], dp[t] + 1);
                 }
             }
        }
        int ans = 0;
        for(auto u: dp)
            ans = max(ans, u);
        return ans;
    }
};
Comment:
DP解法。
dp[i] = max(dp[t] | t<i && nums[t] < nums[i])
ans = max(dp[i] | i = 0~end)
時間複雜度：Ｏ(n^2)
空間複雜度：Ｏ(n)
*/

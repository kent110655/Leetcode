class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, INT_MIN);
        deque<int> d;
        dp[0] = nums[0];
        d.push_back(0);
        for(int i = 1; i < n; i++)
        {
            dp[i] = nums[i] + dp[d.front()];
            if(i - d.front() >= k)
            {
                d.pop_front();
            }
            while(!d.empty() && dp[d.back()] <= dp[i])
            {
                d.pop_back();
            }
            d.push_back(i);
        } 
        return dp[n-1];
    }
};

/*
Comment:
First time we use dp algorithm to calculate the final answer. But the time complexity would be Ｏ(nk), and the result will be a TLE. So we want to speed up the comparing maximum part. We keep a sliding window which is monotonic. Keep the front end element be the greater element in order to get the greater element in Ｏ(n). So We use a deque to store the element and remove the element which is smaller than new element from the back end. Also, we should check the element whether is in the k range. Then we can complete the dp vector with only Ｏ(n).
Time Complexity:Ｏ(n)
Space Complexity:Ｏ(n)
*/

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int N = nums.size();
        unordered_map<int,int> cnt;
        unordered_map<int,int> first;
        unordered_map<int,int> last;
        int maxCount = INT_MIN;
        int minLen = INT_MAX;
        for(int i = 0; i < N; i++)
        {
            cnt[nums[i]]++;
            if(cnt[nums[i]] == 1)
                first[nums[i]] = i;
            last[nums[i]] = i;
            maxCount= max(maxCount, cnt[nums[i]]);
        }
        for(auto u : cnt)
        {
            if(u.second == maxCount)
                minLen = min(last[u.first] - first[u.first] + 1, minLen);
        }
        return minLen;
    }
};
/*
Comment:
利用hash table紀錄每個element的個數與第一個與最後一個位置
再取最大個數的最小長度即可
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(n)
*/

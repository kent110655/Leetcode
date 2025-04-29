class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxLen = 0;
        unordered_map<int,int> prefix;
        int sum = 0;
        prefix[0] = -1;
        for(int t = 0; t < nums.size(); t++)
        {
            sum += nums[t] ? 1 : -1;
            if(prefix.count(sum) != 0)
            {
                maxLen = max(maxLen, t - prefix[sum]);
            }
            else
            {
                prefix[sum] = t;
            }
        }
        return maxLen;
    }
};

/*
Comment:
把nums的0轉換成-1，並且以一個hash table紀錄累積sum總和初次出現的位置index。
當sum逐步在計算完成時，如果遇到之前有出現過的sum值(看hash)，即可得知這兩個位置的距離差就是連續總和為0(Ans)
Time Complexity:Ｏ(n)
Space Complexity:Ｏ(n)
 */

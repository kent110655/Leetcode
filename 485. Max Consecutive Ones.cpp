class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxC = INT_MIN;
        for(auto n : nums)
        {
            if(n == 0)
            {
                maxC = max(maxC, count);
                count = 0;
            }
            else
                count++;
        }
        maxC = max(maxC, count);
        return maxC;
    }
};
/*
Comment:
掃一遍紀錄連續的最大值即可
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(1)
*/

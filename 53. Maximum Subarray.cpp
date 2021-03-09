class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=nums[0];
        int MaxSum=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            sum=max(sum+nums[i], nums[i]);
            MaxSum=max(MaxSum, sum);
        }
        return MaxSum;
    }
};

/*
algo 1:
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> sum(nums.size());
        sum[0]=nums[0];
        int MaxSum=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            sum[i]=max(sum[i-1]+nums[i], nums[i]);
            MaxSum=max(MaxSum, sum[i]);
        }
        return MaxSum;
    }
};
Comment:
DP algo.
sum[i]:代表含有element i的字串和最大值。
sum[i] = max(sum[i-1]+nums[i], nums[i]);
*/

/*
algo 2:
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=nums[0];
        int MaxSum=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            sum=max(sum+nums[i], nums[i]);
            MaxSum=max(MaxSum, sum);
        }
        return MaxSum;
    }
};

Comment:
優化空間複雜度Ｏ(n)-->Ｏ(1)
只用到sum[i]與sum[i-1]，所以直接以一個變數即可。
*/

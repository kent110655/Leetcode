class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int N = nums.size();
        if(N == 3)
            return nums[0] * nums[1] * nums[2];
        int max1 = INT_MIN;
        int max2 = INT_MIN;
        int max3 = INT_MIN;
        int min1 = INT_MAX;
        int min2 = INT_MAX;
        for(auto n : nums)
        {
            if(n > max1)
            {
                max3 = max2;
                max2 = max1;
                max1 = n;
            }
            else if(n > max2)
            {
                max3 = max2;
                max2 = n;
            }
            else if(n > max3)
            {
                max3 = n;
            }
            if(n < min1)
            {
                min2 = min1;
                min1 = n;
            }
            else if(n < min2)
            {
                min2 = n;
            }
        }
        return max(max1*max2*max3, min1*min2*max1);
    }
};

/*
Comment:
Max Product存在兩種情況
Case1: 三正數相乘
Case2: 兩負數一正數相乘
所以只要求出最大三整數與最小兩負數即可。
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(1)
*/

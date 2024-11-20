class Solution {
public:
    int search(vector<int>& nums, int target) {
        long l = -1;
        long r = nums.size();
        while(l+1 != r)
        {
            long m = l + (r-l)/2;
            if(isTargetOnLeft(nums, m, target))
            {
                l = m;
            }
            else
            {
                r = m;
            }
        }
        if(l >= 0 && nums[l] == target)
        {
            return l;
        }
        else
        {
            return -1;
        }
    }

    bool isTargetOnLeft(vector<int>& nums, int m, int target)
    {
        if(nums[0] <= target) // target在前半部分
        {
            if(nums[m] < nums[0]) // m在後半段
            {
                return false;
            }
            else // m在前半段
            {
                if(nums[m] <= target)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
        else // target在後半部分
        {
            if(nums[m] >= nums[0]) // m在前半段
            {
                return true;
            }
            else // m在後半段
            {
                if(nums[m] <= target)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
        
    }
};

/*
Comment:
主要是要辨認binary search的m與target是否在同一個連續串，利用nums[0]與target, m 比較大小來判別位置。
時間複雜度：Ｏ(logn)
空間複雜度：Ｏ(1)
*/

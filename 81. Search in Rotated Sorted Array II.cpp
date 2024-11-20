class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = -1;
        int r = nums.size();
        if(nums[0] == target)
        {
            return true;
        }
        while(r > 0 && nums[0] == nums[r-1]) //當頭尾相同時，移除尾端的重複數字
        {
            r--;
        }
        bool targetOnLeft = (nums[0] < target);
        while(l+1 < r)
        {
            int m = l + (r-l)/2;
            if(checkIsLeft(nums,target,targetOnLeft,m))
            {
                l = m;
            }
            else
            {
                r = m;
            }
            if(nums[m] == target)
                return true;
        }
        return false;
    }

    bool checkIsLeft(vector<int>& nums, int target, bool targetOnLeft ,int m)
    {
        bool sameSide = (nums[m] > nums[0] && targetOnLeft) || (nums[m] < nums[0] && !targetOnLeft) || (nums[m] == nums[0] && targetOnLeft);

        if(sameSide)
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
        else
        {
            return !targetOnLeft;
        }
    }
};

/*
Comment:
跟33題類似，但多了可重複數字的條件。
此條件導致當nums[m]跟nums[0]相同時無法判斷m是在左側還是右側
一開始先預先處理這部分
當頭尾相同時，移除尾端的重複數字(移動邊界r)(移除重複數字不影響結果)
所以nums[m]=nums[0]時一定是在左側
時間複雜度：Ｏ(logn + k), k=頭尾相同時，尾端重複數字數量
空間複雜度：Ｏ(1)
*/

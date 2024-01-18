class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result;
        int minGap =100000;
        int div;
        int left;
        int right;
        sort(nums.begin(), nums.end());
        for(int i = 0 ; i < nums.size(); i++)
        {
            left = i+1;
            right = nums.size()-1;
            while(left < right)
            {
                div = target - nums[i] - nums[left] - nums[right];
                if(minGap > abs(div))
                {
                    minGap = abs(div);
                    result = nums[i] + nums[left] + nums[right];
                }
                if(minGap == 0)
                {
                    return result;
                }
                if(div > 0)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
        return result;
    }
};

/*
Comment:
Time Complexity：O(nlogn) + O(n^2) = O(n^2)
Space Complexity：O(1)
Algo：
sort從小到大
使用3個pointer來實作。
先指定一個pointer i 當作target，並且剩餘指定兩端pointer left,right
比較target跟nums[i]+nums[l]+nums[r]的大小，並依此調整l,r
偏小就l++, 偏大就r-- 在過程中比較當前組合跟target的差距取最小值即可
*/


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());
        int size = nums.size();
        for(int i = 0; i < size-3; i++)
        {
            if(i > 0 && nums[i] == nums[i-1])
            {
                continue;
            }
            for(int t = i+1; t < size-2; t++)
            {
                if(t > i+1 && nums[t] == nums[t-1])
                {
                    continue;
                }
                int left = t+1;
                int right = nums.size()-1;
                while(left < right)
                {
                    long sum = (long)nums[i] + nums[t] + nums[left] + nums[right];
                    if(sum == target)
                    {
                        result.push_back({nums[i], nums[t], nums[left], nums[right]});
                        while(left < right && nums[left] == nums[left+1])
                        {
                            left++;
                        }
                        while(left < right && nums[right] == nums[right-1])
                        {
                            right--;
                        }
                        left++;
                        right--;
                    }
                    else if(sum > target)
                    {
                        right--;
                    }
                    else if(sum < target)
                    {
                        left++;
                    }
                }
            }
        }
        return result;
    }
};

/*
Time Complexity：O(n^3)
Space Complexity：O(1)
Comment:
2 pointer解法，與3Sum類似
先由小到大sort一遍
再來以兩個for迴圈指定此次要選定的前兩個數
最後兩個數再以two pointer方式動態調整到match
為了加速，在過程中需進行剪枝，把一些不需要跑的loop提前結束
例如重複的數字、剩餘數字數量不足...等等
*/

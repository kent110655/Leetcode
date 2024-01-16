class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int sum = 0;
        int target;
        int r;
        int l;
        int last_l;
        int last_r;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if(i > 0 && nums[i] == nums[i-1])
            {
                continue;
            }
            l = i+1;
            r = nums.size()-1;
            target = nums[i] * (-1);
            while(l < r)
            {
                if(nums[l] + nums[r] < target)
                {
                    l++;
                }
                else if(nums[l] + nums[r] > target)
                {
                    r--;
                }
                else
                {
                    if(last_l != nums[l] || last_r != nums[r])
                    {
                        vector<int> tempt = {nums[i], nums[l], nums[r]};
                        last_l = nums[l];
                        last_r = nums[r];
                        result.push_back(tempt);
                    }
                    l++;
                    r--;
                }
            }
        }
        return result;
    }
};

/*
Time Complexity：O(nlogn) + O(n^2) = O(n^2)
Space Complexity：O(1)
Algo：
sort從小到大
使用3個pointer來實作。
先指定一個pointer i 當作target，並且剩餘指定兩端pointer l,r
比較target跟nums[l]+nums[r]的大小，並依此調整l,r
偏小就l++, 偏大就r--, 命中則l++ r--
再確保命中時不會取到相同的配對即可
*/

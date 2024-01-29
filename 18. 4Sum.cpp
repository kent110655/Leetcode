class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        kSum(nums, target, 4, result);
        return result;
    }

    void kSum(vector<int>& nums, long target, int k, vector<vector<int>>& result)
    {
        vector<int> cur;
        dfs(nums, target, k, 0, nums.size()-1, cur, result);
    }

    void dfs(vector<int>& nums, long target, int k, int left, int right, vector<int> cur, vector<vector<int>>& result)
    {
        if(k>2)
        {
            for(int i = left; i <= right-k+1; i++)
            {
                if(i > left && nums[i] == nums[i-1])
                {
                    continue;
                }
                vector<int> next_cur(cur.begin(), cur.end());
                next_cur.push_back(nums[i]);
                dfs(nums, target-nums[i], k-1, i+1, right, next_cur, result);
            }
        }
        else if(k==2)
        {
            while(left < right)
            {
                if(target == nums[left] + nums[right])
                {
                    vector<int> tempt(cur.begin(), cur.end());
                    tempt.push_back(nums[left]);
                    tempt.push_back(nums[right]);
                    result.push_back(tempt);
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
                else if(target < nums[left] + nums[right])
                {
                    right--;
                }
                else
                {
                    left++;
                }
            }
        }
    }
};

/*
Algo1: KSum (延伸通解)

Time Complexity：O(nlogn + n^k)
    sort: O(nlogn)
    dfs: 主要是for loop -> O(n^k)

Space Complexity：O(n+k)
    result使用: O(n)
    recursive深度: O(k)
    recursive每層: O(1)


Comment:
2 pointer解法，與3Sum類似
先由小到大sort一遍
再來以兩個for迴圈指定此次要選定的前k個數
最後兩個數再以two pointer方式動態調整到match
為了加速，在過程中需進行剪枝，把一些不需要跑的loop提前結束
例如重複的數字、剩餘數字數量不足...等等
此例把4Sum的解法轉成KSum，並利用Recursive來實作指定前面k個數
*/


/*
Algo 2:

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

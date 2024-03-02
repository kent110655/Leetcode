class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = 1;
        int count =0;
        int last_left = nums.back()+1;
        while(right < nums.size() && left < right)
        {
            if(nums[right] - nums[left] < k)
            {
                right += 1;
            }
            else if(nums[right] - nums[left] > k)
            {
                left += 1;
                if(left == right)
                {
                    right += 1;
                }
            }
            else
            {
                if(nums[left] != last_left)
                {
                    count += 1;
                    last_left = nums[left];
                }
                left += 1;
                right += 1;
            }
        }
        return count;
    }
};

/*
Comment:
先sort nums從小排到大
利用two pointer left=0, right=1
判斷兩個pointer的差植與k的大小
<k: 代表right值不夠大，right右移
>k: 代表left值不夠大，left右移 (需維持left < right)
=k: 代表符合條件，確認此時與上一個符合條件的值是否相同，若不相同則count++，再把left,right右移
Time Complexity: O(nlogn)
Space Complexity: O(1)
*/

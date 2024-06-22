class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = -1;
        int right = n;
        while(left+1 != right)
        {
            int mid = left + (right-left)/2;
            if(nums[mid] > nums[n-1])
            {
                left = mid;
            }
            else if(nums[mid] < nums[n-1])
            {
                right = mid;
            }
            else
            {
                if(right == n)
                {
                    right--;
                }
                n--;
            }
        }
        return nums[right];
    }
};

/*
Comment:
使用binary search找邊界
比較mid與最後一個數字的大小
mid > last num: 左側
mid < last num: 右側
mid = last num: 
這種情況沒法判斷左右側，所以移除最後的數字(因為是重複所以結果不變)
last num 左移，當作一開始就沒有算入最後的數字(當right還在初始位置則需要一起調整左移)

Time Complexity:Ｏ(logn)
Space Complexity:Ｏ(1)
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int maxAmount = (right-left) * min(height[left], height[right]);
        
        while(left < right)
        {
            if(height[left] > height[right])
            {
                right--;
            }
            else if(height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
                left++;
            }
            maxAmount = max(maxAmount, (right-left) * min(height[left], height[right]));
        }
        return maxAmount;
    }
};
/*
Comment:
利用two pointer設置左右兩邊的pointer
整個過程會是兩邊逐漸靠近，直到重疊結束，途中紀錄max水量
移動規則：當一邊比較低的時候，低的需要移動(改變)嘗試變成更好的高度
Time: Ｏ(n)
Space: Ｏ(1)
*/

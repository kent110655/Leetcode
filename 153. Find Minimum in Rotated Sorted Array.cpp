class Solution {
public:
    int findMin(vector<int>& nums) {
        int size=nums.size();
        if(size==1)
            return nums[0];
        int left=0;
        int right=size-1;
        int mid;
        int end=nums[size-1];
        while(left<=right)
        {
            mid=left+(right-left)/2;
            if(nums[mid]<=end)  //取左 or target
                right=mid-1;
            else    //取左
                left=mid+1;
        }
        return nums[right+1];
    }
};
/*
Comment:
Binary search
把mid跟最後一個element比較大小，可得知最小值在左邊還是右邊。
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int size=nums.size()-1;
        int left=0;
        int right=size;
        int mid;
        if(nums.size()==1)
            return nums[0];
        while(left<=right)
        {
            mid=left+(right-left)/2;
            if(mid%2==1)
                mid--;
            if(nums[mid]==nums[mid+1])  //  取右
                left=mid+2;
            else if(nums[mid]!=nums[mid+1]) //取左 or target
                right=mid-1;
        }
        return nums[left];
    }
};

/*
Comment:
Binary Search
取mid的時候使之保持在第偶數個element
情況1:nums[mid]==nums[mid+1]
target在右
情況2:nums[mid]!=nums[mid+1]
target在左 or mid就是target
最後mid=target的時候在情況2，所以target = right+1 = left。
*/

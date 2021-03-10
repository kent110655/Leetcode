class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int size=nums.size();
        if(size==0)
        {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        
        //第一輪Binary search (找最左端target)
        int left=0;
        int right=nums.size()-1;
        int mid;
        while(left<=right)
        {
            mid=left+(right-left)/2;
            if(nums[mid]>=target)    //取左 or target
            {
                right=mid-1;
            }
            else    //取右
            {
                left=mid+1;
            }
        }
        //if 沒找到target
        if(right+1>=size||(right+1<size && nums[right+1]!=target))
        {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        else
            ans.push_back(right+1);
        
        //第二輪Binary search (找最右端target)
        left=0;
        right=size-1;
        while(left<=right)
        {
            mid=left+(right-left)/2;
            if(nums[mid]>target)    //取左
            {
                right=mid-1;
            }
            else    //取右 or target
            {
                left=mid+1;
            }
        }
        ans.push_back(left-1);
        return ans;
    }
};

/*
Comment:
Binary search
題：求得target的最左端跟最右端位置。
利用兩種binary search分別求得兩端位置。
*/

class Solution {
public:
    int findFirstPosi(vector<int>& nums, int target)
    {
        //找最左端target
        int size = nums.size();
        int left=0;
        int right=size-1;
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
        return right+1;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int size=nums.size();
        if(size==0)
        {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        
        int first=findFirstPosi(nums,target);
        int end=findFirstPosi(nums,target+1)-1;
        if(first==size || nums[first]!=target)
        {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        else
        {
            ans.push_back(first);
            ans.push_back(end);
            return ans;
        }
    }
};

/*
algo 1:
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

Comment:
Binary search
題：求得target的最左端跟最右端位置。
利用兩種binary search分別求得兩端位置。
*/

/*
algo 2:
class Solution {
public:
    int findFirstPosi(vector<int>& nums, int target)
    {
        //找最左端target
        int size = nums.size();
        int left=0;
        int right=size-1;
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
        return right+1;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int size=nums.size();
        if(size==0)
        {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        
        int first=findFirstPosi(nums,target);
        int end=findFirstPosi(nums,target+1)-1;
        if(first==size || nums[first]!=target)
        {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        else
        {
            ans.push_back(first);
            ans.push_back(end);
            return ans;
        }
        
    }
};

Comment:
優化algo 1，不用兩個binary search
只寫一個取最左端的binary search
最左端位置：尋找target
最右端位置：尋找target+1的最左端，得出的位置再-1即可
*/

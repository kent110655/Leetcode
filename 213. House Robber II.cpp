class Solution {
public:
    int DP(vector<int>& nums, int a,int b)
    {
        int n1,n2,res;
        n1=nums[a];
        n2=max(nums[a],nums[a+1]);
        res=max(nums[a],nums[a+1]);
        for(int i=a+2;i<b+1;i++)
        {
            res=max(n1+nums[i],n2);
            n1=n2;
            n2=res;
        }
        return res;
    }
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        else if(n==2)
        {
            return max(nums[0],nums[1]);
        }
        int ans = max(DP(nums,0,n-2), DP(nums,1,n-1));
        return ans;
        
    }
};

/*
Comment:
dp[i]=max(dp[i-1],dp[i-2]+nums[i])
DP(nums,0,n-2):不含最後element
DP(nums,1,n-1):不含第一個element
取兩者中最大即為所求。
*/

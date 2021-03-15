class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return nums[0];
        else if(n==2)
            return max(nums[0],nums[1]);
        int n1,n2,res;
        n1=nums[0];
        n2=max(nums[0],nums[1]);
        for(int i=2;i<n;i++)
        {
            res=max(n1+nums[i], n2);
            n1=n2;
            n2=res;
        }
        return res;
    }
};

/*
algo 1:
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return nums[0];
        vector<int> dp(n);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++)
        {
            dp[i]=max(dp[i-2]+nums[i], dp[i-1]);
        }
        return dp[n-1];
    }
};
Comment:
DP algo.
dp[i]=max(dp[i-2]+nums[i] , dp[i-1])
*/

/*
algo 2:
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return nums[0];
        else if(n==2)
            return max(nums[0],nums[1]);
        int n1,n2,res;
        n1=nums[0];
        n2=max(nums[0],nums[1]);
        for(int i=2;i<n;i++)
        {
            res=max(n1+nums[i], n2);
            n1=n2;
            n2=res;
        }
        return res;
    }
};
Comment:
只需兩變數來存前兩個dp。
*/

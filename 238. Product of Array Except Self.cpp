class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int N = nums.size();
        vector<int> ans(N, 1);
        int back = 1;
        for(int i = 1; i < N; i++)
            ans[i] = ans[i-1] * nums[i-1];
        for(int j = N - 2; j >= 0; j--)
        {
            back *= nums[j+1];
            ans[j] = ans[j] * back;
        }
        return ans;
    }
};
/*
Algo 2:
Comment:
改良Algo 1使空間複雜度降為Ｏ(1)
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(1)
*/

/*
Algo 1:
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        vector<int> front(nums.size(), 1);
        vector<int> back(nums.size(), 1);
        for(int i = 1; i < nums.size(); i++)
            front[i] = front[i-1] * nums[i-1];
        for(int j = nums.size() - 2; j >= 0; j--)
            back[j] = back[j+1] * nums[j+1];
        for(int k = 0; k < nums.size(); k++)
            ans[k] = front[k] * back[k];
        return ans;
    }
};
Comment:
利用兩個vector front,back
front[i] = nums[0]~nums[i-1]的乘積 
back[i] = nums[i+1]~nums[end]的乘積 
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(n)
*/

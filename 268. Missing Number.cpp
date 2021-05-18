class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int N = nums.size();
        int sum = 0;
        int origin = N * (1 + N) / 2;
        for(auto n : nums)
        {
            sum += n;
        }
        return origin - sum;
    }
};
/*
Algo 2:
Comment:
若沒有缺失的情況為origin = 0+1+...+N
所以origin - element的sum 即為所求
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(1)
*/

/*
Algo 1:
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int N = nums.size();
        int ans = 0;
        for(int i = 1; i <= N; i++)
            ans ^= i;
        for(auto n : nums)
            ans ^= n;
        return ans;
    }
};
Comment:
利用把全部雙數個只有一個落單XOR可以得到唯一落單
先把0~N都XOR一次，再把element XOR即可找出miss的element
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(1)
*/

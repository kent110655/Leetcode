class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(auto n : nums)
            ans ^= n;
        return ans;
    }
};
/*
Comment:
利用XOR(^)性質
x ^ 0s = x
x ^ 1s = ~x
x ^ x = x
所有element XOR以後會剩下唯一一個單獨的數
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(1)
*/

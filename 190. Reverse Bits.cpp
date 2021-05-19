class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for(int i = 0; i < 32; i++)
        {
            ans <<= 1;
            ans |= n & 1;
            n >>= 1;
        }
        return ans;
    }
};
/*
Comment:
反轉32bit的數字
利用bit operate反轉
如果數字可能為負數，則使用%以及/會有錯誤，所以使用bit operate來做
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(1)
*/

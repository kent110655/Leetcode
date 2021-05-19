class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0)
            return false;
        bool one = false;
        while(n != 0)
        {
            if((n & 1) && !one)
                one = true;
            else if((n & 1) && one)
                return false;
            n >>= 1;
        }
        return true;
    }
};
/*
Comment:
判斷使否為2的次方數
判斷integer的二進位是否只有一個1即可
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(1)
*/

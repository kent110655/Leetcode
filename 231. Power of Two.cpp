class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n > 0) && (n & (n-1)) == 0;
    }
};
/*
Algo 2:
利用 n & (n-1) 即是消除最低位的1的操作
如果消除最低位1以後為0即代表只有一個1
*/

/*
Algo 1:
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
Comment:
判斷使否為2的次方數
判斷integer的二進位是否只有一個1即可
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(1)
*/

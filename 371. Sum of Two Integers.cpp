class Solution {
public:
    int getSum(int a, int b) {
        if(b == 0)
            return a;
        int sum = a ^ b;
        int carry = (a & b & 0b011111111111111111111111111111111) << 1;
        return getSum(sum, carry);
    }
};
/*
Comment:
加法器的概念
a+b不考慮進位 sum 為 a ^ b
a+b的進位 carry 為 (a & b) << 1
所求為 carry + sum
以Recursive計算，直到 carry=0 終止recursive。(不再進位)
P.S.
compiler無法接受負數往左移，所以要把a&b的最高位bit變為0才能左移。
所以要AND 0b011111111111111111111111111111111 使最高位bit變為0
*/

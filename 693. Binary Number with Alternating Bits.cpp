class Solution {
public:
    bool hasAlternatingBits(int n) {
        int a = n ^ (n >> 2);
        return (a & (a-1)) == 0;
        
    }
};
/*
Comment:
若符合條件，把數字右移兩位，再與原本n XOR 可得 a = 100..000
a-1 = 111...1111
所以 a & (a-1) 必為0
*/

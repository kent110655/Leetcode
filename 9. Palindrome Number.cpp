class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x % 10 == 0 && x != 0))
            return false;
        int right = 0;
        while(x > right)
        {
            right = right * 10 + x % 10;
            x /= 10;
        }
        return (right == x) || (right / 10 == x);
    }
};
/*
Comment:
把x的右半邊獨立出來並且反轉成right。
比較x跟right相同(要考慮奇數位數)
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(1)
*/

class Solution {
public:
    string toHex(int num) {
        if(num == 0)
            return"0";
        char symbol[16]
        = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
        string ans;
        long long n = num < 0 ? (1LL << 32) + num : num;
        while(n != 0)
        {
            ans = symbol[n % 16] + ans;
            n /= 16;
        }
        return ans;
    }
};
/*
Comment:
2's complement運算
32bit的-a的二補數為 2^33 - a
EX: -40的二補數 = 2^8 - 40 = 100000000 - 00100000
所以當num為負數時，2^33 + num 即為 -num 的二補數表示
時間複雜度：Ｏ(log n)
空間複雜度：Ｏ(log n)
*/


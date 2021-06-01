class Solution {
public:
    int trailingZeroes(int n) {
        int cnt = 0;
        while(n > 0)
        {
            cnt += n / 5;
            n /= 5;
        }
        return cnt;
    }
};
/*
Algo 2:
Comment:
以iter實作。
時間複雜度：Ｏ(log n)
空間複雜度：Ｏ(log n)
*/

/*
Algo 1:
class Solution {
public:
    int trailingZeroes(int n) {
        return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
    }
};
Comment:
找2*5的組合最多個數(0從2*5來)
因為階乘中2必定比5多，所以只要找5有幾個即可。
5個數 = 5的倍數個數 + 25的倍數個數 + ... = n/5 + n/25 + n/125 + ....
以遞迴實作。
時間複雜度：Ｏ(log n)
空間複雜度：Ｏ(log n)
*/

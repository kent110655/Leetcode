class Solution {
public:
    int hammingDistance(int x, int y) {
        int XOR = x ^ y;
        int ans = 0;
        while(XOR != 0)
        {
            ans += (XOR & 1 == 1) ? 1 : 0;
            XOR = XOR>>1;
        }
        return ans;
    }
};

/*
Comment:
找出不同的bit有幾個
利用XOR(^)令不同的bit=1,相同的bit=0
再利用 XOR & 1 來求出第一位bit的值
再把XOR右移(>>)
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(1)
*/

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);
        for(int i = 1; i <= n; i ++)
        {
            ans[i] = ans[i&(i-1)] + 1;
        }
        return ans;
    }
};
/*
Algo 3:
Comment:
i & (i-1) : 去除i的最低位1 EX: 1100110 -> 1100100
所以把(去除最低位1的數)重新加上(失去的那個1)即為所求
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(1)
*/

/*
Algo 2:
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);
        for(int i = 1; i <= n; i ++)
        {
            if(i % 2 == 1)
                ans[i] = ans[i-1] + 1;
            else
                ans[i] = ans[i/2];
        }
        return ans;
    }
};
Comment:
如果最低位 = 1，則ans[i] = ans[i-1] + 1
(ans[i-1]再加上i的1)
如果最低位 = 0，則ans[i] = ans[i/2]
(ans[i/2]比ans[i]少個0)
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(1)
*/

/*
Algo 1:
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);
        for(int i = 0; i <= n; i ++)
        {
            int t = i;
            while(t != 0)
            {
                if(t % 2 == 1)
                    ans[i]++;
                t /= 2;
            }
        }
        return ans;
    }
};
Comment:
一個個值分別重新算
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(1)
*/

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans(n);
        int back = k+1;
        int front = 1;
        for(int i = 0; i < k+1; i++)
        {
            if(i % 2 == 0)
            {
                ans[i] = front;
                front++;
            }
            else
            {
                ans[i] = back;
                back--;
            }
        }
        for(int j = k + 1; j < n; j++)
        {
            ans[j] = j + 1;
        }
        return ans;
    }
};
/*
Comment:
盡可能容納不同的差值
次序：1, k+1, 2, k, 3, k-1, ... k/2, k/2+1
差值：k, k-1, k-2, ....., 1
滿足k個差值以後，剩下的數以升序排列(差值為1必出現過)
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(1)
*/

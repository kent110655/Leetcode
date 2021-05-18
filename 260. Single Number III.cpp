class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans(2,0);
        int XOR = 0;
        for(auto n : nums)
            XOR ^= n;
        int diff = 1;
        while((XOR & diff) == 0)
        {
            diff <<= 1;
        }
        for(int u : nums)
        {
            if((u & diff) == 0)
                ans[0] ^= u;
            else
                ans[1] ^= u;
        }
        return ans;
    }
};
/*
Algo 2:
Comment:
更改尋找最低位1的方法，以迴避-diff的overflow
另設一個diff從1開始往左移 直到 diff & XOR != 0 (即為1對上最低位的1)
*/


/*
Algo 1:
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans(2,0);
        int diff = 0;
        for(auto n : nums)
            diff ^= n;
        diff = diff & (-diff);
        for(int u : nums)
        {
            if((u & diff) == 0)
                ans[0] ^= u;
            else
                ans[1] ^= u;
        }
        return ans;
    }
};
Comment:
假設落單element為a,b
思路：把element分成兩部分，a,b各在一邊，且相同的element要在同一邊。再分別找落單element。
先利用XOR所有element得出diff (diff = a ^ b)
因為此時diff中為1的bit代表a,b在此bit是相異的
所以以此來當作判別兩部分的依據
隨便挑diff其中一個為1的bit當作判別把element分成兩部分(bit=1 / bit=0)
利用取最低位1的做法取得diff的最低位的1(不一定要最低位的1，只要是1皆可用)
x & (-x) = 最低位1 (ex: x = 110100 --> 000100)
再把所有element & 最低位1 是否等於0即可分成兩部分來XOR找落單
P.S. 因為&的優先度低於==，所以要()才正確。
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(1)
RE (因為-diff overflow)
*/

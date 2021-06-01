class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
        while(columnNumber > 0)
        {
            if(columnNumber % 26 == 0)
            {
                ans = 'Z' + ans;
                columnNumber -= 26;
            }
            else
            {
                char s = 'A' + columnNumber % 26 - 1;
                ans = s + ans;
                columnNumber -= columnNumber % 26;
            }
            columnNumber /= 26;
        }
        return ans;
    }
};

/*
Comment:
26的倍數要分開計算。
時間複雜度：Ｏ(logn)
空間複雜度：Ｏ(logn)
*/

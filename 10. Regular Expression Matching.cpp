class Solution {
public:
    bool isMatch(string s, string p) {
        int sN = s.size();
        int pN = p.size();
        vector<vector<bool>> dp(sN + 1, vector<bool>(pN + 1));
        dp[0][0] = true;    //s,p皆空
        for(int j = 1; j <= pN; j++)    //s空, p非空
        {
            if(p[j-1] == '*')
            {
                dp[0][j] = dp[0][j-2];
            }
            else
            {
                dp[0][j] = false;
            }
        }
        
        for(int i = 1; i <= sN; i++)
        {
            for(int j = 1; j <= pN; j++)
            {
                if(s[i-1] == p[j-1] || p[j-1] == '.')
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[j-1] == '*')
                {
                    if(p[j-2] != s[i-1] && p[j-2] != '.')
                    {
                        dp[i][j] = dp[i][j-2];
                    }
                    else
                    {
                        dp[i][j] = dp[i][j-2] || dp[i][j-1] || dp[i-1][j];
                    }
                }
                
            }
        }
        return dp[sN][pN];
    }
};

/*
Comment:
dp[i][j]:s的前i個 與 p的前j個 match與否
Case 1: s,p皆為空  --> True
Case 2: s非空, p空 --> Fasle
Case 3: s空, p非空
    p = "a*" or ".*"  --> True
    others            --> Fasle
    (如果遇到*，則可以把*與前一個化為空)
Case 4: s,p非空
    更新dp:
    Case 1：s第i個 與 p第j個 相同
        dp[i][j] = dp[i-1][j-1]
    Case 2：p第j個為'.'
        dp[i][j] = dp[i-1][j-1]
    Case 3：p第j個為'*'
        Case 1：p第j-1個 不等於 s第i個 也不等於'.'
            只能把p的第j個與第j-1個變成空
            dp[i][j] = dp[i][j-2]
        Case 2：p第j-1個 等於 s第i個 or '.'
            Case 1:把p的第j個(*)與第j-1個變成空(a* -> "")
                dp[i][j] = dp[i][j-2]   (當作a*不存在)
            Case 2:把p的第j個與第j-1個變成一個s第i個(a* -> a)
                dp[i][j] = dp[i][j-1]   (當作*不存在)
            Case 3:把p的第j個(*)變成多個s第i個(a* -> aa...aa)
                dp[i][j] = dp[i-1][j]   (當作s的a不存在，因為不差這個a)
            三種Case只要有一個可以為true即可使dp[i][j]=true
時間複雜度：Ｏ(sN*pN)
空間複雜度：Ｏ(sN*pN)
*/

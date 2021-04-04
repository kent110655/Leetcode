class Solution {
public:
    int numDecodings(string s) {
        int size=s.size();
        if(s[0]=='0')
            return 0;
        else if(size==1)
            return 1;
        
        vector<int> dp(size);
        dp[0]=1;
        if(atoi(s.substr(0,2).c_str())<=26)
        {
            dp[1]=(s[1]=='0') ? 1:2;
        }
        else
        {
            dp[1]=(s[1]=='0') ? 0:1;
        }
        
        for(int i=2;i<size;i++)
        {
            int two = atoi(s.substr(i-1,2).c_str());
            
            if(two==0)          //two=ab -> a=0,b=0 -> fail!
                return 0;
            else if(s[i]=='0')  //b=0 ,so ab must combine 
            {
                if(two>26)      //ab>26 , so ab can't combine, fail!
                    return 0;
                else            //legal
                    dp[i]=dp[i-2];
            }
            else if(s[i-1]=='0')    //a=0 ,so b must be alone
            {
                dp[i]=dp[i-1];
            }
            else                    //a!=0 , b!=0 , ab can combine or separate
            {
                if(two>26)      //ab>26 , so ab can't combine, b must be alone
                    dp[i]=dp[i-1];
                else
                    dp[i]=dp[i-1]+dp[i-2];
            }
        }
        return dp[size-1];
    }
};

/*
Comment:
使用DP。
每次取出前兩個數字ab來判斷，利用兩個條件分Case：
1. ab>26
2. a=0? b=0?

Case 1: ab=0
    fail!
    
Case 2: a=0 (b must be alone)
    dp[i]=dp[i-1]
    
Case 3: b=0 (ab must combine), ab<=26
    dp[i]=dp[i-2]
    
Case 4: b=0 (ab must combine), ab>26 (ab must not combine)
    fail!
    
Case 5: a!=0, b!=0, ab>26 (ab must not combine)
    dp[i]=dp[i-1]
    
Case 6: a!=0, b!=0, ab<=26 (ab can combine or separate)
    dp[i]=dp[i-1]+dp[i-2]

P.S. 初始邊界條件需詳細設好！
*/

class Solution {
public:
    int numSquares(int n) {
        while(n%4 == 0)
            n/=4;
        if(n%8==7)
            return 4;
        for(int i=0;i*i<=n;i++)
        {
            int j = sqrt(n-i*i);
            if(i*i+j*j==n)
            {
                return !!i+!!j; 
            }
        }
        return 3;
    }
};
/*
Algo 3:
Comment:
利用四平方和定理。
根据四平方和定理，任意一个正整数均可表示为4个整数的平方和，其实是可以表示为4个以内的平方数之和，那么就是说返回结果只有 1,2,3 或4其中的一个，首先我们将数字化简一下，由于一个数如果含有因子4，那么我们可以把4都去掉，并不影响结果，比如2和8,3和12等等，返回的结果都相同，读者可自行举更多的栗子。还有一个可以化简的地方就是，如果一个数除以8余7的话，那么肯定是由4个完全平方数组成，这里就不证明了，因为我也不会证明，读者可自行举例验证。那么做完两步后，一个很大的数有可能就会变得很小了，大大减少了运算时间，下面我们就来尝试的将其拆为两个平方数之和，如果拆成功了那么就会返回1或2，因为其中一个平方数可能为0. (注：由于输入的n是正整数，所以不存在两个平方数均为0的情况)。注意下面的 !!a + !!b 这个表达式，可能很多人不太理解这个的意思，其实很简单，感叹号!表示逻辑取反，那么一个正整数逻辑取反为0，再取反为1，所以用两个感叹号!!的作用就是看a和b是否为正整数，都为正整数的话返回2，只有一个是正整数的话返回1。
*/

/*
Algo 1:
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1);
        vector<int> perfectN;
        dp[0]=0;
        dp[1]=1;
        perfectN.push_back(1);
        for(int i=2;i<=n;i++)
        {
            int M = sqrt(i);
            if(M*M==i)
            {
                dp[i]=1;
                perfectN.push_back(i);
            }
            else
            {
                dp[i]=INT_MAX;
                for(auto u:perfectN)
                {
                    dp[i]=min(dp[i],dp[u]+dp[i-u]);
                }
            }
        }
        return dp[n];
    }
};

Comment:
DP。
紀錄完全平方數在perfectN中，並且把dp[i]所能組合的可能性中找出最小的。
*/

/*
Algo 2:
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1);
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            int M = sqrt(i);
            if(M*M==i)
            {
                dp[i]=1;
            }
            else
            {
                dp[i]=INT_MAX;
                for(int j=1;j*j<i;j++)
                {
                    dp[i]=min(dp[i],dp[i-j*j]+1);
                }
            }
        }
        return dp[n];
    }
};

Comment:
DP。
不用另外紀錄完全平方數，直接用j*j的方法直接得出可以用的完全平方數。
*/

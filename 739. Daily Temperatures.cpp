class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> ans(T.size(), 0);
        stack<int> temper;
        for(int i = 0; i < T.size(); i++)
        {
            while(!temper.empty() && T[i] > T[temper.top()])
            {
                ans[temper.top()] = i - temper.top();
                temper.pop();
            }
            temper.push(i);
        }
        return ans;
    }
};
/*
Comment:
利用一個stack，依序把溫度的"index"放入stack
如果即將放入的溫度比top的溫度高
則代表目前這個是目前top的下一個高溫。
更新ans的值，再把值pop出來
重複操作直到top溫度比當前溫度大時再把當前溫度push進去
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(n)
*/

/*
Algo 1:
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> ans(T.size(), 0);
        for(int i = 0; i < T.size(); i++)
        {
            for(int t = i+1; t < T.size(); t++)
            {
                if(T[i] < T[t])
                {
                    ans[i] = t-i;
                    break;
                }
            }
        }
        return ans;
    }
};
Comment:
暴力法 ＴＬＥ
時間複雜度：Ｏ(n^2)
空間複雜度：Ｏ(n)
*/

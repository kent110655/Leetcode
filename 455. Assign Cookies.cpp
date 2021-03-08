class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0;
        int j=0;
        int count=0;
        while(j<s.size() && i<g.size())
        {
            if(s[j]>=g[i])
            {
                count++;
                j++;
                i++;
            }
            else
            {
                j++;
            }
        }
        return count;
    }
};

/*
Comment:
利用Greedy完成。
不保證s,g中按大小排序，所以要先sort。
時間複雜度：Ｏ(n)
*/

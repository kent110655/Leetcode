class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_map<char,int> map;
        vector<int> ans;
        for(int i=0;i<S.size();i++)
        {
            map[S[i]]=i;
        }
        
        int start=0;
        int end=0;
        for(int i=0;i<S.size();i++)
        {
            end=max(end,map[S[i]]);
            if(i==end)
            {
                ans.push_back(end-start+1);
                start=end+1;
            }
        }
        return ans;
    }
};

/*
algo 1:
class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_map<char,int> map;
        vector<int> posi;
        for(int i=0;i<S.size();i++)
        {
            map[S[i]]=i;
        }
        
        int j=0;
        int top=map[S[0]];
        while(j<S.size())
        {
            top=map[S[j]];
            while(j<=top)
            {
                top=max(map[S[j]],top);
                j++;
            }
            posi.push_back(top);
            
        }
        
        vector<int> ans(posi.size());
        ans[0]=posi[0]+1;
        for(int t=1;t<posi.size();t++)
        {
            ans[t]=posi[t]-posi[t-1];
        }
        return ans;
    }
};
Comment:
1.製作hash table紀錄每種字母的最後位置
2.掃過String S，掃過的字母更新此次掃過的上限top（查hash table）
3.直到掃到top為止，即為一個分段落！
4.重複2.3直到掃完S，即可得分段落的位置posi
5.把posi改成題目所求的每段長度ans即為所求。
Time complexity:Ｏ(n)
*/

/*
algo 2:
class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_map<char,int> map;
        vector<int> ans;
        for(int i=0;i<S.size();i++)
        {
            map[S[i]]=i;
        }
        
        int start=0;
        int end=0;
        for(int i=0;i<S.size();i++)
        {
            end=max(end,map[S[i]]);
            if(i==end)
            {
                ans.push_back(end-start+1);
                start=end+1;
            }
        }
        return ans;
    }
};

Comment:
與algo 1 想法相同，寫法較精簡。
改用start、end來記錄每段開始與結束
直接用ans紀錄每段長度（start-end+1）
Time complexity:Ｏ(n)
*/

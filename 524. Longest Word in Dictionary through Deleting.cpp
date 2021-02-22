class Solution {
public:
    string findLongestWord(string s, vector<string>& d) 
    {
        string result="";
        sort(d.begin(), d.end());
        for(auto word:d)
        {
            if(checkWord(s,word))
            {
                if(result.size()<word.size())
                    result=word;
            }
        }
        return result;
    }
    
    bool checkWord(string dic, string word)
    {
        int j=0;
        for(int i=0;i<dic.size();i++)
        {
            if(dic[i]==word[j])
            {
                j++;
            }
        }
        if(j==word.size())
        {
            return true;
        }
        else
            return false;
    }
};

/*
comment:
1. sort dirtionary 使之按照字母順序排列
2. checkWord()利用雙pointer一一對照s與dir中是否相符
3. 找出dir中符合的最長的string即可

時間複雜度：
sort:O(nlogn)
checkWord:O(dir中string總和長度)
-->O(nlogn)
*/

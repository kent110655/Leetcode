class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size())
            return false;
        for(int i = 0; i < s.size(); i++)
        {
            if(s.find(s[i]) != t.find(t[i]))
                return false;
        }
        return true;
    }
};
/*
Comment:
利用string中的find，比對s,t每個char第一次出現在string中的位置。
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(1)
*/

/*
Algo 1:
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size())
            return false;
        unordered_map<char,int> smap,tmap;
        int count = 1;
        for(auto e:s)
        {
            if(smap[e] == 0)
            {
                smap[e] = count;
                count++;
            }
        }
        count = 1;
        for(auto e:t)
        {
            if(tmap[e] == 0)
            {
                tmap[e] = count;
                count++;
            }
        }
        for(int i = 0; i < s.size(); i++)
        {
            if(tmap[t[i]] != smap[s[i]])
                return false;
        }
        return true;
    }
};
Comment:
利用兩個hash table分別紀錄s,t的每個字母是第幾個出現的字母
再比對他們的結構即可
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(n)
*/

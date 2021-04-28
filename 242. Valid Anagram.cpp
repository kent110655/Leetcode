class Solution {
public:
    bool isAnagram(string s, string t) {
        int s_size = s.size();
        int t_size = t.size();
        if(s_size != t_size)
            return false;
        vector<int> Eng(26,0);
        for(int i = 0; i < s_size; i++)
        {
            Eng[s[i] - 'a']++;
            Eng[t[i] - 'a']--;
        }
        for(auto e: Eng)
            if(e != 0)
                return false;
        return true;
    }
};
/*
Comment:
check 兩個string字母組成數量是否相同。
以一個vector紀錄26個小寫字母數量增減即可。
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(1)
*/

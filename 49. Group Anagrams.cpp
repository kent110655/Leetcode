class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        if(strs.size() == 0 || strs.size() == 1)
        {
            result.push_back(strs);
            return result;
        }
        map<vector<int>, vector<string>> m;
        for(auto s : strs)
        {
            vector<int> cnt(26);
            for(auto c : s)
            {
                cnt[c-'a']++;
            }
            if(m.count(cnt) == 0)
            {
                m.insert({cnt, {s}});
            }
            else
            {
                m[cnt].push_back(s);
            }
        }
        for(auto v : m)
        {
            result.push_back(v.second);
        }
        return result;
    }
};

/*
Comment:
Compared to Algo1, this solution uses vector<int> instead of map<char,int> due to the the letters are limited to lowercase english letters.
This solution uses map data structure map<vector<int>, vector<string>>. By using vector<int> to represent each string as a frequency map of charactors, we can group the anagram strings together. After processing all strings, the anagrams are stored in the values of the map, which can be easily retrieved.
Time Complexity:Ｏ(a*b + a*loga) = Ｏ
Space Complexity:Ｏ(a*b)
a=strs.length, b=strs[i].length
*/

/*
Algo1:
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        if(strs.size() == 0 || strs.size() == 1)
        {
            result.push_back(strs);
            return result;
        }
        map<map<char,int>, vector<string>> m;
        for(auto s : strs)
        {
            map<char,int> tempt;
            for(auto c : s)
            {
                tempt[c]++;
            }
            if(m.count(tempt) == 0)
            {
                m.insert({tempt, {s}});
            }
            else
            {
                m[tempt].push_back(s);
            }
        }
        for(auto v : m)
        {
            result.push_back(v.second);
        }
        return result;
    }
};
Comment:
This solution uses map data structure map<map<char, int>, vector<string>>. By using map<char, int> to represent each string as a frequency map of charactors, we can group the anagram strings together. After processing all strings, the anagrams are stored in the values of the map, which can be easily retrieved.
Time Complexity:Ｏ(a*b + a*loga) = Ｏ
Space Complexity:Ｏ(a*b)
a=strs.length, b=strs[i].length
*/

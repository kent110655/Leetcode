class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> tmap(128);
        for(auto c:t)
        {
            tmap[c] += 1;
        }

        int left = 0;
        int right = 0;
        int min_left = -1;
        int min_len = INT_MAX;
        int success_cnt = 0;
        
        // Initial start
        if(tmap[s[0]] > 0)
        {
            success_cnt++;
        }
        tmap[s[0]]--;

        while(right < s.size())
        {
            if(success_cnt != t.size())
            {
                right++;
                if(tmap[s[right]] > 0)
                {
                    success_cnt++;
                }
                tmap[s[right]]--;
            }
            else
            {
                if(min_len > right - left + 1)
                {
                    min_left = left;
                    min_len = right - left + 1;
                }
                
                if(tmap[s[left]] >= 0)
                {
                    success_cnt--;
                }
                tmap[s[left]]++;
                left++;
            }
        }
        return min_left == -1 ? "" : s.substr(min_left, min_len);
    }
};

/*
Comment:
Algo3:

改良Algo2的做法
1. 以紀錄min_left與min_len兩個integer來代表最小子字串(取代algo2的string result) -> 省string result空間
2. 使用一個success_cnt紀錄目前滿足t字串的字母數，跟t.size()比較來判斷子字串是否有合規 -> 省int type_count空間

success_cnt 紀錄：目前滿足t字串的字母數
兩個pointer left, right代表目前子字串的第一個字母跟最後一個字母
一個while迴圈實現slide window邏輯：
當success_cnt != t.size()代表目前還未滿足條件，則right右移新增新的字母進入子字串
當success_cnt == t.size()代表目前已滿足條件，則left右移減少子字串長度，且同時更新min_left與min_len
最後依min_left與min_len回傳最短子字串

m == s.length
n == t.length
Time Complexity: Ｏ(m+n)
Space Complexity: Ｏ(m+n)



Algo1:
class Solution {
public:
    string minWindow(string s, string t) {
        string result = "@";
        unordered_map<char, int> tmap;
        unordered_map<char, int> current;
        for(auto i:t)
        {
            tmap[i] += 1;
        }
        int type_count = tmap.size();
        int left = 0;
        int right = 0;
        int success_count = 0;
        if(tmap.find(s[0]) != tmap.end())
        {
            current[s[0]]++;
            if(current[s[0]] == tmap[s[0]])
            {
                success_count++;
            }
        }
        while(left <= right && right < s.size())
        {
            if(success_count != type_count)
            {
                right++;
                if(tmap.find(s[right]) != tmap.end())
                {
                    current[s[right]] += 1;
                    if(current[s[right]] == tmap[s[right]])
                    {
                        success_count++;
                    }
                }
            }
            else
            {
                //first match substring
                if(result == "@")
                {
                    result = s.substr(left, right-left+1);
                }
                result = (result.size() > right - left + 1) ? s.substr(left, right-left+1) : result;
                
                if(tmap.find(s[left]) != tmap.end())
                {
                    current[s[left]] -= 1;
                    if(current[s[left]]+1 == tmap[s[left]])
                    {
                        success_count--;
                    }
                }
                left++;
            }
        }
        if(result == "@")
        {
            result = "";
        }
        return result;
    }
};

Comment:

兩個hash table分別紀錄 需要的字母數tmap、現有字串的字母數current
type_count 紀錄：需要幾種字母
success_count 紀錄：目前已滿足幾種字母
兩個pointer left, right代表目前子字串的第一個字母跟最後一個字母
一個while迴圈實現slide window邏輯：
當success_count != type_count代表目前還未滿足條件，則right右移新增新的字母進入子字串
當success_count == type_count代表目前已滿足條件，則left右移減少子字串長度，且同時更新 最短合規子字串result
最後回傳result (若result為初始值則回傳"")

m == s.length
n == t.length
Time Complexity: Ｏ(m+n)
Space Complexity: Ｏ(m+n)
此algo MLE，需嘗試減低memory用量





Algo2:
class Solution {
public:
    string minWindow(string s, string t) {
        string result = "@";
        vector<int> tmap(128);
        for(auto c:t)
        {
            tmap[c] += 1;
        }
        int type_count = 0;
        for(int i = 0; i < 128; i++)
        {
            if(tmap[i] != 0)
            {
                type_count++;
            }
        }
        int left = 0;
        int right = 0;
        int success_count = 0;

        tmap[s[0]]--;
        if(tmap[s[0]] == 0)
        {
            success_count++;
        }

        while(left <= right && right < s.size())
        {
            if(success_count != type_count)
            {
                right++;
                tmap[s[right]] -= 1;
                if(tmap[s[right]] == 0)
                {
                    success_count++;
                }
            }
            else
            {
                //first match substring
                if(result == "@")
                {
                    result = s.substr(left, right-left+1);
                }
                result = (result.size() > right - left + 1) ? s.substr(left, right-left+1) : result;
                
                if(tmap[s[left]] == 0)
                {
                    success_count--;
                }
                tmap[s[left]] += 1;
                left++;
            }
        }
        if(result == "@")
        {
            result = "";
        }
        return result;
    }
};



Comment:
改良Algo1的做法
把兩個hash table改成一個大小128的vector tmap。
因為使用的char只限於字母，所以可以直接用字母代表vector的第幾個element。
並且動態更新tmap，不需兩個vector來分別紀錄需要的/現有的字母

type_count 紀錄：需要幾種字母
success_count 紀錄：目前已滿足幾種字母
兩個pointer left, right代表目前子字串的第一個字母跟最後一個字母
一個while迴圈實現slide window邏輯：
當success_count != type_count代表目前還未滿足條件，則right右移新增新的字母進入子字串
當success_count == type_count代表目前已滿足條件，則left右移減少子字串長度，且同時更新 最短合規子字串result
最後回傳result (若result為初始值則回傳"")

m == s.length
n == t.length
Time Complexity: Ｏ(m+n)
Space Complexity: Ｏ(m+n)
此algo MLE，需嘗試減低memory用量

*/


class Solution {
public:
    int countBinarySubstrings(string s) {
        int cnt = 0;
        int pre = 0;
        int cur = 1;
        for(int i = 1; i < s.size(); i++)
        {
            if(s[i-1] == s[i])
                cur++;
            else
            {
                pre = cur;
                cur = 1;
            }
            if(pre >= cur)
                cnt++;
        }
        return cnt;
    }
};
/*
Comment:
掃過一遍string，記錄之前與現在連續出現的數字數量，並且更新cnt。
https://www.cnblogs.com/grandyang/p/7716150.html
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(1)
*/

/*
Algo 1:
class Solution {
public:
    int countBinarySubstrings(string s) {
        for(int i = 0; i < s.size()-1; i++)
        {
            if(s[i] != s[i+1])
                count(s, i,i+1);
        }
        return cnt;
    }
private:
    int cnt = 0;
    void count(string& s, int start, int end)
    {
        int left = s[start];
        int right = s[end];
        while(start >= 0 && end < s.size() && s[start] == left && s[end] == right)
        {
            cnt++;
            start--;
            end++;
        }
    }
};
Comment:
把string中的每兩個char當作中心，並嘗試向左右擴張，從中紀錄成功數量。
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(1)
*/

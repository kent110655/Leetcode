class Solution {
public:
    int countSubstrings(string s) {
        for(int i = 0; i < s.size(); i++)
        {
            palindromic(s,i,i);
            palindromic(s,i,i+1);
        }
        return count;
    }
private:
    int count = 0;
    void palindromic(string& s, int start, int end)
    {
        while(start >= 0 && end < s.size() && s[start] == s[end])
        {
            count++;
            start--;
            end++;
        }
    }
};
/*
Comment:
把string中的每一個char當作回文中心，並嘗試向左右擴張，從中紀錄回文成功數量。
(當中心點需分成偶數與奇數兩種去討論)
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(1)
*/

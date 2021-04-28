class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> up(26);
        vector<int> low(26);
        bool mid = false;
        int count = 0;
        for(auto t : s)
        {
            if(t-'a'< 0)    //uppercase
                up[t-'A']++;
            else            //lowercase
                low[t-'a']++;
        }
        for(auto w: up)
        {
            if(w % 2 == 1)
            {
                mid = true;
                count += (w-1);
            }
            if(w % 2 == 0)
                count += w;
        }
        for(auto w: low)
        {
            if(w % 2 == 1)
            {
                mid = true;
                count += (w-1);
            }
            if(w % 2 == 0)
                count += w;
        }
        return count + mid;
    }
};
/*
Comment:
紀錄哪個字母的數量，把偶數、奇數-1的部分加總，再加上mid即為所求。
ASCll字母實作
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(1)
*/

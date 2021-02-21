class Solution {
public:
    bool validPalindrome(string s) {
        int i= 0;
        int j =s.size()-1;
        
        while(i<j)
        {
            if(s[i]!=s[j])
                return (palindrome(s,i+1,j)||palindrome(s,i,j-1));
            i++;
            j--;
        }
        return true;
    }
    
    bool palindrome(string s,int i,int j)
    {
        while(i<j)
        {
            if(s[i++]!=s[j--])
                return false;
        }
        return true;
    }
};


/*
comment:
先利用雙pointer做出純粹的palindrome function。
再利用雙指標尋找第一對不相符的char
因為可以刪掉一個，所以可以刪掉這一對的左char或右char
所以把跳過左、右的兩種結果使用palindrome function測出結果即為所求。
時間複雜度：O(n) -->只掃一遍(中間部分掃兩遍)
P.S.發現不相符的一對之前的char不用再檢查，一定是palindrome
*/

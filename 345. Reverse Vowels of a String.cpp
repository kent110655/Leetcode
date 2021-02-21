class Solution {
public:
    string reverseVowels(string s) {
        if(s.size()==1)
            return s;
        int i=0;
        int j=s.size()-1;
        while(i<=j)
        {
            while(vowelcheck(s[i])==false && i<=s.size()-1)
            {
                i++;
            }
            while(vowelcheck(s[j])==false && j>0)
            {
                j--;
            }
            if(i>j)
                break;
            swapV(s,i,j);
            i++;
            j--;
        }
        return s;
    }
    
    bool vowelcheck(char c)
    {
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
            return true;
        else
            return false;
    }
    
    void swapV(string& s,int i,int j)
    {
        char tempt = s[i];
        s[i]=s[j];
        s[j]=tempt;
    }
};



/*
comment:
利用雙pointer從兩端找vowel，找到後交換。
只需要遍尋一遍-->O(s.size())
P.S.注意i,j有可能超出到s的範圍外(ex:j<0)，邊界要注意！
*/

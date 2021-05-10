class Solution {
public:
    bool isValid(string s) {
        stack<char> S;
        for(auto c:s)
        {
            if(S.empty())
                S.push(c);
            else if(c == ')' && S.top() == '(')
                S.pop();
            else if(c == ']' && S.top() == '[')
                S.pop();
            else if(c == '}' && S.top() == '{')
                S.pop();
            else
                S.push(c);
        }
        return S.empty();
    }
};
/*
Comment:
利用prefix的括號法
依序把char放入stack，如果遇到對應的括號則一起pop出來
如果最後跑完後stack為空則是合法。
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(n)
*/

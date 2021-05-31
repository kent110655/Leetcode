class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0)
            return "0";
        string ans;
        stack<string> reverse;
        bool negative = (num > 0) ? false:true;
        num = (num < 0) ? -num : num;
        while(num != 0)
        {
            string s(to_string(num % 7));
            reverse.push(s);
            num /= 7;
        }
        while(!reverse.empty())
        {
            ans.append(reverse.top());
            reverse.pop();
        }
        return negative ? "-" + ans : ans;
    }
};
/*
Comment:
轉成7進位制。
*/

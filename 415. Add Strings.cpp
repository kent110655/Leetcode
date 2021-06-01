class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0;
        int sum = 0;
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        string ans;
        while(i >= 0 || j >= 0 || carry == 1)
        {
            int n1 = i >= 0 ? num1[i] - '0' : 0;
            int n2 = j >= 0 ? num2[j] - '0' : 0;
            sum = (n1 + n2 + carry) % 10;
            carry = (n1 + n2 + carry) / 10;
            ans = (char)(sum + '0') + ans;
            i--;
            j--;
        }
        return ans;
    }
};
/*
Comment:
加法器實作。
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(1)
*/

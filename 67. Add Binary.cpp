class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        int sum = 0;
        int i = a.size() - 1;
        int j = b.size() - 1;
        string ans;
        while(i >=0 || j >= 0 || carry == 1)
        {
            int an = i >= 0 ? (a[i] - '0') : 0;
            int bn = j >= 0 ? (b[j] - '0') : 0;
            sum = (an + bn + carry) % 2;
            carry = (an + bn + carry) / 2;
            ans = (char)(sum + '0') + ans;
            i--;
            j--;
        }
        return ans;
    }
};

/*
Comment:
實作加法器。
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(1)
*/

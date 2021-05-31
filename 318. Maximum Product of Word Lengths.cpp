class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> binary(words.size(), 0);
        int ans = 0;
        for(int i = 0; i < words.size(); i++)
        {
            for(char u : words[i])
            {
                binary[i] |= 1 << (u - 'a');
            }
        }
        for(int j = 0; j < words.size(); j++)
        {
            for(int k = j + 1; k < words.size(); k++)
            {
                if((binary[j] & binary[k]) == 0)
                {
                    ans = max(ans, int(words[j].size()) * int(words[k].size()));
                }
            }
        }
        return ans;
    }
};

/*
Comment:
利用一個32bit的integer存26個字母的存在與否(1 or 0)
時間複雜度：Ｏ(n^2)
空間複雜度：Ｏ(n)
*/

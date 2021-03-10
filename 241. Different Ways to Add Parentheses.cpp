class Solution {
public:
    unordered_map<string,vector<int>> map;
    
    vector<int> diffWaysToCompute(string input) {
        if(map.count(input))
            return map[input];
        
        char op;
        vector<int> ans;
        for(int i=0;i<input.size();i++)
        {
            op=input[i];
            if(op=='+' || op=='-' || op=='*')
            {
                string s1=input.substr(0,i);
                string s2=input.substr(i+1);
                vector<int> left = diffWaysToCompute(s1);
                vector<int> right = diffWaysToCompute(s2);
                for(auto l:left)
                {
                    for(auto r:right)
                    {
                        switch(op)
                        {
                            case '+':
                                ans.push_back(l+r);
                                break;
                            case '-':
                                ans.push_back(l-r);
                                break;
                            case '*':
                                ans.push_back(l*r);
                                break;
                        }
                    }
                }
            }
        }
        if(ans.empty()) //純數字無運算子
        {
            ans.push_back(atoi(input.c_str()));
        }
        map[input]=ans;
        return ans;
    }
};

/*
Comment:
Divide-and-conquer algo.
依operator把string分兩段進行遞迴。
當只剩integer時直接return integer
利用hash table存string的結果來避免重複運算。
*/

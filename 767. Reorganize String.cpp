using PCI = pair<char,int>;
class Solution {
public:
    string reorganizeString(string s) {
        string result = "";
        unordered_map<char, int> hash;
        auto compare = [](const PCI& a, const PCI& b)
        {
            return a.second < b.second;
        };
        priority_queue<PCI, vector<PCI>, decltype(compare)> p;
        for(int i = 0; i < s.size(); i++)
        {
            hash[s[i]]++;
        }
        for(auto h:hash)
        {
            p.push({h.first, h.second});
        }
        char lastChar;
        while(!p.empty())
        {
            PCI next;
            bool needBack = false;
            if(p.top().first == lastChar)
            {
                next = p.top();
                p.pop();
                needBack = true;
                if(p.empty())
                    return "";
            }
            result.push_back(p.top().first);
            lastChar = p.top().first;
            if(p.top().second == 1)
            {
                p.pop();
            }
            else
            {
                auto tempt = p.top();
                tempt.second--;
                p.pop();
                p.push(tempt);
            }
            if(needBack)
                p.push(next);
        }
        return result;
    }
};
/*
Comment:
We use the Greedy alogrithm to solve the problem. First, We use max heap to store all the char, and the top element would always be the charactor with highest frequency. Then we start to build the result string. By the Greedy, we choose the charactor with highest frequency to be the next charactor. If the last charactor is the same as the current char, we need to choose the next high frequency charactor instead by popping the most char and pushing back after choosing the next charactor. Then we can get the result or found that it is impossible to rearrange in the limit.
Time Complexity:Ｏ(nlogn)
Space Complexity:Ｏ(n)
*/

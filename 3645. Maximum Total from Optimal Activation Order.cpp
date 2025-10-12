using PII = pair<int,int>;
class Solution {
public:
    long long maxTotal(vector<int>& value, vector<int>& limit) {
        auto compare = [](const pair<int,int>& a, const pair<int,int>& b)
        {
            if(a.second == b.second)
                return a.first > b.first;
            return a.second < b.second;
        };
        
        vector<PII> arr;
        for(int i =0; i < value.size(); i++)
        {
            arr.push_back({value[i], limit[i]});
        }
        sort(arr.begin(), arr.end(), compare);
        
        int currentAct = 0;
        long long total = 0;
        priority_queue<int, vector<int>, greater<int>> p; // active value
        unordered_set<int> ban;
        unordered_map<int,int> activeCnt; // [L, cnt] limit is L, cnt is active count

        for(auto e:arr)
        {
            auto V = e.first;
            auto L = e.second;
            
            if(ban.find(L) != ban.end())
                continue;

            if(currentAct < L) // active the element
            {
                total += V;
                p.push(V);
                currentAct++;
                activeCnt[L]++;

                ban.insert(currentAct);
                auto needInactiveCnt = activeCnt[currentAct];
                activeCnt[currentAct] = 0;
                currentAct -= needInactiveCnt;
            }
            // cannot active this element
            // can active the element and inactive the minimum value element
            else if(!p.empty() && p.top() < V) 
            {
                total += V - p.top();
                activeCnt[L]++; // inactive element can be ignored
                p.pop();
                p.push(V);
            }
        }
        return total;
    }
};

/*
Comment:
We should activate the element which has early limit. So we first sort the vector by limit. First, we use a min heap to get the minimum value which can be replaced first and a hash set store the element which is banned and a hash map to store the count of active element when limit is the key. Second, we can start from the begin of vector. If the current element is banned, we would do nothing to the element. Then, if the active quota is enough, we activate the current element and update the data tables, and we should handle the elements which break their limit. If the active quota is not enough, we can compare the minimum value in the active element and the value of the current element. We could replace the smaller one with the bigger one. Finally, we can get the maximum value in the calculation.
P.S. vector compare function is different from priority_queue compare function!
Time Complexity:Ｏ(nlogn)
Space Complexity:Ｏ(n)
*/

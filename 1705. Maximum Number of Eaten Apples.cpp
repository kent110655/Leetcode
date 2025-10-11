class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        auto compare = [](pair<int,int> a, pair<int,int> b)
        {
            return a.second > b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int,int>>, decltype(compare)> p(compare);
        int cnt = 0;
        int day = 0;
        while(!p.empty() || day < apples.size())
        {
            // remove rot apple
            while(!p.empty() && p.top().second <= day)
            {
                p.pop();
            }

            // add new apple
            if(day < apples.size() && apples[day] > 0)
                p.push({apples[day], day+days[day]});
            
            // eat a apple
            if(!p.empty())
            {
                auto e = p.top();
                e.first--;
                p.pop();
                if(e.first > 0)
                    p.push(e);
                cnt++;
            }
            day++;
        }
        return cnt;
    }
};

/*
Comment:
We want to get the apple which is rot recently. So we use a min heap (priority_queue) to get the apple that it has the closest rot day. Then we push the new apples into min heap. Finally, we eat a apple which is the top element in min heap and record the count of eaten apple at the same time. When heap is empty and day is over the tree produce apple date, the current count is the answer.
Time Complexity:Ｏ(nlogn)
Space Complexity:Ｏ(n)
*/

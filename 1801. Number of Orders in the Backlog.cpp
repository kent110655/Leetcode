using PII = pair<int,int>;
class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        auto maxCompare = [](PII& a, PII& b)
        {
            return a.first < b.first;
        };
        auto minCompare = [](PII& a, PII& b)
        {
            return a.first > b.first;
        };
        priority_queue<PII, vector<PII>, decltype(minCompare)> sell;
        priority_queue<PII, vector<PII>, decltype(maxCompare)> buy;
        for(auto& order : orders)
        {
            if(order[2] == 0) //type buy
            {
                while(!sell.empty() && order[1] > 0 && sell.top().first <= order[0])
                {
                    if(sell.top().second > order[1])
                    {
                        auto tempt = sell.top();
                        tempt.second -= order[1];
                        sell.pop();
                        sell.push(tempt);
                        order[1] = 0;
                    }
                    else
                    {
                        order[1] -= sell.top().second;
                        sell.pop();
                    }
                }
                if(order[1] > 0)
                    buy.push({order[0], order[1]});
            }
            else // type sell
            {
                while(!buy.empty() && order[1] > 0 && buy.top().first >= order[0])
                {
                    if(buy.top().second > order[1])
                    {
                        auto tempt = buy.top();
                        tempt.second -= order[1];
                        buy.pop();
                        buy.push(tempt);
                        order[1] = 0;
                    }
                    else
                    {
                        order[1] -= buy.top().second;
                        buy.pop();
                    }
                }
                if(order[1] > 0)
                    sell.push({order[0], order[1]});
            }
        }
        long long result = 0;
        int mod = 1000000007;
        while(!buy.empty())
        {
            result += buy.top().second % mod;
            result = result % mod;
            buy.pop();
        }
        while(!sell.empty())
        {
            result += sell.top().second % mod;
            result = result % mod;
            sell.pop();
        }
        return result;
    }
};

/*
Comment:
We use a min heap and a max heap to get the current minimum price orders and maximum price orders. Then we process each order and maintain two heaps by the rule. Compare the current order with the top value of heap. Finally, we can calculate remaining amount of orders in the two heaps.
Time Complexity:Ｏ(nlogn)
Space Complexity:Ｏ(n)
*/

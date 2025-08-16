class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        // build adjacency list
        vector<vector<int>> graph(edges.size()+1);
        for(auto e : edges)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        // find Bob path
        vector<int> bobPath;
        BobDFS(bobPath, graph, bob, 0, -1);
        vector<int> tempt(edges.size()+1, INT_MAX);
        bobPathRecord = tempt;
        for(int i = 0 ; i < bobPath.size(); i++)
        {
            bobPathRecord[bobPath[i]] = i;
        }
        return AliceDFS(graph, amount, 0, -1, 0);
    }

private:
    vector<int> bobPathRecord;
    bool BobDFS(vector<int>& bobPath, vector<vector<int>>& graph, int target, int nowPosi, int prePosi)
    {
        if(nowPosi == target)
        {
            bobPath.push_back(nowPosi);
            return true;
        }
        
        for(auto nextPosi : graph[nowPosi])
        {
            if(nextPosi == prePosi)
                continue;
            bool isTrue = BobDFS(bobPath, graph, target, nextPosi, nowPosi);
            if(isTrue == true)
            {
                bobPath.push_back(nowPosi);
                return true;
            }
        }
        return false;
    }

    int AliceDFS(vector<vector<int>>& graph, vector<int>& amount, int nowPosi, int prePosi, int time)
    {
        int maxIncome = INT_MIN;
        for(auto nextPosi : graph[nowPosi])
        {
            if(nextPosi == prePosi)
                continue;
            int incomeAmount = AliceDFS(graph, amount, nextPosi, nowPosi, time+1);
            maxIncome = max(maxIncome, incomeAmount);
    }
        maxIncome = maxIncome == INT_MIN ? 0 : maxIncome;

        if(bobPathRecord[nowPosi] > time)
        {
            maxIncome += amount[nowPosi];
        }
        else if(bobPathRecord[nowPosi] == time)
        {
            maxIncome += amount[nowPosi]/2;
        }

        return maxIncome;
    }
};

/*
Comment:
In this problem, we first find Bob's path because it is fixed and unchanging. 
Then, we use Bob's path as a reference to determine Alice's path that maximizes the income.
We use DFS to find Bob's path. Important tips for this DFS:
1. Avoid going back to the previous node (to prevent cycles in the tree).
2. Start DFS from the root (node 0) and end at Bob's node to record the correct sequence.
Next, we use DFS to explore all possible paths for Alice. Using Bob's path as a reference, 
we can determine the amount Alice can collect at each node depending on whether Bob has visited it yet. 
Finally, we obtain the path for Alice that yields the maximum income.
Time Complexity:Ｏ(n)
Space Complexity:Ｏ(n)
*/

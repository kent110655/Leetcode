class Solution {
public:
    int n;
    vector<vector<int>> ad;
    vector<int> values;
    vector<long long> sumValue;
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        // build adjacency list
        this->n = values.size();
        this->sumValue.resize(n);
        this->ad.resize(n);
        this->values = values;
        for(auto e : edges)
        {
            ad[e[0]].push_back(e[1]);
            ad[e[1]].push_back(e[0]);
        }

        return Funct(0, -1);
    }

private:
    long long Funct(int node, int pre)
    {
        if(ad[node].size() == 1 && node != 0) // leaf
            return 0;

        long long scoreF = 0;
        long long scoreS = 0;
        for(auto next : ad[node])
        {
            if(next == pre)
                continue;
            // get the score
            scoreF += Funct(next, node);
            // not get the score
            scoreS += ScoreSum(next, node);
        }
        return max(scoreF + values[node], scoreS);
    }
    long long ScoreSum(int node, int pre)
    {
        if(sumValue[node] != 0)
            return sumValue[node];

        if(ad[node].size() == 1 && node != 0) // leaf
            return values[node];

        long long sum = 0;
        for(auto next : ad[node])
        {
            if(next == pre)
                continue;
            sum += ScoreSum(next, node);
        }
        sumValue[node] = sum + values[node];
        return sum + values[node];
    }
};

/*
Comment:
First, We build an adjacency list to represent the tree. Then, we use DFS to traverse the tree. In the process of the DFS, each node has two choices. To get the score or not to get the score. If the node chooses not to get the score, it means we can get all of the score in the subtree and not need to traversal the subtree. If the node choose to get the score, we have to DFS traverse the subtree continueously. Then, we get the maximum of these two values and return.
In the process of summarizing subtree values, we can use a vector to memorize the sum for each node to avoid additional calculation.
Time Complexity:Ｏ(n)
Space Complexity:Ｏ(n)
*/

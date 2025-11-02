using PII = pair<int,int>;
class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int h = grid[0].size();
        stack<pair<PII,PII>> s;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < h; j++)
            {
                if(visited[i][j] == true)
                    continue;
                char currentC = grid[i][j];
                s.push({{i,j}, {-1,-1}});
                PII pre = {-1,-1};
                while(!s.empty())
                {
                    auto c = s.top().first;
                    auto pre = s.top().second;
                    visited[c.first][c.second] = true;
                    s.pop();
                    vector<PII> v;
                    v.push_back({c.first, c.second-1});
                    v.push_back({c.first, c.second+1});
                    v.push_back({c.first-1, c.second});
                    v.push_back({c.first+1, c.second});
                    for(auto e : v)
                    {
                        auto x = e.first;
                        auto y = e.second;
                        if(x >= 0 && y >= 0 && x < n && y < h && grid[x][y] == currentC)
                        {
                            bool isPre = pre.first==x && pre.second==y;
                            if(visited[x][y] && !isPre)
                                return true;
                            else if(!visited[x][y])
                                s.push({{x,y},{c.first,c.second}});
                        }
                    }
                }
            }
        }
        return false;
    }
};

/*
Comment:
Use a 2 dimension vector to store the each node which is visited. Then we use a stack which each element stores the current node and its previous node to traverse DFS. If we traverse the next node is the visited node without previous node, it means that there is a cylce in the graph.
Time Complexity: Ｏ(mn)
Space Complexity: Ｏ(mn)
*/

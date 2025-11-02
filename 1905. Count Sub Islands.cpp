class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        vector<vector<bool>> visited(grid2.size(), vector<bool>(grid2[0].size(), false));
        int cnt = 0;
        int m = grid2.size();
        int n = grid2[0].size();
        for(int i = 0; i < grid2.size(); i++)
        {
            for(int j = 0; j < grid2[0].size(); j++)
            {
                if(visited[i][j] == false && grid2[i][j] == 1)
                {
                    queue<pair<int,int>> q;
                    bool isSubIsland = true;
                    q.push({i,j});
                    while(!q.empty())
                    {
                        auto current = q.front();
                        auto x = current.first;
                        auto y = current.second;
                        
                        if(grid1[x][y] == 0)
                        {
                            isSubIsland = false;
                        }
                        int a = x+1;
                        int b = y;
                        if(a >= 0 && b>=0 && a < m && b < n && grid2[a][b] == 1 && visited[a][b] == 0)
                        {
                            q.push({a,b});
                            visited[a][b] = true;
                        }
                        a = x-1;
                        b = y;
                        if(a >= 0 && b>=0 && a < m && b < n && grid2[a][b] == 1 && visited[a][b] == 0)
                        {
                            q.push({a,b});
                            visited[a][b] = true;
                        }
                        a = x;
                        b = y+1;
                        if(a >= 0 && b>=0 && a < m && b < n && grid2[a][b] == 1 && visited[a][b] == 0)
                        {
                            q.push({a,b});
                            visited[a][b] = true;
                        }
                        a = x;
                        b = y-1;
                        if(a >= 0 && b>=0 && a < m && b < n && grid2[a][b] == 1 && visited[a][b] == 0)
                        {
                            q.push({a,b});
                            visited[a][b] = true;
                        }
                        q.pop();
                    }
                    if(isSubIsland)
                        cnt++;
                }
            }
        }
        return cnt;
    }
};

/*
Comment:
We use a 2D vector to keep track of visited cells. Then we get all nodes for each cell in grid2, and we check whether the node is land and not visited. We start a BFS traversal to explore all connected land cells. At the same time, we check whether the corresponding cell in grid1 is also land. Then we can get the count of sub island.
Time Complexity: Ｏ(mn)
Space Complexity: Ｏ(mn)
*/

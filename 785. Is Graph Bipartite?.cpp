class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int N = graph.size();
        vector<int> colors(N, 0);
        queue<int> q;
        for(int i = 0; i < N; i++)
        {
            if(colors[i] == 0)
            {
                q.push(i);
                colors[i] = 1;
                while(!q.empty())
                {
                    int cur = q.front();
                    for(const auto & u : graph[cur])
                    {
                        if(colors[u] == colors[cur])
                            return false;
                        if(colors[u] == 0)
                        {
                            colors[u] = -colors[cur];
                            q.push(u);
                        }
                    }
                    q.pop();
                }
            }
        }
        return true;
    }
};
/*
Algo 2: BFS
Comment:
以vector colors來紀錄每個Node的顏色情況(0:沒顏色 1:紅色 -1:藍色)
掃一遍所有的Node，如果沒顏色則以BFS去traverse。
BFS中，把當下Node塗色，並把相連的Node塗相反的顏色，如果衝突則return false。
時間複雜度：Ｏ(V+E)
空間複雜度：Ｏ(V+E)
*/

/*
Algo 1: DFS
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int N = graph.size();
        colors = vector<int>(N, 0);
        for(int i = 0; i < N; i++)
        {
            if(colors[i] == 0)
            {
                if(!DFS(graph, i, 1))
                    return false;
            }
        }
        return true;
    }
private:
    vector<int> colors;
    bool DFS(vector<vector<int>>& graph, int node, int color)
    {
        colors[node] = color;
        for(auto u: graph[node])
        {
            if(colors[u] == color)
                return false;
            if(colors[u] == 0)
            {
                if(!DFS(graph, u, -color))
                    return false;
            }
        }
        return true;
    }
};
Comment:
以vector colors來紀錄每個Node的顏色情況(0:沒顏色 1:紅色 -1:藍色)
掃一遍所有的Node，如果沒顏色則以DFS去traverse。
DFS中，把當下Node塗色，並把相連的Node塗相反的顏色，如果衝突則return false。
時間複雜度：Ｏ(V+E)
空間複雜度：Ｏ(V+E)
*/

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(N);
        vector<int> colors(N,0);
        queue<int> q;
        for(const auto & d: dislikes)
        {
            graph[d[0] - 1].push_back(d[1] - 1);
            graph[d[1] - 1].push_back(d[0] - 1);
        }
        for(int i = 0; i < N; i++)
        {
            if(colors[i] == 0)
            {
                q.push(i);
                colors[i] = 1;
                while(!q.empty())
                {
                    int cur = q.front();
                    for(auto u: graph[cur])
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
先實作Graph出來。先把第一層大小設為N，第二層以動態新增，空間才不會爆掉。
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
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        graph = vector<vector<int>>(N);
        for(const auto & d: dislikes)
        {
            graph[d[0] - 1].push_back(d[1] - 1);
            graph[d[1] - 1].push_back(d[0] - 1);
        }
        colors = vector<int>(N,0);
        for(int i = 0; i < N; i++)
        {
            if(colors[i] == 0)
            {
                if(!DFS(i,1))
                    return false;
            }
        }
        return true;
    }
private:
    vector<vector<int>> graph;
    vector<int> colors;
    bool DFS(int node, int color)
    {
        colors[node] = color;
        for(auto g: graph[node])
        {
            if(colors[g] == color)
                return false;
            if(colors[g] == 0)
            {
                if(!DFS(g, -color))
                   return false;
            }
        }
        return true;
    }
};
Comment:
先實作Graph出來。先把第一層大小設為N，第二層以動態新增，空間才不會爆掉。
以vector colors來紀錄每個Node的顏色情況(0:沒顏色 1:紅色 -1:藍色)
掃一遍所有的Node，如果沒顏色則以DFS去traverse。
DFS中，把當下Node塗色，並把相連的Node塗相反的顏色，如果衝突則return false。
時間複雜度：Ｏ(V+E)
空間複雜度：Ｏ(V+E)
*/

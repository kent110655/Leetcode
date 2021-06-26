class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        for(auto edge: prerequisites)
        {
            graph[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
        }
        queue<int> q;
        for(int t = 0; t < numCourses; t++)
        {
            if(indegree[t] == 0)
            {
                q.push(t);
            }
        }
        while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            for(auto u : graph[cur])
            {
                indegree[u]--;
                if(indegree[u] == 0)
                {
                    q.push(u);
                }
            }
        }
        for(int k = 0 ; k < numCourses; k++)
        {
            if(indegree[k] != 0)
                return false;
        }
        return true;
    }
    
};

/*
Algo 2:BFS
Comment:
用已知Edge做成graph，再判斷graph是否有cycle。
利用topological sort(BFS)來實作。
用一個indegree來紀錄每個Node的indegree
當一個Node的indegree=0的時候，代表他已經可以進行作業。
以BFS順序traverse整個graph：
先把所有一開始indegree=0的Node放入queue，再進行BFS
每從queue取出一個Node就要更新他相鄰Node的indegree
並且把更新後indegree=0的Node放入queue(代表這些Node也可以作業了)
跑完BFS後再check所有的Node是否indegree皆為0
若皆為0則無Cycle，反之則有Cycle。
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(n)
*/

/*
Algo 1:DFS
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph = vector<vector<int>>(numCourses);
        for(auto edge: prerequisites)
        {
            graph[edge[1]].push_back(edge[0]);
        }
        vector<int> visit(numCourses, 0);
        for(int i = 0; i < numCourses; i++)
        {
            if(visit[i] == 0)
            {
                if(!DFS(i, visit))
                    return false;
            }
        }
        return true;
    }
private:
    vector<vector<int>> graph;
    //cycle:false //no cycle:true
    bool DFS(int cur, vector<int>& visit)
    {
        if(visit[cur] == 1)
            return false;
        if(visit[cur] == 2)
            return  true;
        visit[cur] = 1;
        for(auto child: graph[cur])
        {
            if(!DFS(child, visit))
                return false;
        }
        visit[cur] = 2;
        return true;
    }
};
Comment:
用已知Edge做成graph，再判斷graph是否有cycle。
利用topological sort來實作。
用一個vector紀錄每個Node的狀態(0:還沒跑到 1:經過未完成 2:完成)
利用DFS traverse 整個graph
如果遇到Node＝1：有cycle，return false
如果遇到Node＝2：沒cycle，return true
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(n)
*/

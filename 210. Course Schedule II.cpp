class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        vector<int> ans;
        queue<int> q;
        for(auto u: prerequisites)
        {
            graph[u[1]].push_back(u[0]);
            indegree[u[0]]++;
        }
        for(int i = 0; i < numCourses; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            ans.push_back(cur);
            for(auto u : graph[cur])
            {
                indegree[u]--;
                if(indegree[u] == 0)
                {
                    q.push(u);
                }
            }
        }
        for(int k = 0; k < numCourses; k++)
        {
            if(indegree[k] != 0)    //Cycle!
            {
                return {};
            }
        }
        return ans;
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
queue取出Node的順序即為topological sort。
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(n)
*/

/*
Algo 1:DFS
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        graph = vector<vector<int>>(numCourses);
        visit = vector<int>(numCourses, 0);
        for(auto u: prerequisites)
            graph[u[1]].push_back(u[0]);
        for(int i = 0; i < numCourses; i++)
        {
            if(!DFS(i))
            return {}; 
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
private:
    vector<vector<int>> graph;
    vector<int> visit;
    vector<int> ans;
    bool DFS(int cur)
    {
        if(visit[cur] == 1) //cycle
            return false;
        if(visit[cur] == 2)
            return true;
        visit[cur] = 1;
        for(auto t: graph[cur])
        {
            if(!DFS(t))
                return false;
        }
        visit[cur] = 2;
        ans.push_back(cur);
        return true;
    }
};
Comment:
Topological Sort
用已知Edge做成graph
利用topological sort來實作。
用一個vector紀錄每個Node的狀態(0:還沒跑到 1:經過未完成 2:完成)
利用DFS traverse 整個graph
如果遇到Node＝1：有cycle，return false
如果遇到Node＝2：沒cycle，return true
在一個Node visit finish時紀錄Node (以finish time紀錄順序)
此順序之反序即為所求的topological sort順序。
時間複雜度：Ｏ(V+E)
空間複雜度：Ｏ(V+E)
*/

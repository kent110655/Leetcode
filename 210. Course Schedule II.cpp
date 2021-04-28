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
/*
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

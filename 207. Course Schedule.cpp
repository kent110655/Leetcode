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
/*
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

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int allState = (1<<n)-1;
        queue<pair<int,int>> q;
        unordered_set<int> visited;
        for(int i = 0; i < n; i++)
            q.push({i, 1<<i});
        int dist = 0;
        while(!q.empty())
        {
            int s = q.size();
            while(s--)
            {
                auto cur = q.front();
                q.pop();
                auto node = cur.first;
                auto state = cur.second;
                if(state == allState)
                    return dist;
                int key = node<<16 | state;
                if(visited.count(key))
                    continue;
                visited.insert(key);
                for(auto next : graph[node])
                {
                    int nextState = 1<<next | state;
                    q.push({next, nextState});
                }
            }
            dist++;
        }
        return 0;
    }
};

/*
comment:
To find the shortest path which go through all the nodes, we could use BFS traversal to trace all posiible path. We use a queue to store independent traversal state which is consist of current node and already visited node. The independent state can represent a bitmask which can separately symbolize the current node and visited node. Because all the node can be a start node, we should push all nodes into the queue initially. And we use a hash set to store the visited node. We use a dist value to store the distance of the path, and it should be update when BFS traversal move to next level. Then we can start to traverse the graph. In the BFS traversal, if we found the state of the current node is already visited, it means that part of traversal can be ignored. And if the current node state is as same as the final answer state, it means we find the one of shortest path going through all nodes. If final answer state doesn't appear yet, we should push the next adjacent node into queue to continue to traverse the graph until we find the final answer state.
Time Complexity:Ｏ(n * 2^n)
    - There are at most n * 2^n possible (node, state) combinations.
    - Each state explores up to O(n) neighbors.
    => Overall complexity: O(n^2 * 2^n)

Space Complexity: Ｏ(n*2^n)
    queue: n * 2^n
    hash set: n * 2^n
*/

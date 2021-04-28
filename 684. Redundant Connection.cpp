class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int N = edges.size();
        uset = vector<int>(N+1);
        height = vector<int>(N+1 , 1);
        for(int i = 0; i < N+1; i++)
            uset[i] = i;
        for(auto e: edges)
        {
            if(find(e[0]) == find(e[1]))
            {
                return {e[0], e[1]};
            }
            merge(e[0], e[1]);
        }
        return {};
    }
private:
    vector<int> uset;
    vector<int> height;
    void merge(int a, int b)
    {
        int A = find(a);
        int B = find(b);
        if(height[A] > height[B])
            uset[B] = A;
        else if(height[A] < height[B])
            uset[A] = B;
        else
        {
            uset[B] = A;
            height[A]++;
        }
    }
    int find(int cur)
    {
        if(cur == uset[cur])
            return cur;
        return find(uset[cur]);
    }
};

/*
Comment:
Disjoint Set實作。
利用uset紀錄每個Node的root
利用height紀錄每個root的height
把height小的合併到height大的裡面
若height相同，則隨意合併，且root的height++
依序find edge的兩個點，判斷兩點是否處於同一個set
如果同一個set即代表加了這個edge會有connect，則return此edge。
若不在同一個set，則merge這兩個點使之合併成同一個set。
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(n)
*/

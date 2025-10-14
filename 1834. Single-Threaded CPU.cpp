class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> result;
        for(int i = 0; i < tasks.size(); i++)
            tasks[i].push_back(i);
        sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0];
        });
        auto compare = [](const vector<int>& a, const vector<int>& b){
            if(a[1] == b[1])
                return a[2] > b[2];
            return a[1] > b[1];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> p;
        long long time = 1;
        int t = 0;
        while(t < tasks.size() || !p.empty())
        {
            while(t < tasks.size() && tasks[t][0] <= time)
            {
                p.push(tasks[t]);
                t++;
            }
            if(p.empty())
            {
                time = tasks[t][0];
                continue;
            }
            time += p.top()[1];
            result.push_back(p.top()[2]);
            p.pop();
        }
        return result;
    }
};

/*
Comment:
Because we need to sort the vector and use the index, we push the index into vector element. Then we sort the tasks vector by enqueueTime. To get the next task in the rule, we use a heap which follows the rule. We use the sorted tasks vector sequence to go through the time. At each moment, we can push all the available tasks into heap. We choose a task from the top of heap to record the task index as result order and update the time to next idle time by the processingTime of the task. Finally, the result order would be the answer.
Time Complexity:Ｏ(nlogn), nlogn + nlogn = nlogn
Space Complexity:Ｏ(n)
*/

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto compare = [](pair<pair<int,int>, double> a,  pair<pair<int,int>, double> b)
        {
            return a.second < b.second;
        };
        priority_queue<pair<pair<int, int>, double>, vector<pair<pair<int,int>, double>>, decltype(compare)> p(compare);
        for(auto c : classes)
        {
            p.push({{c[0], c[1]}, getGain({c[0], c[1]})});
        }
        while(extraStudents != 0)
        {
            auto cl = p.top();
            cl.first.first++;
            cl.first.second++;
            cl.second = getGain(cl.first);
            p.pop();
            p.push(cl);
            extraStudents--;
        }
        double sum_ratio = 0;
        while(!p.empty())
        {
            auto pp = p.top();
            p.pop();
            sum_ratio += (double)pp.first.first/(double)pp.first.second;
        }
        return sum_ratio / classes.size();
    }
    static double getGain(const pair<int,int>& cla)
    {
        return (double)(cla.first+1) / (double)(cla.second+1) - (double)cla.first/(double)cla.second;
    }
};
/*
Comment:
In order to add each extra student to the class that gives the maximum gain, we maintain a maximum heap. To increase the efficiency, we design a structure pair<pair<int,int>,double> to store class information and gain. "double" design can reduce the times of the gain calculation, and "pair<int,int>" design can reduce the cost comparing to vector<int> because vector is based on heap and pair is based on stack. Stack is static memory which is lightweight. But the heap is the dynamic memory which is more expensive.
After we design the data structure, we can push all classes into heap. Then, we could get the class that has maximum gain and add a extra student and update the gain at the same time until there is no more extra student. Finally, we can calculate the average ratio from the data in the maximum heap now.
Time Complexity:Ｏ(extraStudents * logn)
Space Complexity:Ｏ(n)
*/

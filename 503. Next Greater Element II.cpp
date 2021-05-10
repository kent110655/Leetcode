class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size(), -1);
        stack<int> s;
        for(int i = 0; i < nums.size(); i++)
        {
            while(!s.empty() && nums[i] > nums[s.top()])
            {
                ans[s.top()] = nums[i];
                s.pop();
            }
            s.push(i);
        }
        if(!s.empty())
        {
            for(int t = 0; t < nums.size(); t++)
            {
                while(nums[t] > nums[s.top()])
                {
                    ans[s.top()] = nums[t];
                    s.pop();
                }
            }
        }
        return ans;
    }
};
/*
Comment:
739類似進階題(多了circular)
利用一個stack，依序把"index"放入stack
如果即將放入的比top的大
則代表目前這個是目前top的下一個大值。
更新ans的值，再把值pop出來
重複操作直到top比當前大時再把當前push進去
做完後如果stack不為空，代表有-1存在
再跑一遍上述操作(不用再push，只需更新ans與pop)
即可以完成circular部分的操作。
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(n)
*/

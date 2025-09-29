class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        int eraseCnt = n-k;
        vector<int> st;
        for(int i = 0; i < n; i++)
        {
            while(!st.empty() && st.back() > nums[i] && eraseCnt > 0)
            {
                st.pop_back();
                eraseCnt--;
            }
            st.push_back(nums[i]);
        }
        vector<int> result(st.begin(), st.begin()+k);
        return result;
    }
};

/*
Comment:
The answer actually is the increasing sub sequence which need to be k length. So we use a monotonic stack to maintain a smallest possible subsequence. In addition, we should ensure that enough elements remain to complete the subsequence of k length, so we keep a erase counter to track how many element can be erase. If the element cannot be erased any more, then we would simply push the element onto stack. The final answer is the first k elements in the stack.
Time Complexity:Ｏ(n)
Space Complexity:Ｏ(n)
*/

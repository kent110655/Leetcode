class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        long long cnt = 0;
        stack<int> st;
        for(int l = 0; l < nums.size(); l++)
        {
            while(!st.empty() && nums[st.top()] < nums[l])
            {
                if(l - st.top() > 1){
                    cnt++;
                }  
                st.pop();
            }
            st.push(l);
        }
        stack<int> st2;
        for(int r = nums.size()-1; r >= 0; r--)
        {
            while(!st2.empty() && nums[st2.top()] < nums[r])
            {
                if(st2.top()-r > 1){
                    cnt++;
                }
                st2.pop();
            }
            st2.push(r);
        }
        return cnt;
    }
};

/*
Comment:
First, find the rule of the bowl. When we choose a left end, the next greater element is the other end of the bowl. There is no element that can be the right end before the next greater element because it would be an element greater than the left end and against the definition of a bowl. So we use a monotonic stack to get the next greater element. If the next greater element is next to left element, it means it would not be a bowl. Then we can get the count of the bowl which right end is greater than left end. Next, we could do the same thing with the reversed sequence. Then we can get the count of the bowl which left end is greater than right end. The count is the answer.
Time Complexity:Ｏ(n)
Space Complexity:Ｏ(n)
*/

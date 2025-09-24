class Solution {
public:
    int scoreOfParentheses(string s) {
        int depth = 0;
        int score = 0;
        bool needCount = false;
        for(auto c : s)
        {
            if(c == '(')
            {
                depth++;
                needCount = true;
            }
            else
            {
                depth--;
                if(needCount)
                    score += pow(2, depth);
                needCount = false;
            }
        }
        return score;
    }
};
/*
Algo2: Depth algo
Comment:
Every score in their depth can be upgrade to the first depth. Per depth it upgrade, the score would add pow of two score. and we set a flag to identify whether the score is appear. When '(' encounter ')', it symbolize that a score appear in their depthest level. So we can upgrade the score to first depth and get the final score.
Time Complexity: Ｏ(n)
Space Complexity: Ｏ(1)
*/

/*
Algo1: Stack
class Solution {
public:
    int scoreOfParentheses(string s) {
        int cur = 0;
        stack<int> st;
        for(auto c : s)
        {
            if(c == ')')
            {
                if(cur == 0)
                    cur = 1;
                else
                    cur *= 2;
                cur += st.top();
                st.pop();
            }
            else
            {
                st.push(cur);
                cur = 0;
            }
        }
        return cur;
    }
};

Comment:
We use a stack to store the previous score. If we encounter a '(', we push the current score into the stack to present the sum of the same depth accumulation scores. If we encounter a ')', it means that we are going to end a depth, and we should caculate the sum in the depth. So we first calculate the current score(1 or double) and add the score in the stack which is in the same depth. When the string s is over, we could calculate the final current score in the last depth. Then the final score is the answer.
Time Complexity:Ｏ(n)
Space Complexity:Ｏ(n)
*/

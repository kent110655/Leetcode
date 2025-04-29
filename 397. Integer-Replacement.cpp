class Solution {
public:
    int integerReplacement(int n) {
        long long num = n;
        int step = 0;
        while(num != 1)
        {
            if(num % 2 == 0)
            {
                num /= 2;
            }
            else
            {
                if(num==3 || num % 4 == 1)
                {
                    num -= 1;
                }
                else
                {
                    num += 1;
                }
            }
            step++;
        }
        return step;
    }
};

/*
algo3：
I use loop instead of recursive in order to save the space in the recursive.
Time Complexity:Ｏ(logn)
Space Complexity:Ｏ(1)


algo1 :
class Solution {
public:
    int integerReplacement(int n) {
        if(n == 1)
        {
            return 0;
        }
        if(n%2 == 0)
        {
            return integerReplacement(n/2) + 1;
        }
        else
        {
            auto add = INT_MAX;
            if(n == INT_MAX)
            {
                add = integerReplacement(n-1) - 1;
            }
            else
            {
                add = integerReplacement(n+1);
            }
            auto div = integerReplacement(n-1);
            return min(add, div) + 1;
        }
    }
};
Comment:
Use recursive algo. Consider the INT_MAX situation. We should find a way to get funct(n+1) answer instead of directly use funct(n+1). Then we found the equal relationship.
[+1] + [/2] = [-1] + [/2] + [+1]
So funct(n+1) = funct(n-1) - 1.
Then we can get the answer with recursive algo. and INT_MAX handler.
Time Complexity:Ｏ(logn)
Space Complexity:Ｏ(logn)

algo 2:
class Solution {
public:
    unordered_map<int, int> hash;
    int integerReplacement(int n) {
        if(n == 1)
        {
            return 0;
        }
        if(hash.count(n) != 0)
        {
            return hash[n];
        }
        if(n%2 == 0)
        {
            hash[n] = integerReplacement(n/2) + 1;
            return hash[n];
        }
        else
        {
            auto add = INT_MAX;
            if(n == INT_MAX)
            {
                add = integerReplacement(n-1) - 1;
            }
            else
            {
                add = integerReplacement(n+1);
            }
            auto div = integerReplacement(n-1);
            hash[n] = min(add, div) + 1;
            return hash[n];
        }
    }
};
Comment: use cache to memorize the sub task result.
Time Complexity:Ｏ(logn)
Space Complexity:Ｏ(logn)
*/

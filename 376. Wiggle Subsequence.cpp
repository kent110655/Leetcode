class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int N = nums.size();
        if(N == 0 || N == 1 || (N == 2 && nums[0] != nums[1]) )
            return N;
        int p = 1;
        int q = 1;
        for(int i = 1; i < N; i++)
        {
            if(nums[i] > nums[i-1])
                p = q + 1;
            else if(nums[i] < nums[i-1])
                q = p + 1;
        }
        return max(p, q);
    }
};
/*
Algo 3:
Comment:
Greedy解。
利用更新兩個變數p,q來記錄
p:當前的點當上升點時的最大長度。
q:當前的點當下降點時的最大長度。
目前 > 前一個 : 當上升點，更新p為前一個點的q+1
目前 < 前一個 : 當下降點，更新q為前一個點的p+1
目前 = 前一個 : 忽略目前這個點，什麼都不做，直接看下一個點
最終比較p,q取大者(比較下降結尾還是上升結尾的值)即為所求。
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(1)
*/

/*
Algo 1:
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int N = nums.size();
        if(N == 0 || N == 1 || (N == 2 && nums[0] != nums[1]) )
            return N;
        vector<int> p(N,1);
        vector<int> q(N,1);
        for(int i = 1; i < N; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(nums[i] > nums[j])
                    p[i] = max(p[i], q[j] + 1);
                else if(nums[i] < nums[j])
                    q[i] = max(q[i], p[j] + 1);
            }
        }
        return max(p[N-1], q[N-1]);
    }
};
Comment:
DP解法。
p[i]:i這個點當上升點時的最大長度
掃一遍 0~i-1 如果nums[j] < nums[i]，則代表j可以當i的前一個下降點
所以比較原本的p[i]與q[i]+1大小取大更新。
q[i]:i這個點當下降點時的最大長度
掃一遍 0~i-1 如果nums[j] > nums[i]，則代表j可以當i的前一個上升點
所以比較原本的q[i]與p[i]+1大小取大更新。
最終比較最後一個點的q,p，取大者即為所求。
時間複雜度：Ｏ(n^2)
空間複雜度：Ｏ(n)
*/

/*
Algo 2:
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int N = nums.size();
        if(N == 0 || N == 1 || (N == 2 && nums[0] != nums[1]) )
            return N;
        int count = 2;
        int diff = nums[1] - nums[0];
        int t = 1;
        while(diff == 0 && t < N)
        {
            diff = nums[t] - nums[t-1];
            t++;
        }
        if(t == N) return 1;
        for(int i = t; i < N; i++)
        {
            if(diff * (nums[i] - nums[i-1]) == 0)
                continue;
            if(diff * (nums[i] - nums[i-1]) < 0)
            {
                count++;
                diff = nums[i] - nums[i-1];
            }
        }
        return count;
    }
};
Comment:
從頭掃一遍，如果趨勢變大變小轉換則count++。
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(1)
*/

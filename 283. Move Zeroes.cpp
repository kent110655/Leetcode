class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int N = nums.size();
        int p = 0;
        for(int i = 0; i < N; i++)
        {
            if(nums[i] != 0)
            {
                nums[p] = nums[i];
                p++;
            }
        }
        for(int j = p; j < N; j++)
            nums[j] = 0;
    }
};
/*
Comment:
把題目想成把非零的數字全部推前
所以以一個pointer p來從頭開始往後更新
遍尋所有值，如果遇到非零則更新到p的位置，p再++繼續更新下一個位置
跑完所有更新以後再把p之後的位置全填零即可
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(1)
*/
/*
Algo 1:
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        bool verify = false;
        for(int i = 0; i < nums.size()-1; i++)
        {
            verify = false;
            for(int j = 0; j < nums.size()-1; j++)
            {
                if(nums[j] == 0)
                {
                    swape(nums, j, j+1);
                    verify = true;
                }
            }
            if(verify == false)
                return;
        }
    }
    void swape(vector<int>& nums, int a, int b)
    {
        int tempt = nums[a];
        nums[a] = nums[b];
        nums[b] = tempt;
    }
};
Comment:
暴力解法
時間複雜度：Ｏ(n^2)
空間複雜度：Ｏ(1)
*/

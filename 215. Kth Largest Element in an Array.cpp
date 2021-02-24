class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        long left=INT_MIN;
        long right=INT_MAX;
        long mid;
        while(left<right)
        {
            mid = right - (right-left)/2;
            if(countNum(nums,mid)>=k)   //找小了
            {
                left=mid;
            }
            else
            {
                right=mid-1;
            }
        }
        return left;
    }
    
    int countNum(vector<int>& nums,int mid)
    {
        int count=0;
        for(auto u:nums)
        {
            if(u>=mid)
            {
                count++;
            }
        }
        return count;
    }
};

/*
algo 1: Sort

    static bool comp(int a,int b){
        return a>b;
    }
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end(),comp);
        return nums[k-1];
    }
    
comment:
1. 直接使用STL的sort把nums由大到小排序
2. 回傳第k個element即為所求
時間複雜度：sort:Ｏ(nlogn) --> Ｏ(nlogn) 
*/

/*
algo 2: priority_queue

    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int> > Pqueue;
        for(int u:nums)
        {
            Pqueue.push(u);
            if(Pqueue.size()>k)
            {
                Pqueue.pop();
            }
        }
        return Pqueue.top();
    }
    
comment:
利用priority_queue排序 (使用Binary Heap製成)。
在push的過程中維護priority_queue的大小為k，多餘的element把他pop掉。
使priority_queue維持在他的top即為第k大的element的狀態。
時間複雜度：
priority_queue操作: push,pop:Ｏ(logn), top:Ｏ(1)
--> Ｏ(nlogk)
空間複雜度：Ｏ(k)
*/

/*
algo 3: Binary search

    int findKthLargest(vector<int>& nums, int k) {
        long left=INT_MIN;
        long right=INT_MAX;
        long mid;
        while(left<right)
        {
            mid = right - (right-left)/2;
            if(countNum(nums,mid)>=k)   //找小了
            {
                left=mid;
            }
            else
            {
                right=mid-1;
            }
        }
        return left;
    }
    
    int countNum(vector<int>& nums,int mid)
    {
        int count=0;
        for(auto u:nums)
        {
            if(u>=mid)
            {
                count++;
            }
        }
        return count;
    }
    
comment:
利用Bianry Search找出第k大的element。
時間複雜度：
[-2^32,2^32]-->至多猜33次即可猜中
每猜一次需花Ｏ(n)去計算猜的值為第幾大（即為countNum）
--> 所以 Ｏ(33n) --> Ｏ(n)
*/

class Solution {
public:
    void swap(vector<int>& nums,int a,int b)
    {
        int tempt;
        tempt=nums[a];
        nums[a]=nums[b];
        nums[b]=tempt;
    }
    void sortColors(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            int minNum=INT_MAX;
            int minSeq;
            for(int e=i;e<nums.size();e++)
            {
                if(nums[e]<minNum)
                {
                    minNum=nums[e];
                    minSeq=e;
                }
            }
            swap(nums,minSeq,i);
        }
    }
};

/*
Insertion Sort: Ｏ(n^2)
    void sortColors(vector<int>& nums) {
        for(int i=1;i<nums.size();i++)
        {
            int key = nums[i];
            int e=i-1;
            while(e>=0 && nums[e]>key)
            {
                nums[e+1]=nums[e];
                e--;
            }
            nums[e+1]=key;
        }
    }
*/

/*
Selection Sort: Ｏ(n^2)
    void swap(vector<int>& nums,int a,int b)
    {
        int tempt;
        tempt=nums[a];
        nums[a]=nums[b];
        nums[b]=tempt;
    }
    void sortColors(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            int minNum=INT_MAX;
            int minSeq;
            for(int e=i;e<nums.size();e++)
            {
                if(nums[e]<minNum)
                {
                    minNum=nums[e];
                    minSeq=e;
                }
            }
            swap(nums,minSeq,i);
        }
    }
*/

/*
Bubble Sort: Ｏ(n^2)
    void swap(vector<int>& nums,int a,int b)
    {
        int tempt;
        tempt=nums[a];
        nums[a]=nums[b];
        nums[b]=tempt;
    }
    
    void sortColors(vector<int>& nums) {
        for(int e=0;e<nums.size();e++)
        {
            for(int i=1;i<nums.size();i++)
            {
                if(nums[i-1]>nums[i])
                    swap(nums,i-1,i);
            }
        }
        
    }
*/

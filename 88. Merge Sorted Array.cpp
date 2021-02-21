class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1;
        int j=n-1;
        int index=m+n-1;
        
        while(i>=0 && j>=0)
        {
            if(nums1[i]>=nums2[j])
            {
                nums1[index--]=nums1[i--];
            }
            else
            {
                nums1[index--]=nums2[j--];
            }
        }
        while(j>=0)
        {
            nums1[index--]=nums2[j--];
        }
    }
};

/*
comment:
設置3個pointer分別在nums1,nums2,nums1填入位置。
因為nums1的element都在頭端，所以從尾端開始填！(重要！)
時間複雜度：O(m+n) --> 遍尋m+n
*/

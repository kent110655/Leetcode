class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        if(nums1.size() > nums2.size())
        {
            // a shorter lenth target is better for binary search
            return findMedianSortedArrays(nums2, nums1);
        }

        int n1 = nums1.size();
        int n2 = nums2.size();
        int k = (n1+n2+1)/2; // Cnt combine need

        int left = -1;
        int right = n1;
        while(left+1 != right)
        {
            int mid = left + (right-left)/2;
            int m1 = mid+1; // Cnt nums1 need
            int m2 = k - m1; // Cnt nums2 need
            // index mid number is smaller than nums2 next number -> need mid
            if(nums1[mid] < nums2[m2])
            {
                left = mid;
            }
            else
            {
                right = mid;
            }
        }
        int m1 = left+1; // Cnt nums1 need
        int m2 = k - m1; // Cnt nums2 need
        int Ck_1 = max(m1<=0 ? INT_MIN : nums1[m1-1], m2<=0 ? INT_MIN : nums2[m2-1]);
        if((n1+n2)%2 == 1)
        {
            return Ck_1;
        }
        int Ck = min(m1 >= n1 ? INT_MAX : nums1[m1], m2 >= n2 ? INT_MAX : nums2[m2]);
        return (Ck_1 + Ck) * 0.5;
    }
};

/*
Comment:
nums1: A0, A1, A2, ... , A(m1-1), ... , An1
nums2: B0, B1, B2, ... , B(m2-1), ... , Bn2
combine: C0, C1, C2, ... , Ck, ... , Cn3
0. Ｃ需要k個數字，nums1需要m1個數字，nums2需要m2個數字 -> k = m1+m2
1. 先找到組成中位數nums1需要m1個，nums2需要m2個 -> 使用binary search找到
2. binary search: 
認定一組vector，對他使用binary search，當決定其中一組vector時，便可確定另一組num2所取的數字，即可判斷下一個數字使否可以更小來決定是否這次是滿足條件。
當選擇nums1需要t個，則代表nums2需要(N-t)個，只需比較 nums1的下一個數字 與 nums2的第(N-t)個 的大小即可得出nums1是否需要取更多更少的數字。
3. 當得知m1, m2後，求得中位數:
Ｃ中第k個數字：C(k-1) = Max(A(m1-1) , B(m2-1))
Ｃ中地k+1個數字：Ck = min(A(m1) , B(m2))
-> 當奇數則return C(k-1)
-> 當偶數則return (C(k-1) + Ck) * 0.5

Time Complexity：Ｏ(log(m+n))
Space Complexity：Ｏ(1)
*/

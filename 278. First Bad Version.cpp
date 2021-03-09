// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(n==1)
            return 1;
        int left=0;
        int right=n;
        int mid;
        while(left<=right)
        {
            mid=left+(right-left)/2;
            if(isBadVersion(mid)==false) //取右
                left=mid+1;
            else    //取左 or target
                right=mid-1;
        }
        return right+1;
    }
};
/*
Binary search
因為target最後必出現在else裡面，所以最後mid = target必存在else裡面
所以right+1即為所求。
*/

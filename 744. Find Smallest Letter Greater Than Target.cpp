class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left=0;
        int right=letters.size()-1;
        int mid;
        while(left<=right)
        {
            mid=left+(right-left)/2;
            if(letters[mid]<=target)
                left=mid+1;
            else
                right=mid-1;
        }
        if(right==letters.size()-1)
            return letters[0];
        else
            return letters[left];
    }
};
/*
Comment:
Binary Search
此種寫法：最後 right < target < left
情況1:target = last element (即right = last element)
return letters[0]
情況2:target > last element (即right = last element)
return letters[0]
情況3:target = 兩個element之間 (即right < target < left)
return letters[left]
情況4:target = 中間element (即right = target < left)
return letters[left]
所以分成兩種情況12,34。
當有重複element的情況：
以判斷式"="在left or right來決定最後取重複element的左端還是右端
EX:上例即為"="在left判斷式，所以"="時left會上移->最後取得最右端重複element。
*/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        int mid;
        int left = matrix[0][0];
        int right = matrix[m-1][n-1];
        while(left < right)
        {
            mid = left + (right - left) / 2;
            int count = findSmallEqual(matrix, mid);
            if(count < k)
                left = mid+1;
            else
                right = mid;
        }
        return left;
    }
    
    int findSmallEqual(vector<vector<int>>& matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int i = m-1;
        int j = 0;
        int cnt = 0;
        while(i >= 0 && j < n)
        {
            if(matrix[i][j] <= target)
            {
                cnt += i+1;
                j++;
            }
            else
                i--;
        }
        return cnt;
    }
};
/*
Algo 4: Binary Search
Comment:
改良Algo 3之中尋找小於等於mid的element個數
從左下角開始搜尋target
當matrix[i][j] > target，上移(i--)
->不作為
當matrix[i][j] <= target，右移(j++)
->此時比matrix[i][j]小的皆符合要尋找的條件(小於等於mid)
->所以cnt更新加上(i+1)
搜尋路徑即為小於等於target的邊界線
如此可以以Ｏ(m+n)求出小於等於mid的element個數
時間複雜度：Ｏ((m+n) * logX) X:最大值與最小值差值
空間複雜度：Ｏ(1)
*/


/*
Algo 3 : Binary Search
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        int mid;
        int left = matrix[0][0];
        int right = matrix[m-1][n-1];
        while(left < right)
        {
            mid = left + (right - left) / 2;
            int count = findSmallEqual(matrix, mid);
            if(count < k)
                left = mid+1;
            else
                right = mid;
        }
        return left;
    }
    
    int findSmallEqual(vector<vector<int>>& matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int cnt = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(target >= matrix[i][j])
                    cnt++;
            }
        }
        return cnt;
    }
};
Comment:
利用Binary Search
matrix[0][0]必為最小值
matrix[m-1][n-1]必為最大值
所以利用Binary Search在兩者範圍之間尋找
先找出小於等於mid的element有幾個(此處用遍尋所有element)
以此判斷target在左還是右進行Binary Search
時間複雜度：Ｏ(mn * logX) X:最大值與最小值差值
空間複雜度：Ｏ(1)
*/

/*
Algo 1:
class Solution {
public:
    struct compare
    {
        bool operator()(vector<int>& a,vector<int>& b)
        {
            return a[0] > b[0];
        }
    };
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        priority_queue<vector<int>, vector<vector<int> >, compare > q;
        auto used = vector<vector<bool> >(m,vector<bool>(n,false));
        used[0][0] = true;
        int count = 0;
        q.push({matrix[0][0], 0, 0});
        while(count < k-1)
        {
            int val = q.top()[0];
            int x = q.top()[1];
            int y = q.top()[2];
            if(x+1 < m && y < n && used[x+1][y] == false)
            {
                q.push({matrix[x+1][y], x+1, y});
                used[x+1][y] = true;
            }
            if(x < m && y+1 < n && used[x][y+1] == false)
            {
                q.push({matrix[x][y+1], x, y+1});
                used[x][y+1] = true;
            }
            q.pop();
            count++;
        }
        return q.top()[0];
    }
};
Comment:
利用matrix[0][0]最小的性質，開始找第k小的element
用used[][]紀錄element是否被用過
利用min heap來判斷相鄰的element誰大誰小
從matrix[0][0]依序把相鄰的element放入heap
pop掉k-1個element以後，top即為所求。
時間複雜度：Ｏ(k*logk)
空間複雜度：Ｏ(k)
*/

/*
Algo 2: Heap
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> q;
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[0].size(); j++)
            {
                q.push(matrix[i][j]);
                if(q.size() > k)
                    q.pop();
            }
        }
        return q.top();
    }
};
Comment:
利用STL的priority_queue來使用max Heap
把所有element放入heap在其中維持heap大小為k(多的pop掉)
最終top即為第k大的element。
時間複雜度：Ｏ(m * n * logmn)
空間複雜度：Ｏ(n)
*/

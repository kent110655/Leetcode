class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> window;  //存index
        vector<int> ans;
        for(int i = 0 ;i < nums.size(); i++)
        {
            //deque中的最大值已經在window範圍之外(i+1-k：window最尾位置)
            if(!window.empty() && i+1-k > window.front())
            {
                window.pop_front();
            }
            //把deque中比當前的element小或等於的element pop掉，再把當前element push進deque
            while(!window.empty() && nums[i] >= nums[window.back()])
            {
                window.pop_back();
            }
            window.push_back(i);
            //當前element至少是第k個，可以開始輸出最大值
            if(i+1 >= k)
            {
                ans.push_back(nums[window.front()]);
            }
        }
        return ans;
    }
};
/*
Algo 4:
Comment:
以Algo 3的想法直接維護一個deque window
deque中存代表element的位置(index)
每次loop至多會因window移動pop掉一個element
所以只需看front的element是否小於window最尾端(i+1-k)
push時把deque中比當前的element小或等於的element pop掉，再把當前element push進deque
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(n)
*/

/*
Algo 3:MonotonicQueue(deque)
class MonotonicQueue
{
public:
    void push(int i)
    {
        while(!d.empty() && i > d.back())
        {
            d.pop_back();
        }
        d.push_back(i);
    }
    void pop()
    {
        d.pop_front();
    }
    int max()
    {
        return d.front();
    }
private:
    deque<int> d;
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MonotonicQueue window;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++)
        {
            window.push(nums[i]);
            if(i >= k-1)
            {
                ans.push_back(window.max());
                if(window.max() == nums[i-k+1])
                    window.pop();
            }
        }
        return ans;
    }
};
Comment:
利用deque實作一個MonotonicQueue
push(i)：把比i小的element皆pop掉，在push進i。
pop():把最前面front()的element掉。
max():回傳最前面的element。
最前面的element一定是最大，因為比push進來的element小的都被pop掉了
在main中需要選擇使用pop()的時機，當要移除的element是最大值的時候才需要pop()
(不然其實在push過程中就已經pop掉了)

push()：
整個跑完總共pop掉n個element，push進n個element
而每個pop跟push皆花Ｏ(1)，所以平均下來是Ｏ(n)
pop()與max()皆為Ｏ(1)
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(n)
*/



/*
Algo 2:BST
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> window;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++)
        {
            window.insert(nums[i]);
            if(i >= k - 1)
            {
                ans.push_back(*window.rbegin());
                window.erase(window.equal_range(nums[i-k+1]).first);
            }
        }
        return ans;
    }
};
Comment:
維護一個BST來隨時取得max element
並且可以新增刪除任意element
multiset是使用BST實作。
rbegin():指向最後一個element的位置(在BST中最後一個element即為max)
equal_range(element):回傳<第一個等於element的位置,最後等於element的位置>
equal_range().first即為即將被排出的element位置
insert、erase、equal_ranger皆為Ｏ(logk)
時間複雜度：Ｏ(nlogn) [Ｏ((n-k+1)*logk)]
空間複雜度：Ｏ(k)
*/


/*
Algo 1:priority_queue
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<int, vector<int>> window;
        priority_queue<int, vector<int>> del;
        queue<int> stream;
        int deleteElement;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++)
        {
            int input = nums[i];
            if(stream.size() == k)  //刪除移出的element
            {
                deleteElement = stream.front();
                stream.pop();
                del.push(deleteElement);
            }
            stream.push(input);
            window.push(input);
            while(!del.empty() && window.top() == del.top())
            {
                window.pop();
                del.pop();
            }
            if(stream.size() == k)
            {
                ans.push_back(window.top());
            }
        }
        return ans;
    }
};
Comment:
維護一個大小k的max heap，以得到每階段的max element
利用一個queue stream來取得下一個要移出的element是什麼
利用兩個priority_queue window與del
以達成"取得最大值"與"刪除任意element"的功能

要push新的element時，直接push進window與stream即可

要刪除移出的element時，從stream pop出可得deleteElement
接著把deleteElement push入del(代表進入待刪清單，會按照從大到小排列)

要取得此時的max element時
先處理待刪清單：
把del中比window大或等於的element pop掉(window,del都要pop)
最後再把window中的max輸出即可

時間複雜度：Ｏ(nlogn)
空間複雜度：Ｏ(n)
*/

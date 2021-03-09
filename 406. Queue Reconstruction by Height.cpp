class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b)
    {
        return a[0]>b[0] || (a[0]==b[0] && a[1]<b[1]);
        //h由大到小 k由大到小
    }
    
    void swap(vector<vector<int> >& v, int a, int b)
    {
        vector<int> tempt=v[b];
        for(int t=b;t>a;--t)
        {
            v[t] = v[t-1];
        }
        v[a]=tempt;
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),cmp);
        
        for(int i=0;i<people.size();i++)
        {
            swap(people,people[i][1],i);
        }
        return people;
    }
};

/*
algo 1:
class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b)
    {
        return a[0]>b[0] || (a[0]==b[0] && a[1]<b[1]);
        //h由大到小 k由大到小
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),cmp);
        vector<vector<int>> que;
        for(auto u:people)
        {
            que.insert(que.begin()+u[1],u);
        }
        return que;
    }
};
Comment:
Greedy algo.
因為之後insert的element不能影響之前insert的element的k，所以要由h大的先開始insert。
以h由大到小 k由大到小的順序sort（以此順序插入element）
insert的時候以element的k來決定要insert在第幾個以符合自身的k。
（後面insert的element不會影響到之前insert的element的k）
*/

/*
algo 2:
class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b)
    {
        return a[0]>b[0] || (a[0]==b[0] && a[1]<b[1]);
        //h由大到小 k由大到小
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),cmp);
        //vector<vector<int>> que;
        for(int i=0;i<people.size();i++)
        {
            auto tempt = people[i];
            people.erase(people.begin()+i);
            people.insert(people.begin()+tempt[1],tempt);
            
        }
        return people;
    }
};

Comment:
利用原vector來做swap，erase element之後再insert，不用用到額外空間。
*/

/*
algo 3:
class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b)
    {
        return a[0]>b[0] || (a[0]==b[0] && a[1]<b[1]);
        //h由大到小 k由大到小
    }
    
    void swap(vector<vector<int> >& v, int a, int b)
    {
        vector<int> tempt=v[b];
        for(int t=b;t>a;--t)
        {
            v[t] = v[t-1];
        }
        v[a]=tempt;
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),cmp);
        
        for(int i=0;i<people.size();i++)
        {
            swap(people,people[i][1],i);
        }
        return people;
    }
};

Comment:
利用純粹的swap在原people vector中做交換
不用額外空間且比較快
時間複雜度：Ｏ(n^2)
*/

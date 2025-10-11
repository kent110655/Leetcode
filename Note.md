



# 🧭 C++ 常見資料結構用法速查表

## 🧩 1. Vector（動態陣列）
```cpp
#include <vector>
using namespace std;

vector<int> v;                // 空 vector
vector<int> v(5, 1);          // 長度 5，初始值 1
v.push_back(10);              // 加到尾端
v.pop_back();                 // 移除尾端
int x = v.back();             // 取最後一個元素
v.size();                     // 元素個數
v.empty();                    // 是否為空
v.clear();                    // 清空
swap(v[0], v[1]);             // 交換兩個元素
````

## 🧱 2. Stack（堆疊，先進後出 LIFO）

```cpp
#include <stack>

stack<int> st;
st.push(1);                   // 壓入
st.pop();                     // 彈出
int x = st.top();             // 取頂端
st.empty();                   // 是否為空
st.size();                    // 元素個數
```

## 🚦 3. Queue（佇列，先進先出 FIFO）

```cpp
#include <queue>

queue<int> q;
q.push(1);                    // 加到尾端
q.pop();                      // 移除前端
int x = q.front();            // 取前端
int y = q.back();             // 取尾端
q.empty();
q.size();
```

## 🔄 4. Deque（雙端佇列）

```cpp
#include <deque>

deque<int> dq;
dq.push_back(1);              // 尾端插入
dq.push_front(2);             // 前端插入
dq.pop_back();                // 尾端刪除
dq.pop_front();               // 前端刪除
int x = dq.front();           
int y = dq.back();            
```

## ⚖️ 5. Priority Queue（優先隊列 / Heap）

```cpp
#include <queue>

// 最大堆（預設）
priority_queue<int> pq;
pq.push(3); pq.push(1); pq.push(5);
int x = pq.top();             // 取最大值 (5)

// 最小堆
priority_queue<int, vector<int>, greater<int>> minpq;
```


### 🧠 5-1. 自訂義結構 + Lambda 比較器（最常見）

#### 範例：根據結構體中的欄位排序

```cpp
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

struct Node {
    int id;
    int cost;
};

// 小的 cost 優先（最小堆）
auto cmp = [](const Node& a, const Node& b) {
    return a.cost > b.cost; // 若 a 比 b 大，a 排在後面
};

priority_queue<Node, vector<Node>, decltype(cmp)> pq(cmp);

int main() {
    pq.push({1, 10});
    pq.push({2, 5});
    pq.push({3, 20});
    cout << pq.top().id << " " << pq.top().cost << endl; // 輸出: 2 5
}
```

🧩 說明：

* `decltype(cmp)` 用來指定 lambda 型別
* 比較函數回傳 `true` 表示 **a 應排在 b 後面**
  （即：a 的優先權低於 b）

---

### 🧱 5-2. 使用結構體 + operator()（傳統做法）

```cpp
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

struct Node {
    int id;
    int cost;
};

struct Compare {
    bool operator()(const Node& a, const Node& b) const {
        return a.cost > b.cost;  // cost 小的優先
    }
};

int main() {
    priority_queue<Node, vector<Node>, Compare> pq;
    pq.push({1, 10});
    pq.push({2, 5});
    pq.push({3, 20});
    cout << pq.top().id << " " << pq.top().cost << endl; // 2 5
}
```

---

### 🧮 5-3. 排序多條件比較（例：cost 小優先，其次 id 小優先）

```cpp
struct Node {
    int id;
    int cost;
};

struct Compare {
    bool operator()(const Node& a, const Node& b) const {
        if (a.cost == b.cost)
            return a.id > b.id; // cost 相同 → id 小的優先
        return a.cost > b.cost;
    }
};
```

---

### 💡 5-4. 以 Pair 為例（排序第二個欄位小者優先）

```cpp
#include <queue>
#include <vector>
using namespace std;

priority_queue<pair<int,int>, vector<pair<int,int>>, 
               function<bool(pair<int,int>, pair<int,int>)>> pq(
    [](auto &a, auto &b) {
        return a.second > b.second; // second 小的優先
    }
);
```

---


## 🌳 6. Set / Multiset（集合，不重複 / 可重複，排序）

```cpp
#include <set>

set<int> s;
s.insert(3); s.insert(1); s.insert(2); // 自動排序
s.erase(1);                 // 移除元素
bool exist = s.count(2);    // 是否存在
auto it = s.find(3);        // 查找
s.size(); s.empty();

// multiset 可存重複
multiset<int> ms;
ms.insert(1); ms.insert(1);
```

## ⚡️ 7. Unordered Set（雜湊集合，不排序，O(1) 查找）

```cpp
#include <unordered_set>

unordered_set<int> us;
us.insert(10);
bool exist = us.count(10);  
us.erase(10);
```

## 🗺️ 8. Map / Multimap（鍵值對，排序）

```cpp
#include <map>

map<int, string> mp;
mp[1] = "one";
mp[2] = "two";
string val = mp[1];
mp.erase(2);
auto it = mp.find(1);        // O(log n)

// multimap 允許相同 key
multimap<int, string> mmp;
mmp.insert({1, "a"});
mmp.insert({1, "b"});
```

## 🔍 9. Unordered Map（雜湊表，O(1) 查找）

```cpp
#include <unordered_map>

unordered_map<string, int> um;
um["apple"] = 3;
um["banana"] = 5;
int x = um["apple"];
um.erase("banana");
```

## ✨ 10. String（字串，底層為 vector<char>）

```cpp
#include <string>

string s = "hello";
s.size();
s.empty();
s.push_back('!');
s.pop_back();
s.substr(0, 3);             // "hel"
s.find("lo");               // 回傳位置
reverse(s.begin(), s.end()); // 反轉
```

## 🔗 11. List（雙向鏈結串列）

```cpp
#include <list>

list<int> lst;
lst.push_back(1);
lst.push_front(2);
lst.pop_back();
lst.pop_front();
```

## 🧠 12. Pair（成對資料結構）

```cpp
#include <utility>   // or <bits/stdc++.h>

pair<int, string> p = {1, "apple"};
int x = p.first;                 // 取第一個元素
string y = p.second;             // 取第二個元素

// 建立 pair
auto p2 = make_pair(2, "banana");

// 比較（依 first，再依 second）
pair<int, int> a = {1, 5};
pair<int, int> b = {1, 7};
bool smaller = a < b;            // true

// 可用於 vector、map 等結構
vector<pair<int, int>> vp;
vp.push_back({3, 4});
vp.emplace_back(5, 6);
```

## ⚙️ 13. 常用演算法（#include <algorithm>）

```cpp
#include <algorithm>
#include <vector>

vector<int> v = {3,1,4,1,5};
sort(v.begin(), v.end());       // 排序
reverse(v.begin(), v.end());    // 反轉
auto it = lower_bound(v.begin(), v.end(), 3); // >=3
auto it2 = upper_bound(v.begin(), v.end(), 3); // >3
max_element(v.begin(), v.end()); // 最大值 iterator
min_element(v.begin(), v.end()); // 最小值 iterator
```

## 📊 時間複雜度對照表

| 資料結構               | 插入                 | 刪除        | 查找       | 是否排序 | 典型用途            |
| ------------------ | ------------------ | --------- | -------- | ---- | --------------- |
| `vector`           | O(1) / O(n)        | O(1)/O(n) | O(1)     | ❌    | 動態陣列、DP         |
| `deque`            | O(1) (首尾)          | O(1)      | O(1)     | ❌    | Sliding Window  |
| `stack`            | O(1)               | O(1)      | O(1)     | ❌    | Monotonic Stack |
| `queue`            | O(1)               | O(1)      | O(1)     | ❌    | BFS             |
| `priority_queue`   | O(log n)           | O(log n)  | O(1)     | ✅    | Heap 應用         |
| `set` / `multiset` | O(log n)           | O(log n)  | O(log n) | ✅    | 排序集合            |
| `unordered_set`    | O(1)               | O(1)      | O(1)     | ❌    | Hash 查重         |
| `map` / `multimap` | O(log n)           | O(log n)  | O(log n) | ✅    | 鍵值排序            |
| `unordered_map`    | O(1)               | O(1)      | O(1)     | ❌    | Hash 查表         |
| `list`             | O(1) (已知 iterator) | O(1)      | O(n)     | ❌    | 插入刪除多           |
| `string`           | O(1)/O(n)          | O(1)/O(n) | O(n)     | ✅    | 字串處理            |


***


# 🧠 Monotonic 結構筆記

| 類型         | Monotonic Stack                                            | Monotonic Deque                                      |
| ---------- | ---------------------------------------------------------- | ---------------------------------------------------- |
| **典型應用場景** | 處理「子序列」問題（不一定連續）                                           | 處理「子陣列 / 視窗」問題（連續）                                   |
| **操作方向**   | 單端（push / pop back）                                        | 雙端（push / pop front & back）                          |
| **維護目標**   | 維持遞增 / 遞減序列，用來找下個更大/更小元素或全域最優子序列                           | 維持當前視窗的 max / min 值                                  |
| **資料狀態**   | 僅儲存必要元素以維持單調性                                              | 儲存索引，確保能移除過期元素                                       |
| **移除條件**   | 新元素與棧頂比較後決定是否 pop                                          | 新元素會從 back 更新單調性，左界移動會從 front 移除過期值                  |
| **使用結構原因** | 僅需一端操作即可完成遞增/遞減判斷                                          | 同時需處理「進入與離開視窗」兩個方向                                   |
| **常見題型**   | Next Greater Element、Most Competitive Subsequence (LC1673) | Sliding Window Maximum、Continuous Subarrays (LC2762) |


***


# Binary Search
判斷使用時機：1. 有sort過 2. O(logn)完成
推薦教學/模板：https://www.youtube.com/watch?v=JuDAqNyTG4g


***


# Tree無向圖
當遇到無向圖input，轉成adjacency list來表示運用


***


# DFS
在path traverse的過程中，可以以global變數紀錄更新所需的資料


***


# Tree Order Traversal
使用DFS

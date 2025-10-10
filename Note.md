

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


# Binary Search
判斷使用時機：1. 有sort過 2. O(logn)完成
推薦教學/模板：https://www.youtube.com/watch?v=JuDAqNyTG4g

# Tree無向圖
當遇到無向圖input，轉成adjacency list來表示運用

# DFS
在path traverse的過程中，可以以global變數紀錄更新所需的資料

# Tree Order Traversal
使用DFS

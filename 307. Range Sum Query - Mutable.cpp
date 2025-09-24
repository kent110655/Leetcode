class NumArray {
public:
    vector<int> nums;
    
    class segTreeNode
    {
        public:
        segTreeNode* left;
        segTreeNode* right;
        int start;
        int end;
        int info;
        segTreeNode(int a, int b)
        {
            start = a;
            end = b;
            info = 0;
            left = NULL;
            right = NULL;
        }
    };

    void init(segTreeNode* node, int start, int end)
    {
        if(start == end)
        {
            node->info = nums[start];
            return;
        }
        int mid = start + (end-start)/2;
        node->left = new segTreeNode(start, mid);
        node->right = new segTreeNode(mid+1, end);
        init(node->left, start, mid);
        init(node->right, mid+1, end);
        node->info = node->left->info + node->right->info;
    }

    void updateSingle(segTreeNode* node, int index, int val)
    {
        if(node->start > index || node->end < index)
            return;
        if(node->start == node->end)
        {
            node->info = val;
            return;
        }
        int mid = node->left->end;
        if(index <= mid)
        {
            updateSingle(node->left, index, val);
        }
        else
        {
            updateSingle(node->right, index, val);
        }
        node->info = node->left->info + node->right->info;
    }

    int queryRange(segTreeNode* node, int left, int right)
    {
        if(node->start >= left && node->end <= right)
        {
            return node->info;
        }
        if(node->start > right || node->end < left)
        {
            return 0;
        }
        return queryRange(node->left, left, right) + queryRange(node->right, left, right);
    }

    segTreeNode* root;

    NumArray(vector<int>& nums) {
        this->nums = nums;
        auto n = nums.size();
        root = new segTreeNode(0, n-1);
        init(root, 0, n-1);
    }
    
    void update(int index, int val) {
        updateSingle(root, index, val);
    }
    
    int sumRange(int left, int right) {
        return queryRange(root, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */


 /*
 Algo2: Segment Tree
 Comment:
 1. Build a segment tree where each node represents the sum of a subarray [start, end].
    - Leaf nodes correspond to individual elements.
    - Internal nodes store the sum of their children.
 2. Update:
    - Traverse down the tree to the leaf corresponding to the updated index.
    - Update the value and propagate the changes back up to maintain correct sums.
 3. Query (sumRange):
    - Recursively check overlapping ranges.
    - If a node’s range lies fully inside the query range, return its sum.
    - If disjoint, return 0.
    - Otherwise, combine results from left and right children.

 Time Complexity: 
    Query:Ｏ(1)
    Update:Ｏ(logn)
 Space Complexity: Ｏ(n)
 */

 /*
 Algo1:
 class NumArray {
public:
    vector<int> n;
    vector<int> cum;
    NumArray(vector<int>& nums) {
        n = nums;
        cum.resize(nums.size());
        cum[0] = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            cum[i] = cum[i-1] + nums[i];
        }
    }
    
    void update(int index, int val) {
        auto div = n[index] - val;
        n[index] = val;
        
        for(int i = index; i < cum.size(); i++)
        {
            cum[i] -= div;
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0)
        {
            return cum[right];
        }
        return cum[right] - cum[left-1];
    }
};

Comment:
 1. Build an accumulation (prefix sum) array to record the cumulative sum at each index.
 2. To get the range sum [left, right], subtract the prefix sum before `left` from the prefix sum at `right`.
 3. For updates, after changing a value in the original array, adjust all subsequent elements in the prefix sum array to maintain correctness.
 Time Complexity: 
    Query:Ｏ(1)
    Update:Ｏ(n)
 Space Complexity: Ｏ(n)
 */

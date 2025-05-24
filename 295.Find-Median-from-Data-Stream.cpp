class MedianFinder {
public:
    multiset<int> small;
    multiset<int> large;
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(small.empty() || num <= *small.rbegin())
        {
            small.insert(num);
        }
        else
        {
            large.insert(num);
        }
        while(abs((int)large.size() - (int)small.size()) > 1)
        {
            if(large.size() > small.size())
            {
                small.insert(*large.begin());
                large.erase(large.begin());
            }
            else
            {
                large.insert(*prev(small.end()));
                small.erase(prev(small.end()));
            }
        }
    }
    
    double findMedian() {
        if(small.size() == large.size())
        {
            return (double)(*small.rbegin() + *large.begin())/2;
        }
        else if(small.size() < large.size())
        {
            return *large.begin();
        }
        else
        {
            return *small.rbegin();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

 /*
 Comment:
Use two sorted multisets to maintain the median.
In the addNum function, the number is inserted into either the `small` or `large` multiset,
depending on its comparison with the largest element in the `small` multiset.
After insertion, the two multisets are rebalanced so that their sizes differ by at most one.
To find the median, simply return the maximum of `small`, the minimum of `large`,
or the average of both if the total number of elements is even.
Time Complexity: Ｏ(logn)
Space Complexity: Ｏ(n)
 */

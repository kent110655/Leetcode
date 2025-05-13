class MyCalendar {
public:
    map<int, int> bookList;
    MyCalendar() {
    }
    
    bool book(int startTime, int endTime) {
        auto it_start_right = bookList.lower_bound(startTime);

        bool left_bound_ok = it_start_right == bookList.begin() || prev(it_start_right)->second <= startTime;
        bool right_bound_ok = it_start_right == bookList.end() || endTime <= it_start_right->first;

        if(left_bound_ok && right_bound_ok)
        {
            bookList.insert({startTime,endTime});
            return true;
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */


 /*
 Comment:
 Use map to store the booking which is legal and insert in. Use map method lower_bound to get the iterator which first element is bigger or equal than target.
 Then, Separately, check the legality of right bound and left bound. If it is legal in two side bound, insert the booking into map.
 Time Complexity:Ｏ(logn) per booking , lower_bound is binary search (red black tree), so it is Ｏ(logn)
 Space Complexity: Ｏ(n)
 */

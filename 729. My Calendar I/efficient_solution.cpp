#include <bits/stdc++.h>

using namespace std;

struct Entry {
    int start, end;
    Entry* next;

    Entry(int _start, int _end, Entry* _next) {
        start = _start;
        end = _end;
        next = _next;
    }
};

class MyCalendar {
   public:
    MyCalendar() {
        Entry* tail = new Entry(INT_MAX, INT_MAX, nullptr);
        head = new Entry(-1, -1, tail);
    }

    bool book(int start, int end) {
        Entry *cur=head, *prev=head;

        while(cur->start<start){
            prev = cur;
            cur = cur->next;
        }

        if(prev->end>start || cur->start<end){
            return false;
        }

        prev->next = new Entry(start, end, cur);
        return true;

    }

   private:
    Entry* head;
};
int main() {
    MyCalendar mc = MyCalendar();
    cout<<mc.book(10,20)<<'\n';
    cout<<mc.book(15,25)<<'\n';
    cout<<mc.book(20,30)<<'\n';
    return 0;
}
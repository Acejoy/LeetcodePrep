#include<bits/stdc++.h>

using namespace std;

class Entry{
    public:
    pair<int, int> range;
    Entry* prev;
    Entry* next;
    
    Entry(int start, int end, Entry* _prev=NULL, Entry* _next=NULL){
        range = make_pair(start,end);
        prev = _prev;
        next = _next;
    }
    
};

class MyCalendar {
public:
    Entry* bookingsList;
    MyCalendar() {
        bookingsList=NULL;
    }
    
    bool book(int start, int end) {
        if(bookingsList==NULL){
            Entry* n = new Entry(start, end);
            bookingsList = n;
            return true;
        } else {
            Entry *curEntry, *reqEntry=NULL, *lastEntry=NULL;
            
            curEntry=bookingsList;
            
            while(curEntry!=NULL){
                if(curEntry->range.first>=end){
                    reqEntry = curEntry;
                    break;
                }                
                lastEntry=curEntry;
                curEntry = curEntry->next;
            }
            
            Entry* newEntry = new Entry(start, end);
            newEntry->next = reqEntry;
                
            if(reqEntry!=NULL){
                   
                //first entry
                if(reqEntry->prev==NULL){                    
                    reqEntry->prev = newEntry;
                    bookingsList = newEntry;
                    return true;                    
                //somewhere in middle
                } else {
                    if(reqEntry->prev->range.second<=start) {
                        reqEntry->prev->next = newEntry;
                        newEntry->prev = reqEntry->prev;
                        reqEntry->prev = newEntry;
                        return true;
                    } else {
                        return false;
                    }
                }
            } else {
                if(lastEntry->range.second<=start){
                    newEntry->prev = lastEntry;
                    lastEntry->next = newEntry;
                    return true;
                } else {
                    return false;
                }
            }
            
            
        }
    }
};


int main(){
    MyCalendar mc = MyCalendar();
    cout<<mc.book(10,20)<<'\n';
    cout<<mc.book(15,25)<<'\n';
    cout<<mc.book(20,30)<<'\n';
    return 0;
}
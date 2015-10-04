#include <iostream>
#include <unordered_map>

using namespace std;

class LRUCache{
struct entry{
    int value;
    int prev;
    int next;
    bool has_prev;
    bool has_next;
};
public:
    int c;
    int first;
    int last;
    unordered_map<int,entry> cache;
    LRUCache(int capacity) {
        c=capacity;
    }
    void insert_new(int key, int value){
        if(cache.size()==0){
            first=key;
            last=key;
            entry e;
            e.value=value;
            e.has_prev=false;
            e.has_next=false;
            cache[key]=e;
        } else{
            entry e;
            e.value=value;
            e.has_prev=false;
            e.has_next=true;
            e.next=first;
            cache[first].has_prev=true;
            cache[first].prev=key;
            first=key;
            cache[key]=e;
        } 
    }
    void delete_old(int key){
        entry e=cache[key];
        if(e.has_next){
            cache[e.next].has_prev=e.has_prev;
            cache[e.next].prev=e.prev;
        }
        if(e.has_prev){
            cache[e.prev].has_next=e.has_next;
            cache[e.prev].next=e.next;
        }
        if(key==first){
            first=e.next;
        }
        if(key==last){
            last=e.prev;
        }
        cache.erase(key);
    }
    int get(int key) {
        if(cache.find(key)==cache.end())
            return -1;
        int val=cache[key].value;
        delete_old(key);
        insert_new(key,val);
        return val;
    }
    
    void set(int key, int value) {
        if(cache.find(key)!=cache.end()){
            delete_old(key);
            insert_new(key,value);
        } else if(cache.size()<c){
            insert_new(key,value);
        } else {
            delete_old(last);
            insert_new(key,value);
        }
    }
};

int main(){
    LRUCache cache(2);
    cout<<"get 1:"<<cache.get(1)<<endl;
    cache.set(1,1);
    cout<<"get 1:"<<cache.get(1)<<endl;
    cache.set(2,2);
    cout<<"get 3:"<<cache.get(3)<<endl;
    cache.set(1,1);
    cache.set(3,3);
    cout<<"get 3:"<<cache.get(3)<<endl;
    cout<<"get 2:"<<cache.get(2)<<endl;


}

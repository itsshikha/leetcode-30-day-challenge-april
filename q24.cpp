/*
  Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

The cache is initialized with a positive capacity.

Follow up:
Could you do both operations in O(1) time complexity?
*/

class LRUCache {
public:
    int capacity;
    list<pair<int, int>> lruList;
    unordered_map<int, list<pair<int,int>>::iterator> hash;
    
    void moveFront(int key, int val){
        lruList.erase(hash[key]);
        lruList.push_front(make_pair(key, val));
        hash[key] = lruList.begin();
    }
    LRUCache(int capacity) {
        this->capacity = capacity;
        
    }
    
    int get(int key) {
        if(hash.find(key)==hash.end())
            return -1;
        int val = (*hash[key]).second;
        moveFront(key,val);
        return (*hash[key]).second;
    }
    
    void put(int key, int value) {
        if(hash.find(key)!=hash.end()){
            moveFront(key,value);
            return;
        }
        else{
            lruList.push_front(make_pair(key,value));
            hash[key] = lruList.begin();
            if(hash.size()>capacity){
                hash.erase(lruList.back().first);
                lruList.pop_back();
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>

using namespace std;

// Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

// get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
// put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

// The cache is initialized with a positive capacity.

// Follow up:
// Could you do both operations in O(1) time complexity?

// Example:

// LRUCache cache = new LRUCache( 2 /* capacity */ );

// cache.put(1, 1);
// cache.put(2, 2);
// cache.get(1);       // returns 1
// cache.put(3, 3);    // evicts key 2
// cache.get(2);       // returns -1 (not found)
// cache.put(4, 4);    // evicts key 1
// cache.get(1);       // returns -1 (not found)
// cache.get(3);       // returns 3
// cache.get(4);       // returns 4

// solution: hashmap, linked-list

class LRUCache {
public:
    list<pair<int, int>> q;
    map<int, list<pair<int, int>>::iterator> m;
    int size;

    LRUCache(int capacity) {
        this->size = capacity;
    }
    
    int get(int key) {
        if (m.find(key) != m.end()) {
            int temp = (*m[key]).second;
            q.erase(m[key]);
            q.push_front(make_pair(key, temp));
            m[key] = q.begin();
            return (*m[key]).second;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            q.erase(m[key]);
            q.push_front(make_pair(key, value));
            m[key] = q.begin();
        } else {
            q.push_front(make_pair(key, value));
            m[key] = q.begin();

            if (m.size() > this->size) {
                m.erase(q.back().first);
                q.pop_back();
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
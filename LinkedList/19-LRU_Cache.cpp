#include<bits/stdc++.h>
using namespace std;

// uses concept of Hashmaps and Doubly Linked Lists.

class LRUCache {
public:
    class node {        // doubly LL
        public:
        int key;
        int val;
        node* next;
        node* prev;
        node(int _key, int _val) {
            key = _key;
            val = _val;
        }
    };

    // initial definitions
    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);

    int cap;
    unordered_map<int, node*> mpp;      // mp -> (key, node_address)

    // initial situation of cache
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(node* newnode) {
        node* temp = head->next;
        newnode->prev = head;
        newnode->next = temp;
        temp->prev = newnode;
        head->next = newnode;
    }

    void deletenode(node* delnode) {
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    
    int get(int key_) {
        if(mpp.find(key_) != mpp.end()) {
            node* resnode = mpp[key_];
            int res = resnode->val;
            mpp.erase(key_);
            deletenode(resnode);
            addnode(resnode);
            m[key_] = head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key_, int value) {
        // if tke key already exist
        if(mpp.find(key_) != mpp.end()) {
            node* existingnode = mpp[key_];
            mpp.erase(key_);
            deletenode(existingnode);
        }

        // if the key doesn't already exist
        if(mpp.size() == cap) {
            // delete the LRU element
            // which is the first left to tail
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }

        addnode(new node(key_, value));
        m[key_] = head->next;
    }
};
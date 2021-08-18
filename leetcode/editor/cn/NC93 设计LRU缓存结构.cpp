//
// Created by Mahone on 2021/8/18.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class DLinkNode {
public:
    int key, value;
    DLinkNode *next;
    DLinkNode *prev;

    DLinkNode() : key(-1), value(-1), next(nullptr), prev(nullptr) {};

    DLinkNode(int _key, int _value) : key(_key), value(_value), next(nullptr), prev(nullptr) {};
};

class Solution {
    unordered_map<int, DLinkNode *> cache;
    DLinkNode *head;
    DLinkNode *tail;
    int size;
    int capacity;

public:
    /**
     * lru design
     * @param operators int整型vector<vector<>> the ops
     * @param k int整型 the k
     * @return int整型vector
     */

    void set(int key, int value) {
        if (cache.count(key)) {
            DLinkNode *tmp = cache[key];
            tmp->value = value;
            moveToHead(tmp);
        } else {
            DLinkNode *node = new DLinkNode(key, value);
            addToHead(node);
            cache[key] = node;
            size++;
            if (size > capacity) {
                DLinkNode *removed = removeTail();
                cache.erase(removed->key);
                delete removed;
                size--;
            }
        }
    }

    int get(int key) {
        if (cache.count(key)) {
            DLinkNode *node = cache[key];
            moveToHead(node);
            return node->value;
        } else {
            return -1;
        }
    }


    vector<int> LRU(vector<vector<int> > &operators, int k) {
        size = 0;
        capacity = k;
        head = new DLinkNode();
        tail = new DLinkNode();
        head->next = tail;
        tail->prev = head;
        vector<int> res;
        for (int i = 0; i < operators.size(); ++i) {
            if (operators[i][0] == 1) {
                set(operators[i][1], operators[i][2]);
            } else if (operators[i][0] == 2) {
                res.emplace_back(get(operators[i][1]));
            }
        }
        return res;
    }

    /**
     * 仅添加使用
     * @param node
     */
    void addToHead(DLinkNode *node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void moveToHead(DLinkNode *node) {
        removeNode(node);
        addToHead(node);
    }

    void removeNode(DLinkNode *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    DLinkNode *removeTail() {
        DLinkNode *removed = tail->prev;
        removeNode(removed);
        return removed;
    }


};


int main() {
    Solution s;
    vector<vector<int>> tmp={{1,1,1},{1,2,2},{1,3,2},{2,1},{1,4,4},{2,2}};
    s.LRU(tmp, 3);
    return 0;
}

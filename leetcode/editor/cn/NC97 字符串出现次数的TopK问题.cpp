//
// Created by Mahone on 2021/8/18.
//
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    /**
     * 小顶堆  left>right
     * 快排  left<right 从小到大
     *
     * return topK string
     * @param strings string字符串vector strings
     * @param k int整型 the k
     * @return string字符串vector<vector<>>
     */
    class my_cmp{
    public:
        bool operator()(const pair<string, int> &p1, const pair<string, int> &p2){
            if(p1.second == p2.second){
                return p1.first < p2.first;
            }else{
                return p1.second > p2.second;
            }
        }
    };
    vector<vector<string> > topKstrings(vector<string>& strings, int k) {
        // write code here
        unordered_map<string,int> map;
        for (int i = 0; i < strings.size(); ++i) {
            map[strings[i]]++;
        }
        priority_queue<pair<string ,int>,vector<pair<string,int>>,my_cmp> pri_que;
        for (auto iter = map.begin(); iter != map.end(); ++iter) {
            pri_que.emplace(*iter);
            if (pri_que.size() > k) {
                pri_que.pop();
            }
        }
        vector<vector<string>> res(k,vector<string>());
        for (int i = k-1; i>=0; i--) {
            res[i].emplace_back(pri_que.top().first);
            res[i].emplace_back(to_string(pri_que.top().second));
            pri_que.pop();
        }
        return res;
    }
};
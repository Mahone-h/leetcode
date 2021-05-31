#include "leetcode/editor/cn/include/headers.h"

using namespace std;

void printpair(pair<int, int> a){
    cout << a.first<<" "<<a.second<< endl;
};

int main() {

    set<int> set;
    if (!set.count(0)){
        cout <<"1111" << endl;
    }
    set.emplace(0);
    if (set.count(0)){
        cout <<"2222" << endl;
    }



    return 0;
}

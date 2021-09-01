


#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;


int main() {


    int N, a1, b1, a2, b2;
    cin >> N;
    cin >> a1 >> b1;
    cin >> a2 >> b2;
    double max = 0;
    int res_a=0, res_b=0;
    for (int i = 0; i <= N; ++i) {  //甲i乙j
        int j = N - i;
        int a = a1 * i + a2 * j;
        int b = b1 * i + b2 * j;
        double tmp = sqrt(a * a + b * b);
        if (tmp > max) {
            max = tmp;
            res_a = i;
            res_b = j;
        } else if (tmp == max) {
            if (res_a > a){
                res_a = i;
                res_b = j;
            }
        }
    }
    cout << res_a<<" "<< res_b;
}
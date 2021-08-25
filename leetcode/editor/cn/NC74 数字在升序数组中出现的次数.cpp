#include <vector>


using namespace std;


class Solution {
public:

    int binarySearch(vector<int> &data, int target) {
        int left = 0, right = data.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (data[mid] >= target) {
                right = mid - 1;
            } else if (data[mid] < target) {
                left = mid + 1;
            }
        }
        return left;

    }

    int GetNumberOfK(vector<int> data, int k) {
        int left = binarySearch(data, k);
        int right = binarySearch(data, k + 1);
        return left == data.size() ? 0 : right - left;
    }
};
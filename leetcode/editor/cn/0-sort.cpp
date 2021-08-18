#include "include/headers.h"

/**
 * 选择排序（Selection Sort） O(n^2)
 */
void selectionSort(vector<int> array){
    int n = array.size();
    int minIndex,tmp;
    for (int i = 0; i < n - 1; ++i) {
        minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        tmp = array[i];
        array[i] = array[minIndex];
        array[minIndex] = tmp;
    }
}

/**
 * 插入排序（Insertion Sort） O(n^2)
 */
void insertionSort(vector<int> array){
    int pre,cur;
    for (int i = 1; i < array.size(); ++i) {
        pre = i - 1;
        cur = array[i];
        while (pre >= 0 && array[pre] > cur) {
            array[pre + 1] = array[pre];
            pre--;
        }
        array[pre + 1] = cur;
    }
}

/**
 * 冒泡排序（Bubble Sort）  O(n^2)
 */

void bubbleSort(vector<int> array){
    int tmp;
    for (int i = 0; i < array.size() - 1; ++i) {
        for (int j = 0; j < array.size() - 1 - i; ++j) {
            if (array[j] > array[j + 1]) {
                tmp = array[j];
                array[j + 1] = array[j];
                array[j] = tmp;
            }
        }
    }
}

/**
 * 快速排序 O(N*LogN)
 */

//以最后一个为pivot
int partition(vector<int> &array, int begin, int end){
    int pivot = end, cur = begin, tmp;
    for(int i = begin; i < end; i++){
        if(array[i] < array[pivot]){
            tmp = array[cur]; array[cur] = array[i]; array[i] = tmp;
            cur++;
        }
    }
    tmp = array[pivot]; array[pivot] = array[cur]; array[cur] = tmp;
    return cur;
}
void quickSort(vector<int> &array, int begin, int end){
    if (begin >= end) return;
    int pivot = partition(array, begin, end);
    quickSort(array, begin,pivot - 1);
    quickSort(array, pivot + 1, end);
}

/**
 * 归并排序 O(N*LogN)
 */
void merge(vector<int> &array, int left, int mid, int right) {
    vector<int> tmp(right - left + 1);

    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right) {
        tmp[k++] = array[i] <= array[j] ? array[i++] : array[j++];
    }
    while (i <= mid) tmp[k++] = array[i++];
    while (j <= right) tmp[k++] = array[j++];
    //重新赋值回去
    for (int p = 0; p < tmp.size(); ++p) {
        array[left + p] = tmp[p];
    }
}
void mergeSort(vector<int> &array, int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = (left + right) >> 1;
    mergeSort(array, left, mid);
    mergeSort(array, mid + 1, right);
    merge(array, left, mid, right);

}

/**
 * 堆排序
 */

void heapify(vector<int> &array, int parent, int length) {
    int left;
    while (true) {
        left = parent * 2 + 1;
        if (left < length && array[left] < array[left + 1]) {
            left++;
        }
        if (left > length || array[parent] >= array[left]) {
            break;
        }
        swap(array[parent], array[left]);
        parent = left;
    }

}

/**
  * i=0为起点 left=2*i+1 right=2*i+2   build 处为length / 2 - 1
  * i=0为起点 left=2*i right=2*i+1     build 处为length / 2 其他位置对应修改
  */
void heapSort(vector<int> &array) {
    if (array.empty()) return;
    int length = array.size();
    //https://www.cnblogs.com/malw/p/10542557.html
    //为什么length/2-1
    for (int i = length / 2 - 1; i >= 0; i--)
        heapify(array, i, length - 1);

    for (int i = length - 1; i > 0; i--) {
        swap(array[0], array[i]);
        heapify(array, 0, i - 1);
    }
}





int main()
{
    vector<int> test = {5, 6, 8, 7, 9, 1, 4, 2, 3, 0};
    mergeSort(test, 0, 10);

}
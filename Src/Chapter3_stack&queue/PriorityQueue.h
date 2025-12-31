#pragma once
#include <algorithm>
const int N = 1e5 + 10;

//数组模拟小根堆，1-based
struct minHeap {
    int a[N];
    int size;

    minHeap() : size(0) {}

    void insert(int x);//插入时，插入堆底，上浮至合适位置
    void pop_min();//弹出时，将堆底元素移到堆顶，下沉至合适位置
    int get_min();//堆顶元素即最小元素
    void up(int i);//上浮
    void down(int i);//下沉
    void remove(int k);//删除当前堆中下标为k的元素：将这个元素用堆底元素替换，尝试上浮和下沉
};

void minHeap::up(int i) {
    while (i > 1 && a[i] < a[i / 2]) {
        std::swap(a[i], a[i / 2]);
        i /= 2;
    }
}

void minHeap::down(int i) {
    while (i * 2 <= size) {
        int t = i * 2;
        if (t + 1 <= size && a[t + 1] < a[t]) t++;//取两子节点中的最小值
        if (a[t] < a[i]) {
            std::swap(a[i], a[t]);
            i = t;
        }
        else break;
    }
}

void minHeap::insert(int x) {
    a[++size] = x;
    up(size);
}

int minHeap::get_min() {
    return a[1];
}

void minHeap::pop_min() {
    a[1] = a[size--];
    down(1);
}

void minHeap::remove(int k) {
    if (k < 1 || k > size) return;

    a[k] = a[size--];
    down(k);          
    up(k);            
}
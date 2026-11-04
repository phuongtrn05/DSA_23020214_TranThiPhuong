#include <iostream>
#include <vector>
using namespace std;

// ======================================================
// Priority Queue (hang doi uu tien) cai dat bang MAX-HEAP
// Phan tu LON NHAT co do uu tien cao nhat, luon nam o goc (vi tri 0)
//
// Heap luu trong vector theo cay nhi phan day du:
//   cha cua i    : (i - 1) / 2
//   con trai cua i : 2*i + 1
//   con phai cua i : 2*i + 2
// Tinh chat max-heap: moi nut >= 2 nut con cua no
// ======================================================
class PriorityQueue {
private:
    vector<int> h;

    // Day nut i len tren cho den khi cha >= nut i: O(log n)
    void siftUp(int i) {
        while (i > 0) {
            int p = (i - 1) / 2;
            if (h[p] >= h[i]) break;     // dung tinh chat heap roi
            swap(h[p], h[i]);
            i = p;
        }
    }

    // Day nut i xuong duoi cho den khi >= ca 2 con: O(log n)
    void siftDown(int i) {
        int n = h.size();
        while (true) {
            int l = 2 * i + 1;
            int r = 2 * i + 2;
            int largest = i;

            if (l < n && h[l] > h[largest]) largest = l;
            if (r < n && h[r] > h[largest]) largest = r;

            if (largest == i) break;     // dung tinh chat heap roi
            swap(h[i], h[largest]);
            i = largest;
        }
    }

public:
    // push: them vao cuoi roi day len - O(log n)
    void push(int x) {
        h.push_back(x);
        siftUp((int)h.size() - 1);
    }

    // pop: bo phan tu uu tien cao nhat (goc) - O(log n)
    // Dua phan tu cuoi len goc, bo phan tu cuoi, roi day goc xuong
    bool pop() {
        if (h.empty()) return false;
        h[0] = h.back();
        h.pop_back();
        if (!h.empty()) siftDown(0);
        return true;
    }

    // top: xem phan tu uu tien cao nhat - O(1)
    bool top(int& x) const {
        if (h.empty()) return false;
        x = h[0];
        return true;
    }

    // isEmpty, size: O(1)
    bool isEmpty() const { return h.empty(); }
    int size() const { return (int)h.size(); }

    // In mang heap (theo thu tu luu trong vector): O(n)
    void display() const {
        for (int x : h) cout << x << " ";
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;
    int a[] = {15, 40, 10, 50, 30, 20, 45};

    for (int x : a) {
        pq.push(x);
        cout << "push(" << x << ") -> heap: ";
        pq.display();
    }

    int x;
    if (pq.top(x)) cout << "Top (uu tien cao nhat) = " << x << endl;

    cout << "Lay lan luot: ";
    while (!pq.isEmpty()) {
        pq.top(x);
        cout << x << " ";
        pq.pop();
    }
    cout << endl;

    cout << "Pop khi rong: " << (pq.pop() ? "OK" : "That bai") << endl;
    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

// Day nut i xuong trong heap gom n phan tu dau cua mang a: O(log n)
void siftDown(vector<int>& a, int n, int i) {
    while (true) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int largest = i;

        if (l < n && a[l] > a[largest]) largest = l;
        if (r < n && a[r] > a[largest]) largest = r;

        if (largest == i) break;
        swap(a[i], a[largest]);
        i = largest;
    }
}

// Buoc 1: bien mang bat ky thanh max-heap
// Duyet tu nut cha cuoi cung (n/2 - 1) nguoc ve goc, moi nut day xuong
// Do phuc tap: O(n)  (khong phai O(n log n), vi da so nut o gan la nen siftDown rat ngan)
void buildMaxHeap(vector<int>& a) {
    int n = a.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        siftDown(a, n, i);
}

// Heap sort
// Moi truong hop (tot nhat, trung binh, xau nhat): O(n log n)
// Bo nho phu: O(1) (sap xep tai cho, khong can mang phu)
// Khong on dinh (khong giu thu tu cua cac so bang nhau)
void heapSort(vector<int>& a) {
    int n = a.size();

    buildMaxHeap(a);                 // Buoc 1: O(n)

    // Buoc 2: n-1 lan, moi lan dua so lon nhat (goc) ve cuoi vung chua sap xep
    for (int end = n - 1; end > 0; end--) {
        swap(a[0], a[end]);          // goc (lon nhat) ra vi tri cuoi
        siftDown(a, end, 0);         // heap con lai gom `end` phan tu, sua lai: O(log n)
    }
}

void display(const vector<int>& a) {
    for (int x : a) cout << x << " ";
    cout << endl;
}

int main() {
    vector<int> a = {38, 27, 43, 3, 9, 82, 10, 3};

    cout << "Truoc khi sap xep: ";
    display(a);

    buildMaxHeap(a);
    cout << "Sau build max-heap: ";
    display(a);

    heapSort(a);
    cout << "Sau khi sap xep   : ";
    display(a);

    vector<int> b = {9, 8, 7, 6, 5, 4};
    heapSort(b);
    cout << "Day sap xep nguoc : ";
    display(b);

    vector<int> c = {1, 2, 3, 4, 5};
    heapSort(c);
    cout << "Day sap xep san   : ";
    display(c);
    return 0;
}

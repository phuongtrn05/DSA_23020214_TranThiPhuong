#include <iostream>
#include <vector>
using namespace std;

// ---------- Merge sort (dung de sap xep, xem MergeSort.cpp) ----------
void merge(vector<int>& a, int l, int m, int r) {
    vector<int> tmp;
    int i = l, j = m + 1;
    while (i <= m && j <= r) {
        if (a[i] <= a[j]) tmp.push_back(a[i++]);
        else              tmp.push_back(a[j++]);
    }
    while (i <= m) tmp.push_back(a[i++]);
    while (j <= r) tmp.push_back(a[j++]);
    for (int k = 0; k < (int)tmp.size(); k++)
        a[l + k] = tmp[k];
}

void mergeSort(vector<int>& a, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    merge(a, l, m, r);
}

// ---------- Cach 1: Sap xep roi lay phan tu giua ----------
// Do phuc tap: O(n log n) thoi gian, O(n) bo nho phu
// Dieu kien: n le (n >= 1)
int median(vector<int> a) {          // truyen BAN SAO de khong lam thay doi day goc
    int n = a.size();
    mergeSort(a, 0, n - 1);          // O(n log n)
    return a[n / 2];                 // O(1): n le thi n/2 la chi so phan tu giua
}

// ---------- Cach 2: Quickselect - khong can sap xep het ----------
// Chi tim phan tu thu k (tinh tu 0) theo thu tu tang dan
// Do phuc tap: trung binh O(n), xau nhat O(n^2)
int partition(vector<int>& a, int l, int r) {
    int mid = l + (r - l) / 2;
    swap(a[mid], a[r]);              // dua pivot (phan tu giua) ve cuoi
    int pivot = a[r];
    int i = l;
    for (int j = l; j < r; j++)
        if (a[j] < pivot)
            swap(a[i++], a[j]);
    swap(a[i], a[r]);                // dua pivot ve dung vi tri
    return i;
}

int quickSelect(vector<int>& a, int l, int r, int k) {
    while (true) {
        if (l == r) return a[l];
        int p = partition(a, l, r);
        if (p == k)      return a[p];
        else if (p > k)  r = p - 1;  // phan tu can tim nam ben trai pivot
        else             l = p + 1;  // phan tu can tim nam ben phai pivot
    }
}

int medianQuickSelect(vector<int> a) {
    int n = a.size();
    return quickSelect(a, 0, n - 1, n / 2);
}

int main() {
    vector<int> a = {7, 1, 9, 3, 5};   // sap xep: 1 3 5 7 9 -> trung vi = 5

    cout << "Day: ";
    for (int x : a) cout << x << " ";

    cout << "\nTrung vi (sap xep)    : " << median(a) << endl;
    cout << "Trung vi (quickselect): " << medianQuickSelect(a) << endl;

    vector<int> b = {42};
    cout << "Day 1 phan tu {42}    : " << median(b) << endl;

    vector<int> c = {5, 5, 1, 9, 5, 2, 8};  // sap xep: 1 2 5 5 5 8 9 -> trung vi = 5
    cout << "Day co so trung nhau  : " << median(c) << endl;
    return 0;
}

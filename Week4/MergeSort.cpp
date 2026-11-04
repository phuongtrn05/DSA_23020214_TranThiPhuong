#include <iostream>
#include <vector>
using namespace std;

// Tron 2 nua DA SAP XEP a[l..m] va a[m+1..r] thanh 1 day sap xep
// Do phuc tap: O(n) voi n = r - l + 1, bo nho phu O(n)
void merge(vector<int>& a, int l, int m, int r) {
    vector<int> tmp;             // mang tam chua ket qua tron
    int i = l;                   // con tro nua trai
    int j = m + 1;               // con tro nua phai

    while (i <= m && j <= r) {
        if (a[i] <= a[j])        // dung <= de thuat toan on dinh (stable)
            tmp.push_back(a[i++]);
        else
            tmp.push_back(a[j++]);
    }
    while (i <= m) tmp.push_back(a[i++]);   // nua trai con du
    while (j <= r) tmp.push_back(a[j++]);   // nua phai con du

    for (int k = 0; k < (int)tmp.size(); k++)   // chep ket qua tro lai
        a[l + k] = tmp[k];
}

// Merge sort
// Moi truong hop (tot nhat, trung binh, xau nhat): O(n log n)
// Bo nho phu: O(n)
void mergeSort(vector<int>& a, int l, int r) {
    if (l >= r) return;          // 0 hoac 1 phan tu: da sap xep
    int m = l + (r - l) / 2;     // diem chia doi
    mergeSort(a, l, m);          // sap xep nua trai
    mergeSort(a, m + 1, r);      // sap xep nua phai
    merge(a, l, m, r);           // tron 2 nua lai
}

void display(const vector<int>& a) {
    for (int x : a) cout << x << " ";
    cout << endl;
}

int main() {
    vector<int> a = {38, 27, 43, 3, 9, 82, 10, 3};

    cout << "Truoc khi sap xep: ";
    display(a);

    mergeSort(a, 0, (int)a.size() - 1);

    cout << "Sau khi sap xep  : ";
    display(a);

    vector<int> b = {9, 8, 7, 6, 5, 4};
    mergeSort(b, 0, (int)b.size() - 1);
    cout << "Day sap xep nguoc : ";
    display(b);
    return 0;
}

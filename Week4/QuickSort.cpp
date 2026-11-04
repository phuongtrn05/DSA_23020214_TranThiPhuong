#include <iostream>
#include <vector>
using namespace std;

// Phan hoach (Lomuto): chon pivot, dua phan tu < pivot sang trai, >= pivot sang phai
// Tra ve vi tri cuoi cung cua pivot. Do phuc tap: O(n) cho doan can phan hoach
int partition(vector<int>& a, int l, int r) {
    int mid = l + (r - l) / 2;
    swap(a[mid], a[r]);          // chon pivot la phan tu GIUA, dua ve cuoi
                                 // (tranh truong hop xau nhat khi day da sap xep san)
    int pivot = a[r];
    int i = l;                   // i = vi tri se dat phan tu nho hon pivot tiep theo

    for (int j = l; j < r; j++) {
        if (a[j] < pivot) {
            swap(a[i], a[j]);
            i++;
        }
    }
    swap(a[i], a[r]);            // dat pivot vao dung vi tri cua no
    return i;
}

// Quick sort
// Tot nhat / Trung binh: O(n log n)
// Xau nhat: O(n^2)  (pivot luon la phan tu nho nhat/lon nhat)
// Bo nho phu: O(log n) trung binh (do ngan xep de quy)
void quickSort(vector<int>& a, int l, int r) {
    if (l >= r) return;          // doan co 0 hoac 1 phan tu: da sap xep
    int p = partition(a, l, r);
    quickSort(a, l, p - 1);      // sap xep ben trai pivot
    quickSort(a, p + 1, r);      // sap xep ben phai pivot
}

void display(const vector<int>& a) {
    for (int x : a) cout << x << " ";
    cout << endl;
}

int main() {
    vector<int> a = {38, 27, 43, 3, 9, 82, 10, 3};

    cout << "Truoc khi sap xep: ";
    display(a);

    quickSort(a, 0, (int)a.size() - 1);

    cout << "Sau khi sap xep  : ";
    display(a);

    vector<int> b = {1, 2, 3, 4, 5, 6};   // da sap xep san
    quickSort(b, 0, (int)b.size() - 1);
    cout << "Day da sap xep san: ";
    display(b);

    vector<int> c = {9, 8, 7, 6, 5, 4};   // sap xep nguoc
    quickSort(c, 0, (int)c.size() - 1);
    cout << "Day sap xep nguoc : ";
    display(c);
    return 0;
}

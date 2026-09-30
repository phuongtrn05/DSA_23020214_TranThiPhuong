#include <iostream>
using namespace std;

void xoa(int a[], int &n, int k) {
    if (k < 1 || k > n) {
        cout << "Vi tri k khong hop le.";
        return;
    }

    // Chuyen k ve chi so mang
    k--;

    for (int i = k; i < n - 1; i++) {
        a[i] = a[i + 1];
    }

    n--;
}

int main() {
    int n;
    int a[1000];

    cout << "Nhap n: ";
    cin >> n;

    cout << "Nhap " << n << " phan tu: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int k;
    cout << "Nhap vi tri k can xoa: ";
    cin >> k;

    xoa(a, n, k);

    cout << "Day sau khi xoa: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}
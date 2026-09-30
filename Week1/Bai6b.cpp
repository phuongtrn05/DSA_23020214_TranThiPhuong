#include <iostream>
using namespace std;

void chen(int a[], int &n, int y, int m) {
    if (m < 1 || m > n + 1) {
        cout << "Vi tri m khong hop le.";
        return;
    }

    // Chuyen m ve chi so mang
    m--;

    for (int i = n; i > m; i--) {
        a[i] = a[i - 1];
    }

    a[m] = y;
    n++;
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

    int y, m;

    cout << "Nhap y: ";
    cin >> y;

    cout << "Nhap vi tri m can chen: ";
    cin >> m;

    chen(a, n, y, m);

    cout << "Day sau khi chen: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}
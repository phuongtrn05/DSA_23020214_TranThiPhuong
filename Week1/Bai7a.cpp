#include <iostream>
using namespace std;

int tinhTong(int a[][100], int n, int m) {
    int sum = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sum += a[i][j];
        }
    }

    return sum;
}

int main() {
    int n, m;
    int a[100][100];

    cout << "Nhap so dong n: ";
    cin >> n;

    cout << "Nhap so cot m: ";
    cin >> m;

    cout << "Nhap ma tran:" << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int sum = tinhTong(a, n, m);

    cout << "Tong cac phan tu = " << sum;

    return 0;
}
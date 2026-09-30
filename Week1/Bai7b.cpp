#include <iostream>
using namespace std;

void xoaDong(int a[][100], int &n, int m, int i) {
    if (i < 1 || i > n) {
        cout << "Vi tri dong khong hop le.";
        return;
    }

    // Chuyen tu dong thu i (tinh tu 1)
    // sang chi so mang (tinh tu 0)
    i--;

    for (int row = i; row < n - 1; row++) {
        for (int col = 0; col < m; col++) {
            a[row][col] = a[row + 1][col];
        }
    }

    n--;
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

    int i;
    cout << "Nhap dong can xoa: ";
    cin >> i;

    xoaDong(a, n, m, i);

    cout << "Ma tran sau khi xoa:" << endl;

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            cout << a[row][col] << " ";
        }
        cout << endl;
    }

    return 0;
}
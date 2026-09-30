#include <iostream>
using namespace std;

int main() {
    int n;
    int a[1000];

    cout << "Nhap n: ";
    cin >> n;

    cout << "Nhap " << n << " phan tu: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += a[i];
    }

    cout << "Tong = " << sum;

    return 0;
}
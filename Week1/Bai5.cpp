#include <iostream>
using namespace std;

int main() {
    int n;
    double a[1000];

    cout << "Nhap n: ";
    cin >> n;

    cout << "Nhap " << n << " phan tu: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    double sum = 0;

    for (int i = 0; i < n; i++) {
        sum += a[i];
    }

    double avg = sum / n;

    cout << "Gia tri trung binh = " << avg << endl;

    cout << "Cac gia tri >= gia tri trung binh: ";

    for (int i = 0; i < n; i++) {
        if (a[i] >= avg) {
            cout << a[i] << " ";
        }
    }

    return 0;
}
#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Nhap n: ";
    cin >> n;

    if (n < 0) {
        cout << "Khong tinh duoc giai thua cua so am.";
    }
    else {
        long long gt = 1;

        for (int i = 1; i <= n; i++) {
            gt *= i;
        }

        cout << n << "! = " << gt;
    }

    return 0;
}
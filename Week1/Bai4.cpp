#include <iostream>
using namespace std;

int UCLN(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;

    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

void rutGon(int a, int b) {
    if (b == 0) {
        cout << "Mau so phai khac 0.";
        return;
    }

    int u = UCLN(a, b);

    a /= u;
    b /= u;

    // Đưa dấu âm lên tử
    if (b < 0) {
        a = -a;
        b = -b;
    }

    cout << "Phan so rut gon: " << a << "/" << b;
}

int main() {
    int a, b;

    cout << "Nhap a va b: ";
    cin >> a >> b;

    rutGon(a, b);

    return 0;
}
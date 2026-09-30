
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> a = {10, 20, 30, 40, 50};

    // Them dau
    a.insert(a.begin(), 5);

    // Them tai vi tri i = 3
    a.insert(a.begin() + 3, 25);

    // Them cuoi
    a.push_back(60);

    // Xoa dau
    a.erase(a.begin());

    // Xoa tai vi tri k = 2
    a.erase(a.begin() + 2);

    // Xoa cuoi
    a.pop_back();

    // Duyet xuoi
    cout << "Duyet xuoi: ";
    for (int x : a)
        cout << x << " ";

    // Duyet nguoc
    cout << "\nDuyet nguoc: ";
    for (auto it = a.rbegin(); it != a.rend(); ++it)
        cout << *it << " ";

    return 0;
}
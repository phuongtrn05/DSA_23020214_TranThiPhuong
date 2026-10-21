#include <iostream>
#include <vector>
using namespace std;

// ===== Stack (LIFO) cai dat bang List (vector) =====
// Dinh stack = cuoi vector -> push/pop thao tac o cuoi
class StackList {
private:
    vector<int> a;
public:
    // push: push_back - O(1) khau hao (O(n) o lan vector phai cap phat lai)
    void push(int x) { a.push_back(x); }

    // pop: pop_back - O(1). Tra ve false neu stack rong
    bool pop() {
        if (a.empty()) return false;
        a.pop_back();
        return true;
    }

    // top: doc phan tu cuoi - O(1)
    bool top(int& x) const {
        if (a.empty()) return false;
        x = a.back();
        return true;
    }

    // isEmpty / size - O(1)
    bool isEmpty() const { return a.empty(); }
    int size() const { return (int)a.size(); }

    // Duyet tu dinh den day (duyet nguoc vector) - O(n)
    void display() const {
        for (auto it = a.rbegin(); it != a.rend(); ++it)
            cout << *it << " ";
        cout << endl;
    }
};

int main() {
    StackList s;
    s.push(10); s.push(20); s.push(30); s.push(40);

    cout << "Stack (dinh -> day): ";
    s.display();

    int x;
    if (s.top(x)) cout << "Top = " << x << endl;

    s.pop();
    s.pop();
    cout << "Sau 2 lan pop: ";
    s.display();
    cout << "Size = " << s.size() << endl;

    s.pop(); s.pop();
    cout << "Stack rong? " << (s.isEmpty() ? "Co" : "Khong") << endl;
    cout << "Pop khi rong: " << (s.pop() ? "OK" : "That bai") << endl;
    return 0;
}

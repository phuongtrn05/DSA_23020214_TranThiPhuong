#include <iostream>
#include <vector>
using namespace std;

// ===== Queue (FIFO) cai dat bang List (vector) =====
// enqueue = push_back, dequeue = erase(begin)
class QueueList {
private:
    vector<int> a;
public:
    // enqueue: push_back - O(1) khau hao
    void enqueue(int x) { a.push_back(x); }

    // dequeue: erase(begin) - O(n) vi phai dich toan bo phan tu con lai sang trai
    bool dequeue() {
        if (a.empty()) return false;
        a.erase(a.begin());
        return true;
    }

    // front: doc phan tu dau - O(1)
    bool front(int& x) const {
        if (a.empty()) return false;
        x = a.front();
        return true;
    }

    // isEmpty / size - O(1)
    bool isEmpty() const { return a.empty(); }
    int size() const { return (int)a.size(); }

    // Duyet tu dau den cuoi - O(n)
    void display() const {
        for (int x : a) cout << x << " ";
        cout << endl;
    }
};

int main() {
    QueueList q;
    q.enqueue(10); q.enqueue(20); q.enqueue(30); q.enqueue(40);

    cout << "Queue (dau -> cuoi): ";
    q.display();

    int x;
    if (q.front(x)) cout << "Front = " << x << endl;

    q.dequeue();
    q.dequeue();
    cout << "Sau 2 lan dequeue: ";
    q.display();
    cout << "Size = " << q.size() << endl;

    q.dequeue(); q.dequeue();
    cout << "Queue rong? " << (q.isEmpty() ? "Co" : "Khong") << endl;
    cout << "Dequeue khi rong: " << (q.dequeue() ? "OK" : "That bai") << endl;
    return 0;
}

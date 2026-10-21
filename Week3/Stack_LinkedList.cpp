
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = tail = nullptr;
    }

    // Them dau: O(1)
    void insertHead(int x) {
        Node* p = new Node(x);
        p->next = head;
        head = p;

        if (tail == nullptr)
            tail = p;
    }

    // Them cuoi: O(1)
    void insertTail(int x) {
        Node* p = new Node(x);

        if (head == nullptr) {
            head = tail = p;
            return;
        }

        tail->next = p;
        tail = p;
    }

    // Them tai vi tri i: O(n)
    void insertAt(int i, int x) {
        if (i < 0) return;

        if (i == 0) {
            insertHead(x);
            return;
        }

        Node* p = head;

        for (int j = 0; p != nullptr && j < i - 1; j++)
            p = p->next;

        if (p == nullptr) return;

        Node* q = new Node(x);
        q->next = p->next;
        p->next = q;

        if (q->next == nullptr)
            tail = q;
    }

    // Xoa dau: O(1)
    void deleteHead() {
        if (head == nullptr) return;

        Node* p = head;
        head = head->next;
        delete p;

        if (head == nullptr)
            tail = nullptr;
    }

    // Xoa tai vi tri k: O(n)
    void deleteAt(int k) {
        if (k < 0 || head == nullptr) return;

        if (k == 0) {
            deleteHead();
            return;
        }

        Node* p = head;

        for (int j = 0; p != nullptr && j < k - 1; j++)
            p = p->next;

        if (p == nullptr || p->next == nullptr)
            return;

        Node* q = p->next;
        p->next = q->next;

        if (q == tail)
            tail = p;

        delete q;
    }

    // Xoa cuoi: O(n)
    void deleteTail() {
        if (head == nullptr) return;

        if (head == tail) {
            delete head;
            head = tail = nullptr;
            return;
        }

        Node* p = head;

        while (p->next != tail)
            p = p->next;

        delete tail;
        tail = p;
        tail->next = nullptr;
    }

    // Duyet xuoi: O(n)
    void displayForward() {
        Node* p = head;

        while (p != nullptr) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }

    // Duyet nguoc bang de quy: O(n)
    void displayBackward(Node* p) {
        if (p == nullptr) return;

        displayBackward(p->next);
        cout << p->data << " ";
    }

    void displayReverse() {
        displayBackward(head);
        cout << endl;
    }

    Node* getHead() {
        return head;
    }

    ~LinkedList() {
        while (head != nullptr)
            deleteHead();
    }
};

// ======================================================
// Stack (LIFO) cai dat bang LinkedList o tren
// Dinh stack = head -> push/pop deu thao tac o dau: O(1)
// ======================================================
class Stack {
private:
    LinkedList l;
    int n;

public:
    Stack() { n = 0; }

    // Vo hieu hoa copy de tranh shallow copy (2 stack cung tro vao 1 danh sach)
    Stack(const Stack&) = delete;
    Stack& operator=(const Stack&) = delete;

    // push: insertHead - O(1)
    void push(int x) {
        l.insertHead(x);
        n++;
    }

    // pop: deleteHead - O(1). Tra ve false neu stack rong
    bool pop() {
        if (isEmpty()) return false;
        l.deleteHead();
        n--;
        return true;
    }

    // top: doc dinh stack - O(1). Tra ve false neu stack rong
    bool top(int& x) {
        if (isEmpty()) return false;
        x = l.getHead()->data;
        return true;
    }

    // isEmpty, size: O(1)
    bool isEmpty() { return n == 0; }
    int size() { return n; }

    // Duyet tu dinh den day: O(n)
    void display() {
        l.displayForward();
    }
};

int main() {
    Stack s;
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

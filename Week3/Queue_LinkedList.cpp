
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
// Queue (FIFO) cai dat bang LinkedList o tren
// enqueue = insertTail, dequeue = deleteHead -> deu O(1)
// ======================================================
class Queue {
private:
    LinkedList l;
    int n;

public:
    Queue() { n = 0; }

    // Vo hieu hoa copy de tranh shallow copy
    Queue(const Queue&) = delete;
    Queue& operator=(const Queue&) = delete;

    // enqueue: insertTail - O(1) (nho con tro tail)
    void enqueue(int x) {
        l.insertTail(x);
        n++;
    }

    // dequeue: deleteHead - O(1). Tra ve false neu queue rong
    bool dequeue() {
        if (isEmpty()) return false;
        l.deleteHead();
        n--;
        return true;
    }

    // front: doc phan tu dau hang doi - O(1)
    bool front(int& x) {
        if (isEmpty()) return false;
        x = l.getHead()->data;
        return true;
    }

    // isEmpty, size: O(1)
    bool isEmpty() { return n == 0; }
    int size() { return n; }

    // Duyet tu dau den cuoi hang doi: O(n)
    void display() {
        l.displayForward();
    }
};

int main() {
    Queue q;
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

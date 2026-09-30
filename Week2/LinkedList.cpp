
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

int main() {
    LinkedList l;

    l.insertTail(10);
    l.insertTail(20);
    l.insertTail(30);
    l.insertTail(40);

    l.insertHead(5);
    l.insertAt(2, 15);

    cout << "Danh sach: ";
    l.displayForward();

    l.deleteHead();
    l.deleteAt(2);
    l.deleteTail();

    cout << "Sau khi xoa: ";
    l.displayForward();

    cout << "Duyet nguoc: ";
    l.displayReverse();

    return 0;
}
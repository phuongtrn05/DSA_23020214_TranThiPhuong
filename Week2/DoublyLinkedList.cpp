#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int x) {
        data = x;
        prev = next = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = tail = nullptr;
    }

    // Vô hiệu hóa copy constructor & assignment operator để tránh shallow copy
    DoublyLinkedList(const DoublyLinkedList&) = delete;
    DoublyLinkedList& operator=(const DoublyLinkedList&) = delete;

    // Them dau: O(1)
    void insertHead(int x) {
        Node* p = new Node(x);

        if (head == nullptr) {
            head = tail = p;
            return;
        }

        p->next = head;
        head->prev = p;
        head = p;
    }

    // Them cuoi: O(1)
    void insertTail(int x) {
        Node* p = new Node(x);

        if (tail == nullptr) {
            head = tail = p;
            return;
        }

        tail->next = p;
        p->prev = tail;
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
        int j = 0;

        for (; p != nullptr && j < i; j++)
            p = p->next;

        // Nếu p == nullptr và j == i, tức là chèn vào vị trí ngay sau phần tử cuối (tail)
        if (p == nullptr) {
            if (j == i) {
                insertTail(x);
            }
            // Nếu j < i tức là vi tri i vượt quá độ dài danh sách -> bỏ qua
            return;
        }

        Node* q = new Node(x);

        q->prev = p->prev;
        q->next = p;

        p->prev->next = q;
        p->prev = q;
    }

    // Xoa dau: O(1)
    void deleteHead() {
        if (head == nullptr) return;

        Node* p = head;
        head = head->next;

        if (head != nullptr)
            head->prev = nullptr;
        else
            tail = nullptr;

        delete p;
    }

    // Xoa cuoi: O(1)
    void deleteTail() {
        if (tail == nullptr) return;

        Node* p = tail;
        tail = tail->prev;

        if (tail != nullptr)
            tail->next = nullptr;
        else
            head = nullptr;

        delete p;
    }

    // Xoa tai vi tri k: O(n)
    void deleteAt(int k) {
        if (k < 0 || head == nullptr) return;

        Node* p = head;

        for (int j = 0; p != nullptr && j < k; j++)
            p = p->next;

        if (p == nullptr) return;

        if (p == head) {
            deleteHead();
            return;
        }

        if (p == tail) {
            deleteTail();
            return;
        }

        p->prev->next = p->next;
        p->next->prev = p->prev;

        delete p;
    }

    // Duyet xuoi: O(n)
    void displayForward() const {
        Node* p = head;

        while (p != nullptr) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }

    // Duyet nguoc: O(n)
    void displayBackward() const {
        Node* p = tail;

        while (p != nullptr) {
            cout << p->data << " ";
            p = p->prev;
        }
        cout << endl;
    }

    ~DoublyLinkedList() {
        while (head != nullptr)
            deleteHead();
    }
};

int main() {
    DoublyLinkedList l;

    l.insertTail(10);
    l.insertTail(20);
    l.insertTail(30);
    l.insertTail(40);

    l.insertHead(5);
    l.insertAt(2, 15);

    cout << "Duyet xuoi: ";
    l.displayForward();

    cout << "Duyet nguoc: ";
    l.displayBackward();

    l.deleteHead();
    l.deleteAt(2);
    l.deleteTail();

    cout << "Sau khi xoa: ";
    l.displayForward();

    return 0;
}
#include <iostream>
#include <string>
using namespace std;

// ======================================================
// Symbol Table (bang ky hieu) = tap cac cap (key, value)
// Cai dat bang danh sach lien ket don, KHONG sap xep
// key: string, value: int
// ======================================================
struct Node {
    string key;
    int value;
    Node* next;

    Node(string k, int v) {
        key = k;
        value = v;
        next = nullptr;
    }
};

class SymbolTable {
private:
    Node* head;
    int n;                       // so cap (key, value) hien co

    // Tim nut co key cho truoc: O(n). Tra ve nullptr neu khong co
    Node* find(const string& key) const {
        for (Node* p = head; p != nullptr; p = p->next)
            if (p->key == key) return p;
        return nullptr;
    }

public:
    SymbolTable() {
        head = nullptr;
        n = 0;
    }

    // Vo hieu hoa copy de tranh shallow copy
    SymbolTable(const SymbolTable&) = delete;
    SymbolTable& operator=(const SymbolTable&) = delete;

    // put: them cap (key, value). Neu key da co thi cap nhat value
    // O(n): phai tim key truoc (them vao dau chi mat O(1))
    void put(const string& key, int value) {
        Node* p = find(key);
        if (p != nullptr) {              // key da ton tai -> cap nhat
            p->value = value;
            return;
        }
        Node* q = new Node(key, value);  // key moi -> them vao dau
        q->next = head;
        head = q;
        n++;
    }

    // get: lay value theo key. Tra ve false neu khong co key
    // O(n) (xau nhat phai duyet het danh sach)
    bool get(const string& key, int& value) const {
        Node* p = find(key);
        if (p == nullptr) return false;
        value = p->value;
        return true;
    }

    // contains: key co ton tai khong - O(n)
    bool contains(const string& key) const {
        return find(key) != nullptr;
    }

    // remove: xoa cap co key cho truoc. Tra ve false neu khong co key
    // O(n): phai tim nut truoc nut can xoa
    bool remove(const string& key) {
        Node* prev = nullptr;
        Node* p = head;

        while (p != nullptr && p->key != key) {
            prev = p;
            p = p->next;
        }
        if (p == nullptr) return false;  // khong tim thay

        if (prev == nullptr) head = p->next;   // xoa nut dau
        else prev->next = p->next;             // noi bo qua p

        delete p;
        n--;
        return true;
    }

    // size, isEmpty: O(1)
    int size() const { return n; }
    bool isEmpty() const { return n == 0; }

    // Duyet in toan bo: O(n)
    void display() const {
        for (Node* p = head; p != nullptr; p = p->next)
            cout << "(" << p->key << ", " << p->value << ") ";
        cout << endl;
    }

    ~SymbolTable() {
        while (head != nullptr) {
            Node* p = head;
            head = head->next;
            delete p;
        }
    }
};

int main() {
    SymbolTable st;

    st.put("x", 10);
    st.put("y", 20);
    st.put("z", 30);
    st.put("count", 5);

    cout << "Bang ky hieu: ";
    st.display();
    cout << "Size = " << st.size() << endl;

    int v;
    if (st.get("y", v)) cout << "get(y) = " << v << endl;
    cout << "get(abc): " << (st.get("abc", v) ? "co" : "khong co") << endl;

    st.put("y", 99);                     // cap nhat value cua key da co
    st.get("y", v);
    cout << "Sau put(y, 99): y = " << v << ", size = " << st.size() << endl;

    cout << "contains(z) = " << (st.contains("z") ? "true" : "false") << endl;

    st.remove("x");                      // xoa nut cuoi danh sach
    st.remove("count");                  // xoa nut dau danh sach
    cout << "Sau khi xoa x va count: ";
    st.display();
    cout << "remove(khong_co): " << (st.remove("khong_co") ? "OK" : "That bai") << endl;
    return 0;
}

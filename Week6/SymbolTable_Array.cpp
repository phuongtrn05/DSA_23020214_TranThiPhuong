#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ======================================================
// Symbol Table (bang ky hieu) cai dat bang MANG DA SAP XEP
// Hai mang song song: keys[] va values[], keys luon tang dan
// -> tim kiem bang BINARY SEARCH (tim nhi phan)
// key: string, value: int
// ======================================================
class SymbolTable {
private:
    vector<string> keys;         // luon duoc giu theo thu tu tang dan
    vector<int> values;          // values[i] la value cua keys[i]

    // rank: so luong key NHO HON key cho truoc
    // Cung chinh la vi tri cua key neu co, hoac vi tri can chen vao neu chua co
    // Binary search: O(log n)
    int rank(const string& key) const {
        int lo = 0, hi = (int)keys.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (key < keys[mid])      hi = mid - 1;
            else if (key > keys[mid]) lo = mid + 1;
            else return mid;
        }
        return lo;
    }

public:
    // put: them cap (key, value). Neu key da co thi cap nhat value
    // Tim vi tri: O(log n). Chen vao giua mang phai dich phan tu: O(n)
    // => tong: O(n)
    void put(const string& key, int value) {
        int i = rank(key);
        if (i < (int)keys.size() && keys[i] == key) {   // da co -> cap nhat
            values[i] = value;
            return;
        }
        keys.insert(keys.begin() + i, key);             // chen dung vi tri
        values.insert(values.begin() + i, value);       // de mang van tang dan
    }

    // get: lay value theo key. Tra ve false neu khong co key
    // O(log n)
    bool get(const string& key, int& value) const {
        int i = rank(key);
        if (i < (int)keys.size() && keys[i] == key) {
            value = values[i];
            return true;
        }
        return false;
    }

    // contains: key co ton tai khong - O(log n)
    bool contains(const string& key) const {
        int i = rank(key);
        return i < (int)keys.size() && keys[i] == key;
    }

    // remove: xoa cap co key cho truoc. Tra ve false neu khong co key
    // Tim vi tri: O(log n). Xoa giua mang phai dich phan tu: O(n)
    // => tong: O(n)
    bool remove(const string& key) {
        int i = rank(key);
        if (i >= (int)keys.size() || keys[i] != key) return false;
        keys.erase(keys.begin() + i);
        values.erase(values.begin() + i);
        return true;
    }

    // size, isEmpty: O(1)
    int size() const { return (int)keys.size(); }
    bool isEmpty() const { return keys.empty(); }

    // Duyet in toan bo theo thu tu key tang dan: O(n)
    void display() const {
        for (int i = 0; i < (int)keys.size(); i++)
            cout << "(" << keys[i] << ", " << values[i] << ") ";
        cout << endl;
    }
};

int main() {
    SymbolTable st;

    st.put("x", 10);
    st.put("y", 20);
    st.put("z", 30);
    st.put("count", 5);

    cout << "Bang ky hieu (theo thu tu key): ";
    st.display();
    cout << "Size = " << st.size() << endl;

    int v;
    if (st.get("y", v)) cout << "get(y) = " << v << endl;
    cout << "get(abc): " << (st.get("abc", v) ? "co" : "khong co") << endl;

    st.put("y", 99);                     // cap nhat value cua key da co
    st.get("y", v);
    cout << "Sau put(y, 99): y = " << v << ", size = " << st.size() << endl;

    cout << "contains(z) = " << (st.contains("z") ? "true" : "false") << endl;

    st.remove("x");
    st.remove("count");
    cout << "Sau khi xoa x va count: ";
    st.display();
    cout << "remove(khong_co): " << (st.remove("khong_co") ? "OK" : "That bai") << endl;
    return 0;
}

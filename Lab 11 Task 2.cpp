#include <iostream>
using namespace std;

class HashTable {
private:
    int table[7];
    int size;

public:
    HashTable() {
        size = 7;
        for (int i = 0; i < size; i++) {
            table[i] = -1;
        }
    }

    int hashFunction(int key) {
        return key % size;
    }

    void insert(int key) {
        int index = hashFunction(key);
        int startIndex = index;

        while (table[index] != -1) {
            index = (index + 1) % size;
            if (index == startIndex) {
                cout << "Hash Table is Full!\n";
                return;
            }
        }

        table[index] = key;
        cout << key << " inserted at index " << index << endl;
    }

    void search(int key) {
        int index = hashFunction(key);
        int startIndex = index;

        while (table[index] != -1) {
            if (table[index] == key) {
                cout << key << " found at index " << index << endl;
                return;
            }
            index = (index + 1) % size;
            if (index == startIndex) {
                break;
            }
        }

        cout << key << " not found!\n";
    }

    void display() {
        cout << "\nHash Table:\n";
        for (int i = 0; i < size; i++) {
            cout << "Index " << i << " : ";
            if (table[i] == -1) {
                cout << "Empty";
            } else {
                cout << table[i];
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable h;

    h.insert(15);
    h.insert(22);
    h.insert(29);
    h.insert(36);
    h.insert(10);

    h.display();

    h.search(29);
    h.search(50);

    return 0;
}
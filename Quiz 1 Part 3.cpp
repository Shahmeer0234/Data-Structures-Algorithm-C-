#include <iostream>
using namespace std;

class ArrayOperation {
private:
    int* arr;
    int capacity;
    int size;

public:
    ArrayOperation(int cap = 100) {
        capacity = cap;
        size = 0;
        arr = new int[capacity];
    }


    void insertAtEnd(int value) {
        
        arr[size] = value;
        size++;
    }

    void insertAtPosition(int pos, int value) {
    	

        for (int i = size; i > pos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos] = value;
        size++;
    }

    void search(int key) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == key) {
                cout << "Element " << key << " found at index: " << i << endl;
                return;
            }
        }
        cout << "Element " << key << " not found!" << endl;
    }

    void update(int pos, int value) {
        if (pos >= 0 && pos < size) {
            arr[pos] = value;
        } else {
            cout << "Invalid Position for Update!" << endl;
        }
    }

    void removeAt(int pos) {
        if (pos < 0 || pos >= size) {
            cout << "Invalid Position for Deletion!" << endl;
            return;
        }

        for (int i = pos; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    void display() {
        cout << "Array: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    ArrayOperation list(100);

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.display();

    list.insertAtPosition(1, 65);
    list.display();

    list.search(65);

    list.update(1, 78);
    list.display();

    list.removeAt(1);
    list.display();

    return 0;
}
#include <iostream>
using namespace std;

void InsertAtEnd(int value, int arr[], int &size) {
    arr[size] = value;
    size++;
}

void InsertAtPosition(int pos, int value, int arr[], int &size) {
    
    for (int i = size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    size++;
}

void Search(int size, int key, int arr[]) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            cout << "Element " << key << " found at index: " << i << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "Element not found!" << endl;
}

void Update(int pos, int value, int arr[], int size) {
    if (pos >= 0 && pos < size) {
        arr[pos] = value;
    }
}

void Delete(int pos, int arr[], int &size) {
    
    for (int i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}

void Display(int arr[], int size) {
    cout << "Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[100];
    int size = 0;
    
    InsertAtEnd(10, arr, size);
    InsertAtEnd(20, arr, size);
    InsertAtEnd(30, arr, size);
    Display(arr, size);

    InsertAtPosition(1, 65, arr, size);
    Display(arr, size);

    Search(size, 65, arr);

    Update(1, 78, arr, size);
    Display(arr, size);

    Delete(1, arr, size);
    Display(arr, size);

    return 0;
}
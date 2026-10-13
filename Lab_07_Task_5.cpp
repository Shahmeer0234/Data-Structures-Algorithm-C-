#include <iostream>
#include <string>
using namespace std;

class CircularQueue {
private:
    int orderIDs[5];
    string foodItems[5];
    int front;
    int rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    void addOrder(int id, string item) {
        if ((rear + 1) % 5 == front) {
            cout<<"Queue is Full"<<endl;
            return;
        } else {
            if (front == -1) {
                front = 0;
                rear = 0;
            } else {
                rear = (rear + 1) % 5;
            }
            orderIDs[rear] = id;
            foodItems[rear] = item;
            cout<<"Order added: ID "<<id<<" - "<<item<<endl;
        }
    }

    void completeOrder() {
        if (front == -1) {
            cout<<"Queue is empty"<<endl;
            return;
        } else {
            cout<<"Completed Order: ID "<<orderIDs[front]<<" - "<<foodItems[front]<<endl;
            if (front == rear) {
                front = -1;
                rear = -1;
            } else {
                front = (front + 1) % 5;
            }
        }
    }

    void displayPendingOrders() {
        if (front == -1) {
            cout<<"Queue is empty"<<endl;
            return;
        } else {
            cout<<"Pending Orders:"<<endl;
            int i = front;
            while (true) {
                cout<<"Order ID: "<<orderIDs[i]<<" - Item: "<<foodItems[i]<<endl;
                if (i == rear) {
                    break;
                }
                i = (i + 1) % 5;
            }
        }
    }
};

int main() {
    CircularQueue cq;
    cout<<"=================Adding Orders======================="<<endl;
    cq.addOrder(1, "Burger");
    cq.addOrder(2, "Pizza");
    cq.addOrder(3, "Sandwich");
    cq.addOrder(4, "Fries");
    cq.addOrder(5, "Pasta");

    cout<<"=================Displaying Orders======================="<<endl;
    cq.displayPendingOrders();

    cout<<"=================Completing Orders======================="<<endl;
    cq.completeOrder();
    cq.completeOrder();

    cout<<"=================Reusing Space (Adding New Orders)======================="<<endl;
    cq.addOrder(6, "Shawarma");
    cq.addOrder(7, "Roll");

    cout<<"=================Displaying Pending Orders======================="<<endl;
    cq.displayPendingOrders();

    return 0;
}
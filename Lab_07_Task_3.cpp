#include <iostream>
#include <string>
using namespace std;

class PatientQueue {
private:
    int tokens[5];
    string names[5];
    int front;
    int rear;

public:
    PatientQueue() {
        front = -1;
        rear = -1;
    }

    void addPatient(int token, string name) {
        if (rear == 4) {
            cout<<"Queue is Full"<<endl;
            return;
        } else {
            if (front == -1) {
                front = 0;
            }
            rear++;
            tokens[rear] = token;
            names[rear] = name;
            cout<<"Patient Added: Token "<<token<<" - "<<name<<endl;
        }
    }

    void serveNextPatient() {
        if (front == -1 || front > rear) {
            cout<<"Queue is empty"<<endl;
            return;
        } else {
            cout<<"Serving Patient: Token "<<tokens[front]<<" - "<<names[front]<<endl;
            front++;
            if (front > rear) {
                front = -1;
                rear = -1;
            }
        }
    }

    void displayNextPatient() {
        if (front == -1 || front > rear) {
            cout<<"Queue is empty"<<endl;
            return;
        } else {
            cout<<"Next Patient: Token "<<tokens[front]<<" - "<<names[front]<<endl;
        }
    }

    void displayWaitingPatients() {
        if (front == -1 || front > rear) {
            cout<<"Queue is empty"<<endl;
            return;
        } else {
            cout<<"Waiting Patients:"<<endl;
            for (int i = front; i <= rear; i++) {
                cout<<"Token "<<tokens[i]<<" - "<<names[i]<<endl;
            }
        }
    }
};

int main() {
    PatientQueue pq;
    cout<<"=================Adding Patients======================="<<endl;
    pq.addPatient(101, "Ali");
    pq.addPatient(102, "Ahmed");
    pq.addPatient(103, "Usman");
    pq.addPatient(104, "Sara");
    pq.addPatient(105, "Zain");

    cout<<"=================Serving Next Patient======================="<<endl;
    pq.serveNextPatient();

    cout<<"=================Display Next Patient======================="<<endl;
    pq.displayNextPatient();

    cout<<"=================Display Waiting Patients======================="<<endl;
    pq.displayWaitingPatients();

    return 0;
}
#include <iostream>
#include <string>
using namespace std;

class PrinterQueue {
private:
    string docNames[5];
    int pageCounts[5];
    int front;
    int rear;

public:
    PrinterQueue() {
        front = -1;
        rear = -1;
    }

    void addDocument(string docName, int pages) {
        if (rear == 4) {
            cout<<"Queue is Full"<<endl;
            return;
        } else {
            if (front == -1) {
                front = 0;
            }
            rear++;
            docNames[rear] = docName;
            pageCounts[rear] = pages;
            cout<<"Document added: "<<docName<<" ("<<pages<<" pages)"<<endl;
        }
    }

    void printNextDocument() {
        if (front == -1 || front > rear) {
            cout<<"Queue is empty"<<endl;
            return;
        } else {
            cout<<"Printing: "<<docNames[front]<<" ("<<pageCounts[front]<<" pages)"<<endl;
            front++;
            if (front > rear) {
                front = -1;
                rear = -1;
            }
        }
    }

    void displayTotalWaiting() {
        if (front == -1 || front > rear) {
            cout<<"Total documents waiting: 0"<<endl;
            return;
        } else {
            int count = (rear - front) + 1;
            cout<<"Total documents waiting: "<<count<<endl;
        }
    }

    void displayTotalPagesRemaining() {
        if (front == -1 || front > rear) {
            cout<<"Total pages remaining: 0"<<endl;
            return;
        } else {
            int totalPages = 0;
            for (int i = front; i <= rear; i++) {
                totalPages += pageCounts[i];
            }
            cout<<"Total pages remaining to be printed: "<<totalPages<<endl;
        }
    }
};

int main() {
    PrinterQueue pq;
    cout<<"=================Adding Documents======================="<<endl;
    pq.addDocument("Assignment1.pdf", 10);
    pq.addDocument("LabReport.docx", 5);
    pq.addDocument("Presentation.pptx", 15);
    pq.addDocument("Resume.pdf", 2);
    pq.addDocument("Syllabus.pdf", 8);

    cout<<"=================Total Waiting Documents======================="<<endl;
    pq.displayTotalWaiting();

    cout<<"=================Total Pages Remaining======================="<<endl;
    pq.displayTotalPagesRemaining();

    cout<<"=================Printing Next Document======================="<<endl;
    pq.printNextDocument();

    cout<<"=================Total Pages Remaining After Printing======================="<<endl;
    pq.displayTotalPagesRemaining();

    return 0;
}
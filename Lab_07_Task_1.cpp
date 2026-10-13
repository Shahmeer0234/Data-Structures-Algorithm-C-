#include <iostream>
#include <string>
using namespace std;

class BrowserHistory {
private:
    string history[5];
    int top;

public:
    BrowserHistory() {
        top = -1;
    }

    void visitPage(string url) {
        if (top == 4) {
            cout<<"History is Full"<<endl;
            return;
        } else {
            top++;
            history[top] = url;
            cout<<"Visited: "<<url<<endl;
        }
    }

    void goBack() {
        if (top == -1) {
            cout<<"No previous page to go back to"<<endl;
            return;
        } else {
            cout<<"Going back from: "<<history[top]<<endl;
            top--;
            if (top != -1) {
                cout<<"Current Page: "<<history[top]<<endl;
            } else {
                cout<<"No pages left in history"<<endl;
            }
        }
    }

    void displayMostRecent() {
        if (top == -1) {
            cout<<"History is Empty"<<endl;
            return;
        } else {
            cout<<"Most Recently Visited: "<<history[top]<<endl;
        }
    }

    void displayHistory() {
        if (top == -1) {
            cout<<"History is Empty"<<endl;
            return;
        } else {
            cout<<"Browsing History:"<<endl;
            for (int i = top; i >= 0; i--) {
                cout<<history[i]<<endl;
            }
        }
    }
};

int main() {
    BrowserHistory bh;
    cout<<"=================Visiting Websites======================="<<endl;
    bh.visitPage("google.com");
    bh.visitPage("youtube.com");
    bh.visitPage("github.com");
    bh.visitPage("stackoverflow.com");
    bh.visitPage("linkedin.com");

    cout<<"=================Most Recent Website======================="<<endl;
    bh.displayMostRecent();

    cout<<"=================Going Back======================="<<endl;
    bh.goBack();

    cout<<"=================Remaining History======================="<<endl;
    bh.displayHistory();

    return 0;
}
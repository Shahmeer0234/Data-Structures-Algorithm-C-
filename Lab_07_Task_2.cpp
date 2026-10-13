#include <iostream>
#include <string>
using namespace std;

class TextEditor {
private:
    string actions[5];
    int top;

public:
    TextEditor() {
        top = -1;
    }

    void performAction(string action) {
        if (top == 4) {
            cout<<"Action limit reached"<<endl;
            return;
        } else {
            top++;
            actions[top] = action;
            cout<<"Action performed: "<<action<<endl;
        }
    }

    void undoLastAction() {
        if (top == -1) {
            cout<<"No actions to undo"<<endl;
            return;
        } else {
            cout<<"Undone action: "<<actions[top]<<endl;
            top--;
        }
    }

    void displayRemainingActions() {
        if (top == -1) {
            cout<<"No remaining actions in history"<<endl;
            return;
        } else {
            cout<<"Remaining actions (most recent first):"<<endl;
            for (int i = top; i >= 0; i--) {
                cout<<actions[i]<<endl;
            }
        }
    }
};

int main() {
    TextEditor editor;
    cout<<"=================Performing Actions======================="<<endl;
    editor.performAction("Typing 'Hello'");
    editor.performAction("Deleting 'o'");
    editor.performAction("Formatting Bold");
    editor.performAction("Typing ' World'");
    editor.performAction("Changing Font Color");

    cout<<"=================Undoing Last Action======================="<<endl;
    editor.undoLastAction();

    cout<<"=================Remaining Actions======================="<<endl;
    editor.displayRemainingActions();

    return 0;
}
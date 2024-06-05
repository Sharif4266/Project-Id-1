#include <iostream>
#include <stack>
#include <string>

using namespace std;

class TextEditor {
private:
    string text;
    stack<string> undoStack;

public:
    TextEditor() {
        text = "";
    }

    void insert(char c) {
        text += c;
        undoStack.push(text);
    }

    void remove() {
        if (!text.empty()) {
            text.pop_back();
            undoStack.push(text);
        }
    }

    void undo() {
        if (!undoStack.empty()) {
            undoStack.pop();
            if (!undoStack.empty()) {
                text = undoStack.top();
            } else {
                text = "";
            }
        }
    }

    string getText() {
        return text;
    }
};

int main() {
    TextEditor editor;

    editor.insert('H');
    editor.insert('e');
    editor.insert('l');
    editor.insert('l');
    editor.insert('o');
    cout << "Text: " << editor.getText() << endl; // Output: Text: Hello

    editor.undo();
    cout << "Text after undo: " << editor.getText() << endl; // Output: Text after undo: Hell

    return 0;
}

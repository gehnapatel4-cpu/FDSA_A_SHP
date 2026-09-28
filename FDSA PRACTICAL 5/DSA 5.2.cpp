#include <iostream>
using namespace std;

struct SNode {
    string name;
    SNode* next;
};

SNode* shead = NULL;

void sJoin(string name) {
    SNode* n = new SNode;
    n->name = name;

    if (shead == NULL) {
        shead = n;
        n->next = shead;
        return;
    }

    SNode* temp = shead;

    while (temp->next != shead)
        temp = temp->next;

    temp->next = n;
    n->next = shead;
}

void sLeave(string name) {
    if (shead == NULL)
        return;

    SNode* temp = shead;
    SNode* prev = NULL;

    do {
        if (temp->name == name)
            break;

        prev = temp;
        temp = temp->next;
    } while (temp != shead);

    if (temp->name != name)
        return;

    if (temp == shead) {
        if (shead->next == shead) {
            shead = NULL;
        } else {
            SNode* last = shead;

            while (last->next != shead)
                last = last->next;

            shead = shead->next;
            last->next = shead;
        }
    } else {
        prev->next = temp->next;
    }

    delete temp;
}

void sDisplay() {
    if (shead == NULL) {
        cout << "Empty" << endl;
        return;
    }

    SNode* temp = shead;

    do {
        cout << temp->name << " ";
        temp = temp->next;
    } while (temp != shead);

    cout << endl;
}


struct DNode {
    string name;
    DNode* prev;
    DNode* next;
};

DNode* dhead = NULL;

void dJoin(string name) {
    DNode* n = new DNode;
    n->name = name;

    if (dhead == NULL) {
        dhead = n;
        n->next = dhead;
        n->prev = dhead;
        return;
    }

    DNode* last = dhead->prev;

    n->next = dhead;
    n->prev = last;

    last->next = n;
    dhead->prev = n;
}

void dLeave(string name) {
    if (dhead == NULL)
        return;

    DNode* temp = dhead;

    do {
        if (temp->name == name)
            break;

        temp = temp->next;
    } while (temp != dhead);

    if (temp->name != name)
        return;

    if (temp->next == temp) {
        dhead = NULL;
        delete temp;
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    if (temp == dhead)
        dhead = temp->next;

    delete temp;
}

void dDisplay() {
    if (dhead == NULL) {
        cout << "Empty" << endl;
        return;
    }

    DNode* temp = dhead;

    do {
        cout << temp->name << " ";
        temp = temp->next;
    } while (temp != dhead);

    cout << endl;
}

int main() {

    cout << "Singly Circular:" << endl;

    sJoin("A");
    sJoin("B");
    sJoin("C");
    sDisplay();

    sLeave("B");
    sDisplay();

    cout << endl;

    cout << "Doubly Circular:" << endl;

    dJoin("A");
    dJoin("B");
    dJoin("C");
    dDisplay();

    dLeave("B");
    dDisplay();

    return 0;
}

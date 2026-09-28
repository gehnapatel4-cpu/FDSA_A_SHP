#include <iostream>
using namespace std;

class Node {
public:
    string song;
    Node* prev;
    Node* next;

    Node(string s) {
        song = s;
        prev = NULL;
        next = NULL;
    }
};

class Playlist {
public:
    Node* head = NULL;


    void addFirst(string song) {
        Node* newNode = new Node(song);

        newNode->next = head;

        if (head != NULL)
            head->prev = newNode;

        head = newNode;

        display();
    }


    void addLast(string song) {
        Node* newNode = new Node(song);

        if (head == NULL) {
            head = newNode;
            display();
            return;
        }

        Node* temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;

        display();
    }


    void insertAfter(string oldSong, string newSong) {
        Node* temp = head;

        while (temp != NULL && temp->song != oldSong)
            temp = temp->next;

        if (temp == NULL) {
            cout << "Song not found" << endl;
            display();
            return;
        }

        Node* newNode = new Node(newSong);

        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != NULL)
            temp->next->prev = newNode;

        temp->next = newNode;

        display();
    }


    void removeFirst() {
        if (head == NULL) {
            cout << "Playlist is empty" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;

        if (head != NULL)
            head->prev = NULL;

        delete temp;

        display();
    }


    void count() {
        int count = 0;
        Node* temp = head;

        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        cout << "Count = " << count << endl;
    }

    // Display songs
    void display() {
        Node* temp = head;

        cout << "Playlist: ";

        while (temp != NULL) {
            cout << temp->song << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {
    Playlist p;

    p.addFirst("A");
    p.addLast("B");
    p.addLast("C");

    p.insertAfter("B", "X");

    p.count();

    p.removeFirst();

    p.count();

    return 0;
}

#include <iostream>
using namespace std;

class Node{
    public:
    string name;
    Node* Next;
};

class TrainersList{
    private:
    Node* head;
    public:
        TrainersList(){
            head = NULL;
        }
        bool isEmpty(){
            return head == NULL;
        }
        void insert(string name) {
            Node* newNode = new Node;
            newNode -> name = name;
            newNode->Next = head;
            head = newNode;
            cout << name << " added to Trainers List" << endl;
        }
};

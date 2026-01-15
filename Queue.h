#include <iostream>
using namespace std;

class Node{
    public:
        string name;
        int rank;
        string muscle;
        Node* Next;
};

class ExerciseQueue{
    private:
        Node* front;
    public:
        ExerciseQueue(){
            front = NULL;
        }
        bool isEmpty(){
            return front == NULL;
        }
        void enqueue(string name, int rank, string muscle){
            Node* newNode = new Node;
            newNode -> name = name;
            newNode -> rank = rank;
            newNode -> muscle = muscle;
            newNode -> Next = NULL;
            if (isEmpty() || newNode->rank >= front->rank) {
                newNode-> Next = front;
                front = newNode;
            } else {
                Node* temp = front;
                while (temp->Next != NULL && temp->Next->rank >= rank) {
                    temp = temp -> Next;
                }
                newNode -> Next = temp->Next;
                temp->Next = newNode;
            }
        }
        void dequeue(){
            Node* temp = front;
            if (isEmpty()) {
                cout << "No exercises for this machine!" << endl;
            } else {
                front = front->Next;
                delete temp;
            }
        }
};
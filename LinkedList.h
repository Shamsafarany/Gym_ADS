#include <iostream>
using namespace std;

class TNode{
    public:
    string name;
    TNode* Next;
};

class TrainersList{
    private:
    TNode* head;
    public:
        TrainersList(){
            head = NULL;
        }
        bool isEmpty(){
            return head == NULL;
        }
        void insert(string name) {
            TNode* newNode = new TNode;
            newNode ->name = name;
            newNode->Next = head;
            head = newNode;
            cout << name << " added to Trainers List" << endl;
        }
        void display(){
            TNode* temp = head;
            if(isEmpty()){
                cout << "No trainers added!" << endl;
            }
            while(temp!= NULL) {
                cout << "Trainer " << temp->name << endl;
                temp = temp -> Next;
            }
        }
};

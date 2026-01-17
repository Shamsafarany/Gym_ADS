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
            cout << name <<" added to Trainers List" << endl;
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

        void printReverse(){
            if (head == NULL) {
                cout <<"No trainers added! " << endl;
                return;
            }
            printReverseHelper(head);
        }
        void printReverseHelper(TNode* node) {
            if (node == nullptr){
                return;
            }
            printReverseHelper(node->Next);
            cout << "    - " << node->name << endl; 
        }
         bool deleteTrainer(string name){
            TNode* temp = head;
            TNode* prev = NULL;
            if (isEmpty()) {
                cout << "No exercises for this machine!" << endl;
                return false;
            } else {
                while(temp != NULL && temp->name != name){
                    prev = temp;
                    temp = temp->Next;
                }
                if(temp!= NULL) {
                    if(prev == NULL){
                        head = head->Next;
                        cout <<"Removed trainer: " << temp -> name << endl;
                        delete temp;
                    } else {
                        prev->Next = temp->Next;
                        cout <<"Removed trainer: " << temp -> name << endl;
                        delete temp;
                    }
                } else {
                    cout << "Trainer not found!" << endl;
                    return false;
                }
                return true;
            }
        }
};

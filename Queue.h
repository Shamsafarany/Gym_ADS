#pragma once
#include <iostream>
#include <string>
using namespace std;

class QNode{
    public:
        string name;
        int rank;
        string muscle;
        QNode* Next;
};

class ExerciseQueue{
    private:
        QNode* front;
    public:
        ExerciseQueue(){
            front = NULL;
        }
        bool isEmpty(){
            return front == NULL;
        }
        void enqueue(string name, int rank, string muscle){
            QNode* newNode = new QNode;
            newNode -> name = name;
            newNode -> rank = rank;
            newNode -> muscle = muscle;
            newNode -> Next = NULL;
            if (isEmpty() || newNode->rank >= front->rank) {
                newNode-> Next = front;
                front = newNode;
            } else {
                QNode* temp = front;
                while (temp->Next != NULL && temp->Next->rank >= rank) {
                    temp = temp -> Next;
                }
                newNode -> Next = temp->Next;
                temp->Next = newNode;
            }
        }
        bool deleteExercise(string name){
            QNode* temp = front;
            QNode* prev = NULL;
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
                        front = front->Next;
                        cout <<"Removed exercise: " << temp -> name << endl;
                        delete temp;
                    } else {
                        prev->Next = temp->Next;
                        cout <<"Removed exercise: " << temp -> name << endl;
                        delete temp;
                    }
                } else {
                    cout << "Exercise not found!" << endl;
                    return false;
                }
                return true;
            }
        }

        void display(){
            QNode* temp = front;
            if(isEmpty()){
                cout << "No exercises added!" << endl;
                return;
            }
            while (temp != NULL) {
                cout << temp-> name << " " << temp->muscle << " " << temp->rank << endl;
                temp = temp->Next;
            }
        }
};
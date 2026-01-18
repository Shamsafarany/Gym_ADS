#pragma once
#include <iostream>
#include "Queue.h"
#include "LinkedList.h"
using namespace std;

class BSTNode{
public:
    string name;
    int number;
    ExerciseQueue exercises;
    TrainersList trainers;
    BSTNode* left;
    BSTNode* right;
};

class BST{
    private: 
        BSTNode* root;
        int count;
    public:
        BST(){
            root = NULL;
            count = 0;
        };
        bool isEmpty(){
            return root == NULL;
        }
        void insert(string name, int number) {
            BSTNode* newNode = new BSTNode;
            newNode-> left = NULL;
            newNode-> right = NULL;
            newNode-> name = name;
            newNode-> number = number;
            if (isEmpty()) {
                root = newNode;
            } else {
                BSTNode* parent = NULL;
                BSTNode* temp = root;
                while(temp) {
                    parent = temp;
                    if (name < temp-> name) {
                        temp = temp -> left;
                    } else if (name > temp-> name) {
                        temp = temp-> right;
                    } else {
                        delete newNode;
                        cout << "Duplicate name '" << name << "' not inserted!" << endl;
                        return; 
                    }
                }
                if (name < parent->name) {
                    parent->left = newNode;
                } else {
                    parent->right = newNode;
                }    
            }
            cout <<"Machine: " << name << " | " << "Number: " << number << " inserted" << endl;
            count++;
        }
        bool search(string name, BSTNode* root) {
            BSTNode* temp = root;
            if (temp == NULL) {
                cout <<"Machine not found!" << endl;
                return false;
            } else if (name == temp->name) {
                cout << "Machine found" << endl;
                cout << temp->name << " " << temp-> number << " " << endl;
                cout <<"Exercises: " << endl;
                temp->exercises.display();
                cout <<"Trainers: " << endl;
                temp->trainers.display();
                return true;
            } else if (name < temp->name) {
                return search(name, temp-> left);
            } else{
                return search(name, temp->right);
            }     
         }
         void printInOrder(BSTNode* node){
            if (node != NULL) {
                printInOrder(node-> left);
                cout << node->name << " " << node-> number << endl;
                cout <<"Exercises: " << endl;
                node->exercises.display();
                cout <<"Trainers: " << endl;
                node->trainers.display();
                cout <<"----------------------------" << endl;
                printInOrder(node->right);
            }
         }
        void display() {
            if (isEmpty()) {
                cout << "No machines!" << endl;
            } else {
                cout << "Machines in alphabetical order: " <<endl;
                printInOrder(root);
            }
        }

        void deleteTree(BSTNode* node){
            if(node!= NULL) {
                deleteTree(node -> left);
                deleteTree(node -> right);
                delete node;
            }
        }

        BSTNode* searchMachine(string name){
            BSTNode* current = root;
            if(isEmpty()) {
                cout<<"No machines" << endl;
                return nullptr;
            }
             while(current != NULL) {
                if (name == current->name) {
                    cout << "Found machine " << current->name << " " << current->number << endl;
                cout <<"Exercises: " << endl;
                current->exercises.display();
                cout <<"Trainers: " << endl;
                current->trainers.display();
                    return current;
                }
                if(name < current->name) {
                    current = current-> left;
                } else {
                    current = current-> right;
                }
            }
                cout <<"Machine " << name << " not found!" << endl;
                return nullptr;
            
        }

        void addExercise(string machine, string Exename, int rank, string muscle){
            //search for machine
            BSTNode* machineNode = searchMachine(machine);
            if (machineNode != nullptr) {
                machineNode -> exercises.enqueue(Exename, rank, muscle);
                cout <<"Exercise " << Exename << " added to " << machine << endl;
            }    
        }
        
        void removeExercise(string machine, string name){
            //search for machine
            BSTNode* machineNode = searchMachine(machine);
            if(machineNode != nullptr) {
               bool deleted = machineNode ->exercises.deleteExercise(name);
               if (deleted) {
                cout << "Exercise " << name << " removed from " << machine <<endl;
               } else {
                 return;
               }
                
            }
        }

        void addTrainer(string machine, string name) {
            BSTNode* machineNode = searchMachine(machine);
            if (machineNode != nullptr) {
                machineNode ->trainers.insert(name);
                cout << name << " assigned to " << machine << endl;
            }
        }
        void removeTrainer(string machine, string trainer){
            //search for machine
            BSTNode* machineNode = searchMachine(machine);
            if(machineNode != nullptr) {
               bool deleted = machineNode ->trainers.deleteTrainer(trainer);
               if (deleted) {
                cout << "Trainer " << trainer << " removed from " << machine <<endl;
               } else {
                 return;
               }
                
            }
        }


        void deleteMachine(string name){
            bool found = false;
            if (isEmpty()) {
                cout << "No machines added!" << endl;
                return;
            } else {
                BSTNode* parent = NULL;
                BSTNode* temp = root;
                while (temp!= NULL) {
                    if (temp-> name == name) {
                        found = true;
                        break;
                    } else {
                        parent = temp;
                        if(name > temp->name) {
                            temp = temp-> right;
                        } else {
                            temp = temp -> left;
                        }
                    }
                }
                if (!found) {
                    cout << "Machine not found" <<endl;
                    return;
                }
                //case1: leaf node
                if (temp-> left == NULL && temp->right == NULL) {
                    if (parent->left == temp) {
                        parent->left = NULL;
                    } else {
                        parent->right = NULL;
                    }
                    delete temp;
                    return;
                } else if ((temp->left == NULL && temp->right != NULL) || (temp->left != NULL && temp->right == NULL)) {
                    if (temp->left == NULL && temp->right != NULL) {
                        if (parent->left == temp){
                            parent->left = temp->right;
                        } else {
                            parent->right = temp ->right;
                        }
                        delete temp;
                    } else {
                        if (parent->left == temp) {
                            parent->left = temp->left;
                        } else {
                            parent->right = temp->left;
                        }
                        delete temp;
                    }
                    return;
                }
            }
        }

        void printTrainersReverse(BSTNode* node){
           if (node != NULL) {
                printTrainersReverse(node->left);
                cout<< node->name << ": " << endl;
                node->trainers.printReverse();
                printTrainersReverse(node->right);
           }
        }
        void printTrainersReverseHelper(){
            if (root == NULL) {
                cout << "No machines added!" << endl;
                return;
            } else {
                printTrainersReverse(root);
            }
        }

        ~BST(){
            deleteTree(root);
        };
};
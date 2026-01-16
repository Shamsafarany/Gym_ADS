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
    public:
        BST(){
            root = NULL;
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
                cout <<"Machine - " << name << " - " << number << " - inserted!" << endl;
            }
        }
        bool search(string name, BSTNode* root) {
            BSTNode* temp = root;
            if (temp == NULL) {
                cout <<"Machine not found!" << endl;
                return false;
            } else if (name == temp->name) {
                cout << "Machine found" << endl;
                cout << temp->name << " " << temp-> number << " " << endl;
                return true;
            } else if (name < temp->name) {
                return search(name, temp-> left);
            } else{
                return search(name, temp->right);
            }     
         }
         void printInOrder(BSTNode* node){
            cout << "Machines in alphabetical order: " <<endl;
            if (node != NULL) {
                printInOrder(node-> left);
                cout << node->name << " " << node-> number << endl;
                cout <<"Exercises: ";
                node->exercises.display();
                cout <<"Trainers: ";
                node->trainers.display();
                printInOrder(node->right);
            }
         }
        
        void display() {
            if (isEmpty()) {
                cout << "No machines!" << endl;
            } else {
                printInOrder(root);
            }
        };

        void deleteTree(BSTNode* node){
            if(node!= NULL) {
                deleteTree(node -> left);
                deleteTree(node -> right);
                delete node;
            }
        }

        BSTNode* searchMachine(string name){
            BSTNode* current = root;
             while(current != NULL) {
                if (name == current->name) {
                    cout << "Found machine: " << current->name << endl;
                    return current;
                }
                if(name < current->name) {
                    current = current-> left;
                } else {
                    current = current-> right;
                }
            }
                cout <<"Machine: " << name << " not found!" << endl;
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
                machineNode ->exercises.deleteExercise(name);
                cout << "Exercise " << name << " removed from " << machine <<endl;
            }
        }

        void addTrainer(string machine, string name) {
            BSTNode* machineNode = searchMachine(machine);
            if (machineNode != nullptr) {
                machineNode ->trainers.insert(name);
                cout << name << " assigned to " << machine << endl;
            }
        }

        






        ~BST(){
            deleteTree(root);
        };
};
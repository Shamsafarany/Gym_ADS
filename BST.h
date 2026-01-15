#pragma once
#include <iostream>
using namespace std;

class BSTNode{
public:
    string name;
    int number;
    //queue
    //linkedList to be added
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
                return true;
            } else if (name < temp->name) {
                return search(name, temp-> left);
            } else{
                return search(name, temp->right);
            }     
         }
        
        void remove(int data );
        void display();

        ~BST();
};
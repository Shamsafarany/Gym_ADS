#include <iostream>
#include "BST.h"
using namespace std;

int displayMenu();
void insertMachine(BST& machines);
void searchMachine(BST& machines);
int main(){
    BST machines;
    
    int choice = displayMenu();
    do{
        switch(choice) {
            case 1: 
                insertMachine(machines);
                choice = displayMenu();
                break;
        }
    } while(choice != 8);




    return 0;
}

int displayMenu(){
    int choice;
    cout << "----------------- Menu ---------------" <<endl;
    cout <<endl;
    do {
        cout <<"1 - Add Machine" << endl;
        cout <<"2 - Search Machine" << endl;
        cout <<"3 - Delete Machine" << endl;
        cout <<"4 - Add Exercise" << endl;
        cout <<"5 - Delete Exercise" << endl;
        cout <<"6 - Print Machines (Alphabetical Order)" << endl;
        cout <<"7 - Print Trainers (Descending Order) " << endl;
        cout <<"8 - Exit" <<endl;
        cout <<"Choose operation: ";
        cin >> choice;
    } while(choice < 1 || choice > 8);
   
    return choice;
}

void insertMachine(BST& machines){
    cout<< "--  Add Machine --" << endl;
    string name;
    int number;
    cout<<"Enter machine name: ";
    cin>> name;
    cout <<"Enter machine number: ";
    cin>> number;
    machines.insert(name, number);
}

void searchMachine(BST& machines){
    cout<< "--  Search Machine  --" << endl;
    string name;
    cout<<"Enter machine name: " << endl;
    cin >> name;
    bool found = machines.search(name, BST* machines);
}
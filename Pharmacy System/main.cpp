//Pharmacy-System
#include <iostream>
using namespace std;
#include <iostream>
#include <string.h>
using namespace std;

class node {   //The components of each node
public:
    string name;
    double price;
    int quantity;
    node* next;
    node* prev;
};

class DLL //The Double Linked List
{
public:
    node* head;
    int Counter;

    DLL() { //Default Constructor
        head = NULL;
        Counter = 0;
    }

    bool IsEmpty() { //Is the Double Linked List empty?
        return head == NULL;
    }

    void InsertFirst(string N, double P, int Q) { //Insert new node at first of the Double Linked List
        node* newnodeptr = new node;
        newnodeptr->prev = NULL;
        newnodeptr->name = N;
        newnodeptr->price = P;
        newnodeptr->quantity = Q;


        if (IsEmpty()) { //Check if the DLL is empty
            newnodeptr->next = NULL;
            head = newnodeptr;
        }
        else {
            newnodeptr->next = head;
            head = newnodeptr;
        }
        Counter++;
    }

    void InsertLast(string N, double P , int Q) {
        if (IsEmpty()) {
            InsertFirst(N , P , Q);
        }
        else {
            node* newnodeptr = new node;
            node* pointer;
            pointer = head;
            while (pointer->next != NULL) {
                pointer = pointer->next;
            }
            newnodeptr->prev = pointer;
            newnodeptr->name = N;
            newnodeptr->price = P;
            newnodeptr->quantity = Q;


            newnodeptr->next = NULL;
            pointer->next = newnodeptr;
            Counter++;
        }
    }

    //insert position
    void insertAtPosition( int position, string N, double P, int Q) {

        if (position < 1 || position > Counter)
        {
            cout<<"This position is out of range\n";
        }

        else
        {
            node *newnodeptr = new node;
            newnodeptr -> name = N;
            newnodeptr -> quantity = Q;
            newnodeptr -> price = P;
            node *currentnode = head;
            for (int i = 1; i < position; i++)
            {
                currentnode = currentnode->next;
            }
            newnodeptr -> prev = currentnode -> prev;
            newnodeptr -> next = currentnode;
            currentnode -> prev -> next= newnodeptr;
            currentnode -> prev = newnodeptr;
            Counter++;
        }
    }


    void DeleteFirst() {
        if (head == NULL) {
            cout << "The list is empty. You have to add some items before taking this action\n";
        }
        else {
            node* pointer;
            pointer = head;
            if (Counter == 1) {
                delete pointer;
                head = NULL;
            }
            else {
                head = pointer->next;
                pointer->prev = NULL;
                delete pointer;
            }
            Counter--;
        }
    }

    void DeleteLast(){
        if (IsEmpty())
        {
            cout << "The list is empty. You have to add some items before taking this action\n";
        }
        else
        {
            node* pointer = head;
            if (pointer->next == NULL)
            {
                delete pointer;
                head = NULL;
            }
            else
            {
                while (pointer->next != NULL)
                {
                    pointer = pointer->next;
                }
                pointer->prev->next = NULL;
                delete pointer;
                Counter--;
            }
        }
    }

    void DeletePosition(int Position){
           if (IsEmpty())
        {
            cout << "The list is empty. You have to add some items before taking this action\n";
        }
        else if (Position < 1)
        {
            cout << "This position is out of range\n";
        }
        else if (Position == 1)
        {
            DeleteFirst();
        }
        else
        {
            node* currentnode = head;
            for (int i=1; i< Position;i++)
            {
                currentnode = currentnode->next;
            }
            if (currentnode == NULL)
            {
                cout << "This position is out of range\n";
            }
            else if (currentnode->next == NULL)
            {
                currentnode->prev->next = NULL;
                delete currentnode;
            }
            else
            {
                currentnode->prev->next = currentnode->next;
                currentnode->next->prev = currentnode->prev;
                delete currentnode;
                Counter--;
            }
        }
    }

    //6. Generate bill for a customer:
    void displayForward (){   //prints elements from the beginning to the last
    if (head==NULL)
    {cout << "The list is empty. You have to add some items before taking this action\n";
    return;}

    else{
        node* temp = head;
        while (temp != NULL){
        cout<<"the name of the medicine is: "<< temp->name<<endl;
        cout<<"the price of the medicine is: "<<temp->price<<endl;
        cout<<"the quantity of the medicine is: "<<temp->quantity<<endl;

        temp=temp->next;
        }
    } }

    void displayBackward (){
        if (head==NULL)
        {cout << "The list is empty. You have to add some items before taking this action\n";
        return;}

        else{
        node* temp = head;
         //going to last node
        while (temp->next != NULL){
        temp=temp->next;}
        // traversing backward
        while (temp != NULL){
        cout<<"the name of the medicine is: "<< temp->name<<endl;
        cout<<"the price of the medicine is: "<<temp->price<<endl;
        cout<<"the quantity of the medicine is: "<<temp->quantity<<endl;

        temp=temp->prev;
        } } }

    //5. Find the location of the product :
int findIndex(string value ){ //, int index
    node* current = head;
    int index = 0;
    while (current != NULL) {
        if (current->name == value) {
            return index;
        }
        current = current->next;
        index++;
    }
    return -1; // value not found
}



    // Modify the item at the given index
    void modify(int index, string N , double P , int Q) {
        node* current = head;
        for (int i = 0; i < index; i++) {
        current = current->next;
            }
            current->name = N;
            current->price= P;
            current->quantity= Q;
        }

    // Declare a function to check the pharmacy for low quantity products
    void checkPharmacy() {
    // Traverse the list and check the quantity of each product
        node* current = head;
        while (current != NULL) {
        if (current->quantity < 10) {
        cout << "Low quantity for product " << current->name << ". Quantity: " << current->quantity << endl;
            }
            current = current->next;
        }
    }
};



int main()
{    DLL list ;
      int loc ;
      int quantity;
      int index;
     int choice;
    string name;
    double price;
    int position;
    node* next;
    node* prev;


    do {
        cout << "0. to Exit program\n";
        cout << "1. Insert first product\n";
        cout << "2. Insert last product\n";
        cout << "3. Insert a product in a specific position \n";
        cout << "4. DeleteFirst product \n";
        cout << "5. DeleteLast product \n";
        cout << "6. DeletePosition product \n";
        cout << "7. displayForward product \n";
        cout << "8. displayBackward product \n";
        cout << "9. find product \n";
        cout << "10. modify product \n";
        cout << "11. checkPharmacy \n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 0:
            cout << "Exiting program...\n";
            break;

        case 1:
            cout << "Enter product name: "<< endl;
            cin >> name;
            cout << "Enter product price: "<< endl;
            cin >> price;
            cout << "Enter product quantity: "<< endl;
            cin >> quantity;
            list.InsertFirst(name, price,quantity);
            break;

        case 2:
            cout << "Enter product name: "<< endl;
            cin >> name;
            cout << "Enter product price: "<< endl;
            cin >> price;
            cout << "Enter product quantity: "<< endl;
            cin >> quantity;
            list.InsertLast(name, price,quantity);
            break;

        case 3:
          cout << "Enter position: "<< endl;
            cin >> position;
          cout << "Enter new name: "<< endl;
            cin >> name;
          cout << "Enter new price: "<< endl;
            cin >> price;
          cout << "Enter new quantity: "<< endl;
            cin >> quantity;
            list.insertAtPosition(position , name , price , quantity);
            break;

        case 4:
            list.DeleteFirst();
            break;

        case 5:
            list.DeleteLast();
            break;

        case 6:
            cout << "Enter product position: "<< endl;
            cin >> position;
            list.DeletePosition(position);
            break;

        case 7:
            list.displayForward();
            break;

        case 8:
            list.displayBackward();
            break;

        case 9:
            cout << "Enter name: "<< endl;
            cin >> name;
            index=list.findIndex(name);
            cout<<"location : "<< index <<endl ;
            break;

        case 10:
          cout << "Enter index: "<< endl;
            cin >> index;
          cout << "Enter new name: "<< endl;
            cin >> name;
          cout << "Enter new price: "<< endl;
            cin >> price;
          cout << "Enter new quantity: "<< endl;
            cin >> quantity;
            list.modify(index,name,price,quantity);
            break;

        case 11 :
           list.checkPharmacy();

        default:
            cout << "Invalid choice.\n"<< endl;
            break;
        }

        cout << "\n";
    } while (choice != 0);

    return 0;
}


//Header File was created by Reese Trcalek
#include <iostream>
#include <string>
using namespace std;

//Node that will store book data
struct Book {
    string title = "";
    string author = "";
    bool checkedOutStatus = false;
    string waitlist[5] = {};
    Book* next = nullptr;
    Book(string t, string a, bool status = false, Book* n = nullptr){title = t;author = a;checkedOutStatus = status;next = n;};
};

class Inventory {
    public:
    Inventory();                      // Default Constructor
    ~Inventory();                     // Destructor
    void Append(string t, string a);
    void changeStatus(string t);
    bool getStatus(string t);
    bool foundBook(string t);

    private:
    Book* head;                        // Items are linked to the head
    int size;
};

//Default Constructor for the Linked List
Inventory::Inventory() {
    head=nullptr;
    size=0;
};

void Inventory::Append(string t, string a) {  // Add a value to the end of the list
    Book* newNode= new Book(t, a);
    if(head == nullptr){
       head = newNode;
       size++;
       return;
    }
    Book* current = head;
    while(current->next != nullptr) {
       current = current->next;
    }
    current->next = newNode;
    size++;
 };
 
 //Checks the book into the inventory if checked out and Checks the book out of the inventory if checked in
 void Inventory::changeStatus(string t) {
    Book* current = head;
     for(int i = 0; i < size;i++){
      if(current->title == t){
         if(current->checkedOutStatus == true) {
            current->checkedOutStatus = false;
         }
         else {
            current->checkedOutStatus = true;
         }
      }
      current = current->next;
   }
 };

 //returns the current checked out status of a book
 bool Inventory::getStatus(string t) {
    Book* current = head;
     for(int i = 0; i < size;i++){
      if(current->title == t){
         return current->checkedOutStatus;
      }
      current = current->next;
   }
 };

 bool Inventory::foundBook(string t) {
    Book* current = head;
     for(int i = 0; i < size;i++){
      if(current->title == t){
         return true;
      }
      current = current->next;
   }
   return false;
 };
//This header file was created by Reese Trcalek
#include <iostream>
#include <string>
using namespace std;

//Node that will store account data
struct Node {
    string user = "";
    string pass = "";
    int type = 0;
    string checkedBook = "";
    Node* next = nullptr;
    Node(string u, string p, int t, Node* n = nullptr){user = u;pass = p;type = t;next = n;};
};

class Accounts {
    public:
    Accounts();                      // Default Constructor
    ~Accounts();                     // Destructor
    void Append(string userName, string password, int accountType);
    bool login(string userName, string password);
    void checkOutBook(string userName, string book);
    void checkInBook(string userName, string book);
    int getAccountType(string userName);

    private:
    Node* head;                        // Items are linked to the head
    int size;
};

//Default Constructor for the Linked List
Accounts::Accounts() {
    head=nullptr;
    size=0;
};

Accounts::~Accounts() {

};

//Creates an account and adds them to the linked list
void Accounts::Append(string userName, string password, int accountType) {  // Add a value to the end of the list
    Node* newNode= new Node(userName, password, accountType);
    if(head == nullptr){
       head = newNode;
       size++;
       return;
    }
    Node* current = head;
    while(current->next != nullptr) {
       current = current->next;
    }
    current->next = newNode;
    size++;
 };

 bool Accounts::login(string userName, string password) {
    Node* current = head;
   for(int i = 0; i < size;i++){
      if(current->user == userName){
        if (current->pass == password){
         return true;
        }
        else {
            cout << "Password is incorrect" << endl;
            return false;
        }
      }
      current = current->next;
   }
   return false;
 };

 void Accounts::checkOutBook(string userName, string book) {
    Node* current = head;
    for(int i = 0; i < size;i++){
      if(current->user == userName){
         current->checkedBook = book;
      }
      current = current->next;
   }
 };

 void Accounts::checkInBook(string userName, string book) {
    Node* current = head;
    for(int i = 0; i < size;i++){
      if(current->user == userName){
         current->checkedBook = "";
      }
      current = current->next;
   }
 };

 int Accounts::getAccountType(string userName) {
    Node* current = head;
    for(int i = 0; i < size;i++){
      if(current->user == userName){
         return current->type;
      }
      current = current->next;
   }
   return -1;
 };
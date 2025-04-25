//This file was created by Reese Trcalek
#include <string>
using namespace std;

//Node that will store account data
struct Node {
    string user = "";
    string pass = "";
    int type = 0;
    string checkedBooks[3] = {};
    Node* next = nullptr;
    Node(string u, string p, int t, Node* n = nullptr){user = u;pass = p;type = t;next = n;};
};

class Accounts {
    public:
    Accounts();                      // Default Constructor
    ~Accounts();                     // Destructor
    void Append(string userName, string password, int accountType);


    private:
    Node* head;                        // Items are linked to the head
    int size;
};

//Default Constructor for the Linked List
Accounts::Accounts() {
    head=nullptr;
    size=0;
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
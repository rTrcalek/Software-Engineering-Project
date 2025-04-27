#include "accounts.h"
#include "inventory.h"
using namespace std;

int main() {
    //Reese Trcalek

    //Creates a Linked List to store the inventory
    Inventory inventory;
    //Adds some example books to the list
    inventory.Append("Divine Comedy", "Dante Alighieri");
    inventory.Append("Don Quixote", "Miguel de Cervantes");
    inventory.Append("Paradise Lost", "John Milton");
    
    //Creates a Linked List to store the accounts
    Accounts accounts;
    //Adds some example accounts to the list
    accounts.Append("lib", "lib1234", 0);
    accounts.Append("booksell", "sell1234", 1);
    accounts.Append("borrow", "borrow1234", 2);

    //Ask user to input login
    bool loginCorrect = false;
    string userName = "";
    string password = "";
    while (!loginCorrect) {
        cout << "Input Username" << endl;
        cin >> userName;
        cout << "Input Password" << endl;
        cin >> password;
        //Checks if login is correct
        loginCorrect = accounts.login(userName, password);
    }

    //Check account type to determine what actions to give access to
    int accountType = accounts.getAccountType(userName);
    
    //UI Function Selections
}
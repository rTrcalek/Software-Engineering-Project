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

    if (accountType == 0) // Librarian Account Function
{
    int choice = 0;
    while (choice != 5) 
    {
        cout << "Librarian Menu:" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Check Out Book" << endl;
        cout << "3. Check In Book" << endl;
        cout << "4. View Inventory" << endl;
        cout << "5. Logout" << endl;
        cin >> choice;
        cin.ignore();

    if (choice == 1) 
    {
        string title, author;
        cout << "Enter Book Title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter Book Author: ";
        getline(cin, author);
        inventory.Append(title, author);
        cout << "Book added!" << endl;
    }
    else if (choice == 2) 
    {
        string title;
        cout << "Enter Book Title to Check Out: ";
        cin.ignore();
        getline(cin, title);
        
        if (inventory.foundBook(title)) 
        {
            inventory.changeStatus(title);
            cout << "Book checked out!" << endl;
        }

        else 
        {
            cout << "Book not found." << endl;
        }
    }
    else if (choice == 3) 
    {
        string title;
        cout << "Enter Book Title to Check In: ";
        cin.ignore();
       getline(cin, title);
       
       if (inventory.foundBook(title)) 
       {
            inventory.changeStatus(title);
            cout << "Book checked in!" << endl;
        }

        else 
       {
            cout << "Book not found." << endl;
        }
    }
}
    //UI Function Selections
}

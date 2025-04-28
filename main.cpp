#include "accounts.h"
#include "inventory.h"
using namespace std;

int main() {
    //Reese Trcalek

    //Creates a Linked List to store the inventory
    Inventory inventory;
    //Adds some example books to the list
    inventory.Append("Divine Comedy", "Dante Alighieri", "Poem", "9788804781721");
    inventory.Append("Don Quixote", "Miguel de Cervantes", "Satire", "9788420727943");
    inventory.Append("Paradise Lost", "John Milton", "Poem", "9780023382352");
    
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

    if (accountType == 0) // Librarian Account Function: Written by Bryan Martinez
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
        string title, author, genre, isbn;
        cout << "Enter Book Title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter Book Author: ";
        getline(cin, author);
        cout << "Enter Book Genre: ";
        getline(cin, genre);
        cout << "Enter Book ISBN: ";
        getline(cin, isbn);
        inventory.Append(title, author, genre, isbn);
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


if(accountType == 1) {
    int borrowerChoice = 0;
    
    while (borrowerChoice != 4) {
        cout << "\n        Borrower Menu         \n";
        cout << "1. Borrow a book" << endl;
        cout << "2. return a book" << endl;
        cout << "3. View Borrowed Book" << endl;
        cout << "4. Logout" << endl;
        cout << "\nEnter your choice: ";
        cin >> borrowerChoice;


        string bookName;
        if (borrowerChoice == 1) {
            cout << "Enter book you are borrowing: " << endl;
            cin.ignore();
            getline(cin, bookName);

            if (inventory.foundBook(bookName)) { //finds book availability
                    accounts.checkOutBook(userName, bookName); //book saved to borrowers' account
                    cout << "Book is borrowed" << endl;
                }
            else {
                    cout << "Book isn't found" << endl;
                }

            }

        else if (borrowerChoice == 2) {
                cout << "Returning book..." << endl;
                string recentBook = accounts.checkInBook(userName);

                if (recentBook != "") {
                    inventory.foundBook(userName, recentBook);
                    accounts.checkInBook();
                    cout << "Book returned"<< endl;
                }
        }
        else if (borrowerChoice == 3) {
                cout << "Checked out book: : \n";
                string recentBook = accounts.checkOutBook(userName);

                if (recentBook != "") {
                    cout << "Book borrowed: " << recentBook << endl;
                else {
                cout << "No books borrowed" << endl;
                }

        }
        else if (borrowerChoice != 4) {
            cout << "Error, Try again";

        }
    }
};
    //UI Function Selections
}

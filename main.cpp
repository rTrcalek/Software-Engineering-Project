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
    accounts.Append("booksell", "sell1234", 2);
    accounts.Append("borrow", "borrow1234", 1);

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

        else if (choice == 4)
        {
            inventory.displayInventory();
        }
        else if (choice == 5)
        {
            cout << "Logging out of Account." << endl;
        }

    }    
}

//Borrower Account Function - Karina Sosa
if(accountType == 1) {     // If account type is Borrower, Borrower menu is shown
    int borrowerChoice = 0;
    string bookBorrowed; //tracks borrowed book
    
    while (borrowerChoice != 4) {
        //displays borrower option
        cout << "\n        Borrower Menu         \n";
        cout << "1. Borrow a book" << endl;
        cout << "2. return a book" << endl;
        cout << "3. View Borrowed Book" << endl;
        cout << "4. Logout" << endl;
        cout << "\nEnter your choice: ";
        cin >> borrowerChoice;


       //if borrower choses to borrow a book
        if (borrowerChoice == 1) {
            cout << "Enter book you are borrowing: " << endl;
            cin.ignore();
            string bookName;
            getline(cin, bookName);

            if(inventory.foundBook(bookName)) { //Checks if book exists 
                inventory.changeStatus(bookName); //changes book to borrowed
                accounts.checkOutBook(userName, bookName);
                bookBorrowed = bookName;   //stores borrowed book name
                cout <<bookName<< " is borrowed" << endl;
            }
            else {
                cout <<"Book not found"<<endl;
            }
        }
        //If borrower choses to return a book
        else if (borrowerChoice == 2) {
            cout << "Enter book returning: "<<endl;
            cin.ignore();
            string bookName;
            getline(cin, bookName);

           if(inventory.foundBook(bookName)){ //checks if book exists
            inventory.changeStatus(bookName);
            accounts.checkInBook(userName, bookName);//updates 
            bookBorrowed = "";
            cout <<"Book is returned"<<endl;  
        }
           else{
            cout <<"Book not found "<<endl;
          }
        
     }
    //If borrower choses to view borrowed book
        else if (borrowerChoice == 3) {
                cout << "Checking books borrowed... \n";
                if (bookBorrowed != "") {
                    cout << "Book borrowed: " << bookBorrowed << endl;
                }
                else {
                cout << "No books borrowed" << endl;
                }

        }
    //If choice is logout, it logs out
        else if (borrowerChoice == 4) {
            cout << "Logging out...\n";
        }
        else{
            cout << "Error, Try again\n";
        }

        }
    }


else if (accountType == 2) // Bookseller Account Function: Written by Ronaldo Covarrubias
{
    int choice = 0;
    while (choice != 3)
    {
        // Display Menu for Bookseller
        cout << "Bookseller Menu:" << endl;
        cout << "1. Add Book to Inventory" << endl;
        cout << "2. View Inventory by Title" << endl;
        cout << "3. Logout" << endl;
        cin >> choice;
        cin.ignore();
        
        //Option 1: Add Book to Inventory
        if (choice == 1)
        {
            string title, author, genre, isbn;
            //Title
            cout << "Enter Book Title: ";
            cin.ignore();
            getline(cin, title);
            //Author
            cout << "Enter Book Author: ";
            getline(cin, author);
            //Genre
            cout << "Enter Book Genre: ";
            getline(cin, genre);
            //ISBN
            cout << "Enter Book ISBN: ";
            getline(cin, isbn);
            inventory.Append(title, author, genre, isbn);
            cout << "Book added by bookseller!" << endl;
        }

        //Option 2: View Inventory by Title
        else if (choice == 2)
        {
            string title;
            cout << "Enter Book Title to Search: ";
            getline(cin, title);
            
            //Check if book is in inventory
            if (inventory.foundBook(title))
            {
                cout << "✅ Book found: " << title << endl;
            }
            else
            {
                cout << "❌ Book not found." << endl;
            }
        }
    }
}
};
    //UI Function Selection

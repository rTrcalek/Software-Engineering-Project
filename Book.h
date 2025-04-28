#pragma once
#include <iostream>
using namespace std;

//This class creates and manages books
class Book
{
public:
	string name, genre, author, description;
	int isbn;
	bool ifBorrowed, ifRecommend, ifOverdue, ifWaitlist;
	
	

	// Book Constructor
	Book(string name, string genre, string author, string description, int isbn) {
		this->name = name;
		this->genre = genre;
		this->author = author;
		this->description = description;
		this->isbn = isbn;
		ifBorrowed = false;
		ifRecommend = false;
		ifOverdue = false;
		ifWaitlist = false;
	}


	// function for displaying info
	void displayInfo() {
		cout << "Book: " << name << "\n"
			<< "Author: " << author << "\n"
			<< "Genre: " << genre << "\n"
			<< "ISBN: " << isbn << "\n"
			<< "Description: " << description << "\n";
	}

	// function for displaying title
	void displayTitle(){
		cout << "Book: " << name;
	}

	// function for displaying genre
	void displayGenre() {
		cout << "Genre: " << genre;
	}

	// function for displaying author
	void displayAuthor() {
		cout << "Author: " << author;
	}

	// function for displaying ISBN
	void displayISBN() {
		cout << "ISBN: " << isbn;
	}

	// function for displaying description
	void displayDescription() {
		cout << "Description: " << description;
	}

	// function for editing title
	void editTitle() {
		cin >> name;
	}

	// function for editing author
	void editAuthor() {
		cin >> author;
	}

	// function for editing genre
	void editGenre() {
		cin >> genre;
	}

	// function for editing ISBN
	void editISBN() {
		cin >> isbn;
	}

	// function for editing Description
	void editDscription() {
		cin >> description;
	}

};


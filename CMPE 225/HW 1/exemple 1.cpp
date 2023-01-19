#include <iostream>
using namespace std;
class Author
{
public:
	string name;
};

class Book
{

	string title;
	Author *author;
	string ISBN;
	int edition;

public:
	Book(string title, Author *author, string ISBN, int edition)
	{
		this->title = title;
		this->edition = edition;
		this->ISBN = ISBN;
		this->author = author;
	}
	Book() : ISBN("INVALID"), author(NULL) {}

	bool query_isbn(const std::string &isbn)
	{
		if (isbn == this->ISBN)
		{
			return true;
		}
		else
			return false;
	}
	Book &operator=(const Book &book) //op overloading
	{
		this->edition = book.edition;
		this->ISBN = book.ISBN;
		this->title = book.title;
		this->author = book.author;
		return *this;
	}

	friend ostream &operator<<(ostream &, Book &pt);
};

ostream &operator<<(ostream &o, Book &pt)
{
	o << pt.author->name << "," << pt.title << "," << pt.ISBN << endl;
	return o;
}
/////////////////////////////////////////////////////////////////////////////////////////////
class Library
{
	Book *book;
	int *integer;
	int number_of_books_in;
	int maxbook_ct = 0;

public:
	Library(int number_of_books_in)
	{
		this->number_of_books_in = number_of_books_in;
		this->book = new Book[number_of_books_in];
		this->integer = new int[number_of_books_in];
	}
	~Library()
	{
		delete book;
		delete integer;
	}
	bool add_book(const Book &book)
	{

		this->book[maxbook_ct] = book;

		this->integer[maxbook_ct] = 0; //this-> borrowed  book counter = 0
		maxbook_ct++;				   // total book in library counter

		return true;
	}
	const Book &borrow_book(const string &isbn)
	{
		for (int i = 0; i < maxbook_ct; i++)
		{
			if (book[i].query_isbn(isbn))
			{
				integer[i]++; // if book is available in library add +1 to borrwed counter , its index is same with this->book[] index
				return book[i];
			}
		}
		cout << "ISBN with" << isbn << "does not exsist" << endl
			 << endl;
	}

	Library &operator+=(const Book &book)
	{ //ad book with +=

		this->integer[maxbook_ct] = 0;
		this->book[maxbook_ct] = book;
		maxbook_ct++;
		return *this;
	}
	ostream &write(std::ostream &dest) const
	{
		for (int i = 0; i < this->maxbook_ct; i++)
		{
			cout << this->book[i] << endl;
			cout << "Borrowed: " << this->integer[i] << endl
				 << "======================================================" << endl;
		};
	}
};
std::ostream &operator<<(std::ostream &os, Library const &w)
{ //member ostream overload from stackoverflow
	return w.write(os);
}

int main()
{
	Author mazidi, elmasri, nilsson;
	mazidi.name = "Mazidi";
	elmasri.name = "Elmasri";
	nilsson.name = "Nilsson";
	Book b1("The 8051 Microcontroller & Embedded Systems", &mazidi, "1234-456789123", 2);
	Book b2("Fundamentals of Database Systems", &elmasri, "7899-456456123", 1);
	Book b3("Electric Circuits", &nilsson, "1478-258963258", 3);

	Library obj(3);
	obj.add_book(b1);
	obj.add_book(b2); //add book with function
	//obj.add_book(b3);
	obj += b3; //add book with op overload function

	obj.borrow_book("6584-258963258"); //invalid isbn
	obj.borrow_book("7899-456456123");
	obj.borrow_book("7899-456456123"); //barrow book two times
	obj.borrow_book("1478-258963258");

	std::cout << obj; //list all librarry
	return (0);
}

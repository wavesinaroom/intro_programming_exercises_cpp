#include<iostream>
#include <vector>
#include<stdarg.h>

#include "Book.h"

class Library
{
private:
    const char * name;
    std::vector<Book> book_list;
public:
    Library(/* args */);
    Library(const char * name);
    ~Library();
    void addBook(const char * title, const char * author, const char * publisher, const char * release_date, const char * isbn_number);
    void searchBook(const char * author);
    void showBookInfo(Book book);
    void deleteBook(const char * author);
};

Library::Library(const char * name)
{
    this->name = name;
}

Library::~Library()
{
}

void Library::addBook(const char * title, const char * author, const char * publisher, const char * release_date, const char * isbn_number)
{
    Book book = Book(title, author, publisher, release_date, isbn_number);
    book_list.push_back(book);
}

void Library::searchBook(const char * author)
{
    for (auto &&book : book_list)
    {
        if (book.author == author)
        {
            std::cout<<"Book found!"<<'\n';
            showBookInfo(book);
        }
    }
}

void Library::showBookInfo(Book book)
{
    std::cout<<"Title: "<<book.title<<'\n';
    std::cout<<"Auhtor: "<<book.author<<'\n';
    std::cout<<"Publisher: "<<book.publisher<<'\n';
    std::cout<<"Release date: "<<book.release_date<<'\n';
    std::cout<<"ISBN number: "<<book.isbn_number<<'\n';
}

void Library::deleteBook(const char * author)
{
    for (auto &&book : book_list)
    {
        if (book.author == author)
        {
            book.~Book();
        }
    }
} 
#include<iostream>
#include<vector>
#include<algorithm>
#include "Book.h" 

class Library
{
private:
    const char * name;
    std::vector<Book> book_list;
public:
    Library(/* args */);
    ~Library();
    const char * get_name();
    void setName(const char * name);
    void addBook(const char * title, const char * author, const char * publisher, const char * isbn_number, const char * release_date);
    void showBookInfo(Book book);
    void searchBookByAuthor(const char * author);
    void showBooksInListInfo();
    void deleteBookByAuthor(const char * author);
};

Library::Library(/* args */)
{
}

Library::~Library()
{
}

const char * Library::get_name()
{
    return name;
}

void Library::setName(const char * name)
{
    this->name = name;
}

void Library::addBook(const char * title, const char * author, const char * publisher, const char * isbn_number, const char * release_date)
{
    Book new_book = Book();
    
    new_book.title = title;
    new_book.author = author;
    new_book.publisher = publisher;
    new_book.release_date = release_date;
    new_book.isbn_number = isbn_number;

    book_list.push_back(new_book);
}

void Library::showBookInfo(Book book){
    std::cout<<"-----"<<'\n';
    std::cout<<book.title<<'\n';
    std::cout<<book.author<<'\n';
    std::cout<<book.publisher<<'\n';
    std::cout<<book.release_date<<'\n';
    std::cout<<book.isbn_number<<'\n';
    std::cout<<"-----"<<'\n';
}

void Library::showBooksInListInfo()
{
    for (auto &&book : book_list)
    {   
        showBookInfo(book);        
    }
}

void Library::searchBookByAuthor(const char * author)
{
    for (auto &&book : book_list)
    {
        if (book.author==author)
        {
            showBookInfo(book);
        }
    }
}

void Library::deleteBookByAuthor(const char * author)
{
    for (auto &&book : book_list)
    {
        if(author==book.author)
        {
            book.markedToBeDeleted = true;
            showBookInfo(book);
        }
    }
    book_list.erase(std::remove_if(book_list.begin(), book_list.end(), [](const Book & book){return book.markedToBeDeleted;}), book_list.end());
}


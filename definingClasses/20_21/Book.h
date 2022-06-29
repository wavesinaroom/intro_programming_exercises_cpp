#pragma once;

class Book
{
private:
    const char * title;
    const char * author;
    const char * publisher;
    const char * release_date;
    const char * isbn_number;
public:
    Book(const char * title, const char * author, const char * publisher, const char * release_date, const char * isbn_number);
    ~Book();
    friend class Library;
};

Book::Book(const char * title, const char * author, const char * publisher, const char * release_date, const char * isbn_number)
{
    this->title = title;
    this->author = author;
    this->publisher = publisher;
    this->release_date = release_date;
    this->isbn_number = isbn_number;
}

Book::~Book()
{
}

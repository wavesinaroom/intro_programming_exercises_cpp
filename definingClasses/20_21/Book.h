class Book
{
private:
    const char * title;
    const char * author;
    const char * publisher;
    const char * isbn_number;
    const char * release_date;
    bool markedToBeDeleted;
public:
    Book(/* args */);
    ~Book();
    friend class Library;

};

Book::Book(/* args */)
{
}

Book::~Book()
{
}

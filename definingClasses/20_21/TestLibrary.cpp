#include<iostream>
#include "Library.h"

int main(int argc, char const *argv[])
{
    Library test_library = Library();
    test_library.setName("Ocean of thoughts");

    test_library.addBook("Anything", "Peter", "A publisher", "A number", "A date");
    test_library.addBook("Salem's lost", "Steven King", "SK books", "13215", "10/2004");
    test_library.addBook("Anything", "John", "A publisher", "A number", "A date");
    test_library.addBook("Anything", "Beth", "A publisher", "A number", "A date");
    test_library.addBook("1408", "Steven King", "SK books","456887", "03/2002");
    

    test_library.showBooksInListInfo();    
    std::cout<<"*****"<<'\n';
    test_library.deleteBookByAuthor("Steven King");
    test_library.showBooksInListInfo();
    std::cout<<"*****"<<'\n';
    return 0;
}

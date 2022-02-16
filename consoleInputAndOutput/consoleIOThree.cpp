#include <iostream>

using namespace std;
/* A given company has name, address, phone number, fax number, web site and manager.
The manager has name, surname and phone number. Write a program that read information
about the company and its manager and prints it on the console.
*/
int main(int argc, char const *argv[])
{
    string companyName;
    string companyAddress;
    string companyPhone;
    string companyFax;
    string companyWebsite;
    string companyManager;

    string managerName;
    string managerSurname;
    string managerPhone;

    //Company fields
    cout << "This is gonna be a bit long " << endl;
    cout << " " << endl; 
    cout << "Type name of the company: " << endl;
    cin >> companyName;
    cin.ignore(); 
    cout << "Type the company address:" << endl;
    cin >> companyAddress;
    cout << "Type the company phone:" << endl;
    cin >> companyPhone;
    cout << "Type the company fax:" << endl;
    cin >> companyFax;
    cout << "Type the company Website:" << endl;
    cin >> companyWebsite;
    cout << "Type the company Manager:" << endl;
    cin >> companyManager;
    cout << " " << endl; 
    //Manager fields
    cout << "Almost there, keep going!" << endl;
    cout << " " << endl;  
    cout << "Type the manager name" << endl;
    cin >> managerName;
    cout << "Type the manager surname" << endl;
    cin >> managerSurname;
    cout << "Type the manager phone" << endl;
    cin >> managerPhone;

    //Output
    cout << "Well done! You did it" << endl;
    cout << "" << endl; 
    cout << "Company name: " << companyName << endl;
    cout << "Company Address: " << companyAddress << endl;
    cout << "Company phone: " << companyPhone << endl;
    cout << "Company fax: " << companyFax << endl;
    cout << "Company website: " << companyWebsite << endl;
    cout << "Company manager: " << companyManager << endl;
    cout << " " << endl;
    cout << "Manager name: " << managerName << endl;
    cout << "Manager surname: " << managerSurname << endl;
    cout << "Manager phone: " << managerPhone << endl; 
    cout << "Thanks! Have a lovely day! " << endl; 




    return 0;
}

#include <iostream>
#include <vector>

#include "GSM.h"



int main(int argc, char const *argv[])
{
    std::vector<GSM> gsmTestSubjects {GSM("Redmi Note 11", "Xiaomi"), GSM("Galaxy A03", "Samsung"), GSM("iPhone 7", "Apple")};

    for (auto &&gsm : gsmTestSubjects)
    {
        gsm.printPhoneInfo();
    }

    gsmTestSubjects[0].printNokiaSpecs();
}

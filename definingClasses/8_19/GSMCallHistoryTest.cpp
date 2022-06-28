#include<iostream>
#include"GSM.h"


int main(int argc, char const *argv[])
{

    GSM my_gsm = GSM("Samsung");
    my_gsm.addPhoneCall(10, 20, 11, 2022, 3, 7);
    my_gsm.addPhoneCall(2, 45, 20, 2022, 5, 30);
    my_gsm.addPhoneCall(4, 5, 30, 2022, 6, 15);
    my_gsm.addPhoneCall(8, 52, 56, 2022, 6, 19);
    my_gsm.addPhoneCall(3, 2, 23, 2022, 6, 20);
    my_gsm.printCallHistory();
    my_gsm.calculateBill(0.37); 
    my_gsm.removePhoneCall(3);
    my_gsm.calculateBill(0.37);
    my_gsm.removeAllCalls();
    return 0;
}

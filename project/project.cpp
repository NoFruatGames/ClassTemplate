#include <iostream>
#include "Shop_Counter.h"
int main()
{
    Shop_Counter CPU;
    CPU.setCount(5);
    CPU.setType("CPU");
    CPU.setPrice(1000);
    CPU.setDiscount(50);
    CPU.setName("AMD 4900");

    CPU.showFullInfo();
    std::cout << "\n\n";
    CPU.showShortInfo();
}
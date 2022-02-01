#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Shop_Counter.h"
int main()
{
    Shop_Counter CPU;
    CPU.setType("CPU");
    Shop_Counter Motherboard;
    Motherboard.setType("Motherboard");
    Shop_Counter RAM;
    RAM.setType("RAM");
    Shop_Counter CPU_Cooler;
    CPU_Cooler.setType("CPU_Coller");
    Shop_Counter GPU;
    GPU.setType("GPU");
    Shop_Counter SSD;
    SSD.setType("SSD");
    Shop_Counter HDD;
    HDD.setType("HDD");
    Shop_Counter PC_Case;
    PC_Case.setType("PC_Case");
    Shop_Counter FAN;
    FAN.setType("FAN");
    Shop_Counter PSU;
    PSU.setType("PSU");

    std::vector<Shop_Counter> v = { CPU,Motherboard,RAM,CPU_Cooler,GPU,SSD,HDD,PC_Case,FAN,PSU };
    for (int i = 0; i < v.size(); ++i)
    {
        v[i].showShortInfo();
    }
}
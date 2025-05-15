#pragma once
#include "../include/Doxbase.h"

class studBilet : private Doxbase 
{
private:
    int number;
public:
    studBilet();
    ~studBilet();
    
    int getNumber() const { return number; }
    void setNumber(int x) { number = x; }
    int getYear() const { return Doxbase::getYear(); } // Доступ к унаследованному методу
};
#pragma once
#include "../include/Doxbase.h"

class passport : public Doxbase 
{
private:
    char name;
public:
    passport();
    ~passport();
    
    char getName() const { return name; }
    void setName(char Name) { name = Name;}
};
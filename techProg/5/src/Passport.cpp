#include "../include/Passport.h"
#include <iostream>
#include <cstdlib>

extern char* alphabet; // Объявление внешней переменной

passport::passport() 
{
    setYear(2020 + rand()%6);
    name = alphabet[rand()%26];
    //std::cout << "Passport created\n";
}

passport::~passport() 
{ 
    //std::cout << "Passport deleted\n"; 
}
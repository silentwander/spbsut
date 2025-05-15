#include "../include/Studbilet.h"
#include <iostream>
#include <cstdlib>

studBilet::studBilet() 
{
    setYear(2000 + rand()%25);
    number = (rand() % 1024);
    //std::cout << "StudBilet created\n";
}

studBilet::~studBilet() { 
    //std::cout << "StudBilet deleted\n"; 
}
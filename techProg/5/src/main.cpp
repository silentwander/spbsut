#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../include/Passport.h"
#include "../include/Studbilet.h"
#include "../include/func.h"

int main()
{
    srand(time(0));
    Alphabet();
    
    const int SIZE = 10;
    passport* passports = new passport[SIZE];
    studBilet* studBilets = new studBilet[SIZE];
    
    // Вычисляем показатель (документы, выпущенные в 2024 году)
    for (int i = 0; i < SIZE; ++i)
    {
        CountY(passports[i].getYear());
        std::cout << passports[i].getYear() << " " << passports[i].getName() << "\n";
        
        CountY(studBilets[i].getYear()); // Теперь есть доступ через public метод
        std::cout << studBilets[i].getYear() << " " << studBilets[i].getNumber() << "\n";
    }
    
    std::cout << "Number of documents issued in 2024: " << count << std::endl;
    
    delete[] passports;
    delete[] studBilets;
    delete[] alphabet;
    
    return 0;
}

//g++ main.cpp passport.cpp studbilet.cpp func.cpp -o main
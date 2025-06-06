#include "../include/Passport.h"
#include <iostream>

namespace PassportNamespace {
    int Passport::passport_count = 0;
    
    Passport::Passport(int y, char s) : Doxbase(y), series(s) { 
        passport_count++;
    }
    
    Passport::~Passport() {
        passport_count--;
    }
    
    // Реализация новых методов
    Passport::Passport(const Passport& other) 
        : Doxbase(other), series(other.series) {
        passport_count++;
    }
    
    Passport::Passport(Passport&& other) noexcept 
        : Doxbase(std::move(other)), series(other.series) {
        passport_count++;
    }
    
    Passport& Passport::operator=(const Passport& other) {
        if (this != &other) {
            Doxbase::operator=(other);
            series = other.series;
        }
        return *this;
    }
    
    Passport& Passport::operator=(Passport&& other) noexcept {
        if (this != &other) {
            Doxbase::operator=(std::move(other));
            series = other.series;
        }
        return *this;
    }
    
    void Passport::print_info() const {
        std::cout << "Passport: Series " << series 
                  << ", Year: " << year << std::endl;
    }
}
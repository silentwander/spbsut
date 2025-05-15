#include "../include/Passport.h"

namespace PassportNamespace {
    int Passport::passport_count = 0;
    
    Passport::Passport(int y, char s) : Doxbase(y), series(s) { 
        passport_count++;
    }
    
    Passport::~Passport() {
        passport_count--;
    }
    
    void Passport::print_info() const {
        std::cout << "Passport: Series " << series 
                  << ", Year: " << year << std::endl;
    }
}
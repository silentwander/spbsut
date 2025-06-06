#include "../include/Doxbase.h"

namespace DoxNamespace {
    int Doxbase::total_count = 0;
    
    Doxbase::Doxbase(int y) : year(y) {
        total_count++;
    }
    
    Doxbase::~Doxbase() {
        total_count--;
    }
    
    // Реализация новых методов
    Doxbase::Doxbase(const Doxbase& other) : year(other.year) {
        total_count++;
    }
    
    Doxbase::Doxbase(Doxbase&& other) noexcept : year(other.year) {
        total_count++;
    }
    
    Doxbase& Doxbase::operator=(const Doxbase& other) {
        if (this != &other) {
            year = other.year;
        }
        return *this;
    }
    
    Doxbase& Doxbase::operator=(Doxbase&& other) noexcept {
        if (this != &other) {
            year = other.year;
        }
        return *this;
    }
}
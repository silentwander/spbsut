#include "../include/StudBilet.h"

namespace StudBiletNamespace {
    int StudBilet::studbilet_count = 0;
    
    StudBilet::StudBilet(int y, int num) : Doxbase(y), number(num) {
        studbilet_count++;
    }
    
    StudBilet::~StudBilet() {
        studbilet_count--;
    }
    
    // Реализация новых методов
    StudBilet::StudBilet(const StudBilet& other) 
        : Doxbase(other), number(other.number) {
        studbilet_count++;
    }
    
    StudBilet::StudBilet(StudBilet&& other) noexcept 
        : Doxbase(std::move(other)), number(other.number) {
        studbilet_count++;
    }
    
    StudBilet& StudBilet::operator=(const StudBilet& other) {
        if (this != &other) {
            Doxbase::operator=(other);
            number = other.number;
        }
        return *this;
    }
    
    StudBilet& StudBilet::operator=(StudBilet&& other) noexcept {
        if (this != &other) {
            Doxbase::operator=(std::move(other));
            number = other.number;
        }
        return *this;
    }
}
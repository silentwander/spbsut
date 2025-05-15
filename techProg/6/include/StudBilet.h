#pragma once
#include "Doxbase.h"
#include <cstring>

namespace StudBiletNamespace {
    class StudBilet : private DoxNamespace::Doxbase {
        int number;
        static int studbilet_count;
    public:
        StudBilet(int y, int num);
        ~StudBilet();
        
        void print_info() const override {
            std::cout << "Student Ticket: Year " << get_year() 
                     << ", Number: " << number << std::endl;
        }
        
        int operator[](const char* prop) const {
            if (strcmp(prop, "year") == 0) return get_year();
            if (strcmp(prop, "number") == 0) return number;
            return -1;
        }
        
        static int get_count() { return studbilet_count; }
    };
}
#pragma once
#include "Doxbase.h"

namespace PassportNamespace {
    class Passport : public DoxNamespace::Doxbase {
        char series;
        static int passport_count;
    public:
        Passport(int y, char s);
        ~Passport();
        
        void print_info() const override;
        static int get_count() { return passport_count; }
        
        bool operator==(int target_year) const {
            return year == target_year;
        }
    };
}
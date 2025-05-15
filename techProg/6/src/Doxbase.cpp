#include "../include/Doxbase.h"

namespace DoxNamespace {
    int Doxbase::total_count = 0;
    
    Doxbase::Doxbase(int y) : year(y) {
        total_count++;
    }
    
    Doxbase::~Doxbase() {
        total_count--;
    }
}
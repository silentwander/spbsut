#include "../include/StudBilet.h"

namespace StudBiletNamespace {
    int StudBilet::studbilet_count = 0;
    
    StudBilet::StudBilet(int y, int num) : Doxbase(y), number(num) {
        studbilet_count++;
    }
    
    StudBilet::~StudBilet() {
        studbilet_count--;
    }
}
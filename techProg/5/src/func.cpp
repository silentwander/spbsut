#include "../include/func.h"
#include <cstdlib>

char* alphabet = new char[26];
int count = 0;

void Alphabet()
{ 
    for (int i = 0; i < 26; ++i) 
    {
        alphabet[i] = 'A' + i;
    }
}

void CountY(int x)
{
    if (x == 2024) count++; // Исправлено = на ==
}
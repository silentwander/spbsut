#pragma once
#include <iostream>

namespace DoxNamespace {
    class Doxbase {
    protected:
        int year;
        static int total_count;
    public:
        Doxbase(int y);
        virtual ~Doxbase();
        
        // Добавленные конструкторы и операторы
        Doxbase(const Doxbase& other);
        Doxbase(Doxbase&& other) noexcept;
        Doxbase& operator=(const Doxbase& other);
        Doxbase& operator=(Doxbase&& other) noexcept;
        
        virtual void print_info() const = 0;
        int get_year() const { return year; }
        
        static int get_total_count() { return total_count; }
    };
}
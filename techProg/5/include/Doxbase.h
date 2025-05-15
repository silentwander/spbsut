#pragma once

class Doxbase 
{
private:
    int year;
public:
    void setYear(int x) { year = x;}
    int getYear() const { return year; }
    virtual ~Doxbase() = default;
};
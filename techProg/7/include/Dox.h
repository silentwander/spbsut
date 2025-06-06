#pragma once
#include <string>

class Doxx
{
private:
    std::string type;
    std::string date; // Дата в формате "ГГГГММДД"
public:
    Doxx(const std::string& t, const std::string& d) : type(t), date(d) {}
    std::string getType() const { return type; }
    std::string getDate() const { return date; }
};
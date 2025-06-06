#include "model.h"

// Animal
Animal::Animal(int id_, const std::string& type_, const std::string& gender_, int age_, const std::string& color_, const std::string& place_) : id(id_), type(type_), gender(gender_), age(age_), color(color_), place(place_) {}

int Animal::getId() const { return id; }
std::string Animal::getType() const { return type; }
std::string Animal::getGender() const { return gender; }
int Animal::getAge() const { return age; }
std::string Animal::getColor() const { return color; }
std::string Animal::getPlace() const { return place; }

std::string Animal::getCategory() const { return "Animal"; }

void Animal::print() const {
    std::cout << "ID: " << id << ", Type: " << type << ", Gender: " << gender << ", Age: " << age << ", Color: " << color << ", Place: " << place << std::endl;
}

// Shelter
Shelter::Shelter(int id_, const std::string& type_, const std::string& gender_,
                 const std::string& color_)
    : Animal(id_, type_, gender_, 0, color_, "") {}

std::string Shelter::getCategory() const { return "Shelter"; }

void Shelter::print() const {
    std::cout << "Shelter ID: " << id << ", Type: " << type << ", Gender: " << gender << ", Color: " << color << std::endl;
}

// VetClinic
VetClinic::VetClinic(int id_, const std::string& type_, const std::string& gender_, int age_, const std::string& color_) : Animal(id_, type_, gender_, age_, color_, "") {}

std::string VetClinic::getCategory() const { return "VetClinic"; }

void VetClinic::print() const {
    std::cout << "VetClinic ID: " << id << ", Type: " << type << ", Gender: " << gender << ", Age: " << age << ", Color: " << color << std::endl;
}

// Announcement
Announcement::Announcement(int id_, const std::string& type_, const std::string& gender_,
                           int /*age_*/, const std::string& color_, const std::string& place_)
    : Animal(id_, type_, gender_, 0, color_, place_) {}

std::string Announcement::getCategory() const { return "Announcement"; }

void Announcement::print() const {
    std::cout << "Announcement ID: " << id << ", Type: " << type << ", Gender: " << gender
              << ", Color: " << color << ", Place: " << place << std::endl;
}

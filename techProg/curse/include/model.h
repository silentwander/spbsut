#pragma once
#include <string>
#include <iostream>

class Animal {
protected:
    int id;
    std::string type;
    std::string gender;
    int age;
    std::string color;
    std::string place;

public:
    Animal(int id_, const std::string& type_, const std::string& gender_, int age_,
           const std::string& color_, const std::string& place_);

    virtual ~Animal() = default;

    int getId() const;
    std::string getType() const;
    std::string getGender() const;
    int getAge() const;
    std::string getColor() const;
    std::string getPlace() const;

    virtual std::string getCategory() const;
    virtual void print() const;
};

class Shelter : public Animal {
public:
    Shelter(int id_, const std::string& type_, const std::string& gender_,
            const std::string& color_);

    std::string getCategory() const override;
    void print() const override;
};

class VetClinic : public Animal {
public:
    VetClinic(int id_, const std::string& type_, const std::string& gender_,
              int age_, const std::string& color_);

    std::string getCategory() const override;
    void print() const override;
};

class Announcement : public Animal {
public:
    Announcement(int id_, const std::string& type_, const std::string& gender_,
                 int age_, const std::string& color_, const std::string& place_);

    std::string getCategory() const override;
    void print() const override;
};

#pragma once
#include <vector>
#include <string>
#include <sqlite3.h>
#include "model.h"

class Database {
private:
    sqlite3* db;
    int nextId;

    bool execute(const std::string& sql);

public:
    std::vector<Shelter> shelters;
    std::vector<VetClinic> vetClinics;
    std::vector<Announcement> announcements;

    Database();
    ~Database();

    bool open(const std::string& filename);
    void close();

    int getNextId();

    bool loadData();

    bool addShelter(const std::string& type, const std::string& gender, const std::string& color);
    bool addVetClinic(const std::string& type, const std::string& gender, int age, const std::string& color);
    bool addAnnouncement(const std::string& type, const std::string& gender, int age, const std::string& color, const std::string& place);

    bool clearAllData();
};

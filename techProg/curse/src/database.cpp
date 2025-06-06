#include "database.h"
#include <iostream>

// Конструктор дб.
Database::Database() : db(nullptr), nextId(1) {}

// Деструктор дб.
Database::~Database() {
    close();
}

// Открытие дб.
bool Database::open(const std::string& filename) {
    if (sqlite3_open(filename.c_str(), &db) != SQLITE_OK) {
        std::cerr << "Can't open DB: " << sqlite3_errmsg(db) << std::endl;
        db = nullptr;
        return false;
    }

    // Создание бд. Через Create table if not exists.
    execute("CREATE TABLE IF NOT EXISTS Shelter (id INTEGER PRIMARY KEY, type TEXT, gender TEXT, color TEXT);");
    execute("CREATE TABLE IF NOT EXISTS VetClinic (id INTEGER PRIMARY KEY, type TEXT, gender TEXT, age INTEGER, color TEXT);");
    execute("CREATE TABLE IF NOT EXISTS Announcement (id INTEGER PRIMARY KEY, type TEXT, gender TEXT, color TEXT, place TEXT);");


    return loadData();
}

// Закрытие дб.
void Database::close() {
    if (db) {
        sqlite3_close(db);
        db = nullptr;
    }
}

// Проверка вызова запроса через sqlite3_exec == SQLITE_OK.
bool Database::execute(const std::string& sql) {
    char* errMsg = nullptr;
    int rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << (errMsg ? errMsg : "") << std::endl;
        if (errMsg) sqlite3_free(errMsg);
        return false;
    }
    return true;
}

// Генерация индекса.
int Database::getNextId() {
    return nextId++;
}

// Получить данные для shelter из дб.
static int loadShelterCallback(void* data, int argc, char** argv, char** azColName) {
    auto* shelters = reinterpret_cast<std::vector<Shelter>*>(data);
    int id = 0;
    std::string type, gender, color;

    for (int i = 0; i < argc; ++i) {
        std::string col = azColName[i];
        std::string val = argv[i] ? argv[i] : "";
        if (col == "id") id = std::stoi(val);
        else if (col == "type") type = val;
        else if (col == "gender") gender = val;
        else if (col == "color") color = val;
    }
    shelters->emplace_back(id, type, gender, color);
    return 0;
}

// Получить данные для vetcliniccallback из дб.
static int loadVetClinicCallback(void* data, int argc, char** argv, char** azColName) {
    auto* vetClinics = reinterpret_cast<std::vector<VetClinic>*>(data);
    int id = 0, age = 0;
    std::string type, gender, color;

    for (int i = 0; i < argc; ++i) {
        std::string col = azColName[i];
        std::string val = argv[i] ? argv[i] : "";
        if (col == "id") id = std::stoi(val);
        else if (col == "type") type = val;
        else if (col == "gender") gender = val;
        else if (col == "age") age = std::stoi(val);
        else if (col == "color") color = val;
    }
    vetClinics->emplace_back(id, type, gender, age, color);
    return 0;
}

// Получить данные для Announcement из дб.
static int loadAnnouncementCallback(void* data, int argc, char** argv, char** azColName) {
    auto* announcements = reinterpret_cast<std::vector<Announcement>*>(data);
    int id = 0;
    std::string type, gender, color, place;

    for (int i = 0; i < argc; ++i) {
        std::string col = azColName[i];
        std::string val = argv[i] ? argv[i] : "";
        if (col == "id") id = std::stoi(val);
        else if (col == "type") type = val;
        else if (col == "gender") gender = val;
        else if (col == "color") color = val;
        else if (col == "place") place = val;
    }
    announcements->emplace_back(id, type, gender, 0, color, place);
    return 0;
}

// Проверка актуальности бд и вектора. 
bool Database::loadData() {
    shelters.clear();
    vetClinics.clear();
    announcements.clear();

    char* errMsg = nullptr;

    int rc = sqlite3_exec(db, "SELECT * FROM Shelter;", loadShelterCallback, &shelters, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to load Shelter: " << (errMsg ? errMsg : "") << std::endl;
        if (errMsg) sqlite3_free(errMsg);
        return false;
    }

    rc = sqlite3_exec(db, "SELECT * FROM VetClinic;", loadVetClinicCallback, &vetClinics, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to load VetClinic: " << (errMsg ? errMsg : "") << std::endl;
        if (errMsg) sqlite3_free(errMsg);
        return false;
    }

    rc = sqlite3_exec(db, "SELECT * FROM Announcement;", loadAnnouncementCallback, &announcements, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to load Announcement: " << (errMsg ? errMsg : "") << std::endl;
        if (errMsg) sqlite3_free(errMsg);
        return false;
    }

    int maxId = 0;
    for (const auto& s : shelters) if (s.getId() > maxId) maxId = s.getId();
    for (const auto& v : vetClinics) if (v.getId() > maxId) maxId = v.getId();
    for (const auto& a : announcements) if (a.getId() > maxId) maxId = a.getId();

    nextId = maxId + 1;

    return true;
}

// Функции для сохранения данных в память.
bool Database::addShelter(const std::string& type, const std::string& gender, const std::string& color) {
    int id = getNextId();
    Shelter s(id, type, gender, color);
    std::string sql = "INSERT INTO Shelter (id, type, gender, color) VALUES (" +
                      std::to_string(id) + ", '" + type + "', '" + gender + "', '" + color + "');";
    if (!execute(sql)) return false;
    shelters.push_back(s);
    return true;
}

bool Database::addVetClinic(const std::string& type, const std::string& gender, int age, const std::string& color) {
    int id = getNextId();
    VetClinic v(id, type, gender, age, color);
    std::string sql = "INSERT INTO VetClinic (id, type, gender, age, color) VALUES (" +
                      std::to_string(id) + ", '" + type + "', '" + gender + "', " + std::to_string(age) + ", '" + color + "');";
    if (!execute(sql)) return false;
    vetClinics.push_back(v);
    return true;
}

bool Database::addAnnouncement(const std::string& type, const std::string& gender, int /*age*/, const std::string& color, const std::string& place) {
    int id = getNextId();
    Announcement a(id, type, gender, 0, color, place);
    std::string sql = "INSERT INTO Announcement (id, type, gender, color, place) VALUES (" +
                      std::to_string(id) + ", '" + type + "', '" + gender + "', '" + color + "', '" + place + "');";
    if (!execute(sql)) return false;
    announcements.push_back(a);
    return true;
}

// очистка дб.
bool Database::clearAllData() {
    bool ok = true;
    ok &= execute("DELETE FROM Shelter;");
    ok &= execute("DELETE FROM VetClinic;");
    ok &= execute("DELETE FROM Announcement;");
    ok &= execute("VACUUM;");

    if (ok) {
        shelters.clear();
        vetClinics.clear();
        announcements.clear();
    }
    return ok;
}

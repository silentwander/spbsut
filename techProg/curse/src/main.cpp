#include <iostream>
#include <limits>
#include "model.h"
#include "database.h"
#include "search.h"

// Функция для удобного ввода подсказок.
std::string inputString(const std::string& prompt, const std::string& hint = "") {
    std::string input;
    while (true) {
        std::cout << prompt;
        if (!hint.empty()) std::cout << " (" << hint << ")";
        std::cout << ": ";
        std::getline(std::cin, input);
        if (!input.empty()) break; // Проверка ну пустую строку.
        std::cout << "Input cannot be empty. Please try again.\n";
    }
    return input;
}

// Функция для ввода числового значения.
int inputInt(const std::string& prompt, const std::string& hint = "") {
    int value;
    while (true) {
        std::cout << prompt;
        if (!hint.empty()) std::cout << " (" << hint << ")";
        std::cout << ": ";
        std::cin >> value;
        if (!std::cin.fail() && value >= 0) { // Проверка на корректность ввода + неотрецательность.
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
        std::cout << "Invalid number. Please enter a non-negative integer.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return value;
}

// Функция для вывода меню.
void printMenu() {
    std::cout << "\n--- Menu ---\n";
    std::cout << "1. Add Shelter record\n";
    std::cout << "2. Add VetClinic record\n";
    std::cout << "3. Add Announcement record\n";
    std::cout << "4. Search lost animal\n";
    std::cout << "5. Exit\n";
    std::cout << "Choose option (1-5): ";
}

int main() {
    Database db;
    // Проверка успешного открытия бд.
    if (!db.open("database.db")) {
        std::cerr << "Failed to open database.\n";
        return 1;
    }

    int choice = 0;
    do {
        printMenu();
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // Реализация меню.
        switch (choice) {
            case 1: { // Приют.
                std::string type = inputString("Type", "e.g. dog, cat");
                std::string gender = inputString("Gender", "M or F");
                std::string color = inputString("Color");
                if (db.addShelter(type, gender, color))
                    std::cout << "Shelter record added.\n";
                else
                    std::cout << "Failed to add Shelter record.\n";
                break;
            }
            case 2: { // Ветклиника.
                std::string type = inputString("Type", "e.g. dog, cat");
                std::string gender = inputString("Gender", "M or F");
                int age = inputInt("Age", "integer");
                std::string color = inputString("Color");
                if (db.addVetClinic(type, gender, age, color))
                    std::cout << "VetClinic record added.\n";
                else
                    std::cout << "Failed to add VetClinic record.\n";
                break;
            }
            case 3: { // Объявление.
                std::string type = inputString("Type", "e.g. dog, cat");
                std::string gender = inputString("Gender", "M or F");
                int age = inputInt("Age", "integer");
                std::string color = inputString("Color");
                std::string place = inputString("Place");
                if (db.addAnnouncement(type, gender, age, color, place))
                    std::cout << "Announcement record added.\n";
                else
                    std::cout << "Failed to add Announcement record.\n";
                break;
            }
            case 4: { // Поиск и сравнение.
                std::string type = inputString("Type", "e.g. dog, cat");
                std::string gender = inputString("Gender", "M or F");
                int age = inputInt("Age", "integer");
                std::string color = inputString("Color");
                std::string place = inputString("Place");

                // Внешная запись, чтобы не пресекалась с базой данных.
                Animal lost(-1, type, gender, age, color, place);
                auto results = search(lost, db.shelters, db.vetClinics, db.announcements);

                if (results.empty()) {
                    std::cout << "No records found.\n";
                } else { // вывод 10 больше всего подходящих.
                    std::cout << "\nSearch results (top 10):\n";
                    int count = (results.size() > 10) ? 10 : (int)results.size();
                    for (int i = 0; i < count; ++i) {
                        const auto& r = results[i];
                        std::cout << i + 1 << ". [" << r.category << "] ID: " << r.id
                                  << ", Similarity: " << r.similarity << "%, " << r.summary << std::endl;
                    }
                }
                break;
            }
            case 5: // Выход.
                std::cout << "Goodbye!\n";
                break;
            case 6: { // Скрытая функция очистки базы данных.
                if (db.clearAllData())
                    std::cout << "Database cleared successfully.\n";
                else
                    std::cout << "Failed to clear database.\n";
                break;
            }
            default:
                std::cout << "Invalid option. Please try again.\n";
        }
    } while (choice != 5);
    
    db.close();
    return 0;
}
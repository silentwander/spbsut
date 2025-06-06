#include "../include/Doxbase.h"
#include "../include/Passport.h"
#include "../include/StudBilet.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace DoxNamespace;
using namespace PassportNamespace;
using namespace StudBiletNamespace;


std::vector<Passport> passports1;
std::vector<Passport> passports2;


int count_documents_by_year(const std::vector<Passport>& vec, int year) {
    return std::count_if(vec.begin(), vec.end(), 
        [year](const Passport& p) { return p.get_year() == year; });
}


void print_first_n(const std::vector<Passport>& vec, size_t n) {
    for (size_t i = 0; i < n && i < vec.size(); ++i) {
        vec[i].print_info();
    }
}

int main() {
    srand(time(0));
    int choice = 0;
    int target_year = 2024;

    while (choice != 7) {
        std::cout << "\n=== Data Processing Menu ===";
        std::cout << "\n1. Create first vector (1000 objects)";
        std::cout << "\n2. Create second vector (reverse of first)";
        std::cout << "\n3. Calculate documents for " << target_year;
        std::cout << "\n4. Add 500 elements in the middle";
        std::cout << "\n5. Sort by issue year";
        std::cout << "\n6. Clear all vectors";
        std::cout << "\n7. Exit";
        std::cout << "\nSelect operation: ";
        std::cin >> choice;

        system("cls");

        switch (choice) {
            case 1: { // Create first vector
                passports1.clear();
                for (int i = 0; i < 1000; ++i) {
                    int year = 2020 + rand() % 5; // 2020-2024
                    char series = 'A' + rand() % 26;
                    passports1.emplace_back(year, series);
                }
                std::cout << "Vector 1 created: " << passports1.size() << " elements\n";
                break;
            }
            case 2: { // Create reversed vector
                if (passports1.empty()) {
                    std::cout << "Error: Create first vector first!\n";
                    break;
                }
                passports2 = std::vector<Passport>(
                    passports1.rbegin(), passports1.rend());
                std::cout << "Vector 2 (reversed) created: " << passports2.size() << " elements\n";
                std::cout << "Total documents: " << Doxbase::get_total_count() << "\n";
                break;
            }
            case 3: { // Calculate documents
                if (passports1.empty() || passports2.empty()) {
                    std::cout << "Error: Vectors not created!\n";
                    break;
                }
                int count1 = count_documents_by_year(passports1, target_year);
                int count2 = count_documents_by_year(passports2, target_year);
                std::cout << "Vector 1: " << count1 << " documents from " << target_year << "\n";
                std::cout << "Vector 2: " << count2 << " documents from " << target_year << "\n";
                break;
            }
            case 4: { // Add elements
                if (passports1.empty()) {
                    std::cout << "Error: Create first vector first!\n";
                    break;
                }
                auto it = passports1.begin() + passports1.size() / 2;
                passports1.insert(it, 500, Passport(target_year, 'X'));
                std::cout << "500 elements added. New size: " << passports1.size() << "\n";
                std::cout << "Documents from " << target_year << ": " 
                          << count_documents_by_year(passports1, target_year) << "\n";
                break;
            }
            case 5: { // Sort
                if (passports1.empty()) {
                    std::cout << "Error: Vector is empty!\n";
                    break;
                }
                std::sort(passports1.begin(), passports1.end(),
                    [](const Passport& a, const Passport& b) {
                        return a.get_year() < b.get_year();
                    });
                std::cout << "Sorted. First 10 elements:\n";
                print_first_n(passports1, 10);
                break;
            }
            case 6: { // Clear
                passports1.clear();
                passports2.clear();
                std::cout << "Vectors cleared. Sizes: " 
                          << passports1.size() << " and " << passports2.size() << "\n";
                std::cout << "Total documents: " << Doxbase::get_total_count() << "\n";
                break;
            }
            case 7: // Exit
                return 0;
            default:
                std::cout << "Invalid selection!\n";
        }
    }
}
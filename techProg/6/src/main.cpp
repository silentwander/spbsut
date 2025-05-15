#include <iostream>
#include <vector>
#include <limits>
#include "../include/Doxbase.h"
#include "../include/Passport.h"
#include "../include/StudBilet.h"

using namespace DoxNamespace;
using namespace PassportNamespace;
using namespace StudBiletNamespace;

void show_menu() {
    std::vector<Passport> passports;
    std::vector<StudBilet> stud_bilets;
    int choice;

    while(choice != 6) {
        std::cout << "\n=== Document Manager ===\n"
                  << "1. Add New Passport\n"
                  << "2. Add Student Ticket\n"
                  << "3. List All Documents\n"
                  << "4. Search by Year\n"
                  << "5. Statistics\n"
                  << "6. Exit\n"
                  << "Select option: ";
        std::cin >> choice;
        system("cls");
        switch(choice) {
            case 1: {
                int y; char s;
                std::cout << "Enter issue year: ";
                std::cin >> y;
                std::cout << "Enter passport series: ";
                std::cin >> s;
                passports.emplace_back(y, s);
                break;
            }
            case 2: {
                int y, num;
                std::cout << "Enter issue year: ";
                std::cin >> y;
                std::cout << "Enter ticket number: ";
                std::cin >> num;
                stud_bilets.emplace_back(y, num);
                break;
            }
            case 3: {
                std::cout << "\n--- Passports ---\n";
                for(const auto& p : passports) p.print_info();
                
                std::cout << "\n--- Student Tickets ---\n";
                for(const auto& s : stud_bilets) s.print_info();
                break;
            }
            case 4: {
                std::cout << "Enter target year: ";
                int year;
                std::cin >> year;
                int count = 0;
                
                for(const auto& p : passports) {
                    if(p == year) count++;
                }
                
                for(const auto& s : stud_bilets) {
                    if(s["year"] == year) count++;
                }
                
                std::cout << "Found " << count << " documents for year " << year << std::endl;
                break;
            }
            case 5: {
                std::cout << "\n=== Statistics ===\n"
                          << "Total documents: " << Doxbase::get_total_count() << "\n"
                          << "Passports: " << Passport::get_count() << "\n"
                          << "Student Tickets: " << StudBilet::get_count() << "\n";
                break;
            }
            case 6:
                return;
            default:
                std::cout << "Invalid option!\n";
        }
    }
}

int main() {
    show_menu();
    return 0;
}
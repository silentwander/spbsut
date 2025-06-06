#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include "../include/DoxTemplate.h"
#include "../include/Dox.h"

int main() {
    // Создание процессора для документов
    DoxxTemplate<Doxx> processor;

    // Добавление документов
    processor.addDocument(Doxx("Contract", "20220101"));
    processor.addDocument(Doxx("Invoice", "20230101"));
    processor.addDocument(Doxx("Report", "20210115"));
    processor.addDocument(Doxx("Invoice", "20230520"));
    processor.addDocument(Doxx("Contract", "20221231"));

    // Показатель 1: Самый ранний документ
    try {
        Doxx earliest = processor.getEarliestDocument();
        std::cout << "Earliest document: Type = " << earliest.getType() 
                  << ", Date = " << earliest.getDate() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Показатель 2: Количество документов типа "Invoice"
    int invoiceCount = processor.countByType("Invoice");
    std::cout << "Number of Invoices: " << invoiceCount << std::endl;

    return 0;
}
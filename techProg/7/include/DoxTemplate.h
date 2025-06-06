#pragma once
#include <vector>
#include <stdexcept>
#include <string>

template <class T>
class DoxxTemplate {
private:
    std::vector<T> docs; // Используем обобщенный тип T
public:
    // Добавление документа
    void addDocument(const T& doc) {
        docs.push_back(doc);
    }

    // Поиск документа с самой ранней датой
    T getEarliestDocument() const {
        if (docs.empty()) {
            throw std::logic_error("No documents to process.");
        }
        T earliest = docs[0];
        for (const auto& doc : docs) {
            if (doc.getDate() < earliest.getDate()) {
                earliest = doc;
            }
        }
        return earliest;
    }

    // Подсчёт документов определённого типа
    int countByType(const std::string& targetType) const {
        int count = 0;
        for (const auto& doc : docs) {
            if (doc.getType() == targetType) {
                count++;
            }
        }
        return count;
    }
};
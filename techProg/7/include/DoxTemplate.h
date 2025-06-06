#pragma once
template <class T> 
class DoxxTemplate
{
private:
    vector<DocType> docs; 
public:
    // Добавление документа
    void addDocument(const DocType& doc) {
        docs.push_back(doc);
    }

    // Поиск документа с самой ранней датой
    DocType getEarliestDocument() const {
        if (docs.empty()) {
            throw logic_error("No documents to process.");
        }
        DocType earliest = docs[0];
        for (const auto& doc : docs) {
            if (doc.getDate() < earliest.getDate()) {
                earliest = doc;
            }
        }
        return earliest;
    }

    // Подсчёт документов определённого типа
    int countByType(const string& targetType) const {
        int count = 0;
        for (const auto& doc : docs) {
            if (doc.getType() == targetType) {
                count++;
            }
        }
        return count;
    }
};
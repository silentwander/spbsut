#include "search.h"
#include <algorithm>

double similarity(const Animal& lost, const Animal& record) {
    int matches = 0;
    int total = 0;

    // type - всегда есть
    total++;
    if (lost.getType() == record.getType())
        matches++;

    // gender - всегда есть
    total++;
    if (lost.getGender() == record.getGender())
        matches++;

    // age - учитываем только если record имеет возраст > 0
    if (record.getAge() > 0) {
        total++;
        if (lost.getAge() == record.getAge())
            matches++;
    }

    // color - всегда есть
    total++;
    if (lost.getColor() == record.getColor())
        matches++;

    // place - учитываем только если record.getPlace() не пустое
    if (!record.getPlace().empty()) {
        total++;
        if (lost.getPlace() == record.getPlace())
            matches++;
    }

    if (total == 0)
        return 0.0;

    return (matches * 100.0) / total;
}

std::vector<SearchResult> search(const Animal& lost,
                                 const std::vector<Shelter>& shelters,
                                 const std::vector<VetClinic>& vetClinics,
                                 const std::vector<Announcement>& announcements) {
    std::vector<SearchResult> results;

    // Обработка Shelter
    for (const auto& s : shelters) {
        Animal temp(s.getId(), s.getType(), s.getGender(), 0, s.getColor(), "");
        double sim = similarity(lost, temp);
        results.push_back({
            s.getCategory(),
            s.getId(),
            sim,
            "Type: " + s.getType() + ", Gender: " + s.getGender() + ", Color: " + s.getColor()
        });
    }

    // Обработка VetClinic
    for (const auto& v : vetClinics) {
        Animal temp(v.getId(), v.getType(), v.getGender(), v.getAge(), v.getColor(), "");
        double sim = similarity(lost, temp);
        results.push_back({
            v.getCategory(),
            v.getId(),
            sim,
            "Type: " + v.getType() + ", Gender: " + v.getGender() + ", Age: " + std::to_string(v.getAge()) + ", Color: " + v.getColor()
        });
    }

    // Обработка Announcement
    for (const auto& a : announcements) {
        double sim = similarity(lost, a);
        results.push_back({
            a.getCategory(),
            a.getId(),
            sim,
            "Type: " + a.getType() + ", Gender: " + a.getGender() + ", Age: " + std::to_string(a.getAge()) + 
            ", Color: " + a.getColor() + ", Place: " + a.getPlace()
        });
    }

    // Сортировка результатов по убыванию сходства
    std::sort(results.begin(), results.end(), [](const SearchResult& a, const SearchResult& b) {
        return a.similarity > b.similarity;
    });

    return results;
}

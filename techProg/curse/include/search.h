#pragma once
#include <vector>
#include "model.h"

struct SearchResult {
    std::string category;
    int id;
    double similarity;
    std::string summary;
};

double similarity(const Animal& lost, const Animal& record);

std::vector<SearchResult> search(const Animal& lost,
                                 const std::vector<Shelter>& shelters,
                                 const std::vector<VetClinic>& vetClinics,
                                 const std::vector<Announcement>& announcements);

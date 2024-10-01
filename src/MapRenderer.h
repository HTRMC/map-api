#pragma once
#include <string>

class MapRenderer {
public:
    void renderMap(double lat, double lon, const std::string& label);
};
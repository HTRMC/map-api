#include "MapRenderer.h"
#include <fstream>
#include <sstream>
#include <iostream>

void MapRenderer::renderMap(double lat, double lon, const std::string& label) {
    std::stringstream ss;
    ss << R"(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Map of )" << label << R"(</title>
    <link rel="stylesheet" href="https://unpkg.com/leaflet@1.7.1/dist/leaflet.css"/>
    <script src="https://unpkg.com/leaflet@1.7.1/dist/leaflet.js"></script>
    <style>
        #map { height: 400px; width: 100%; }
    </style>
</head>
<body>
    <div id="map"></div>
    <script>
        var map = L.map('map').setView([)" << lat << ", " << lon << R"(], 13);
        L.tileLayer('https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png', {
            attribution: '&copy; <a href="https://www.openstreetmap.org/copyright">OpenStreetMap</a> contributors'
        }).addTo(map);
        L.marker([)" << lat << ", " << lon << R"(]).addTo(map)
            .bindPopup(')" << label << R"(')
            .openPopup();
    </script>
</body>
</html>
    )";

    std::ofstream out("map.html");
    out << ss.str();
    out.close();

    std::cout << "Map has been rendered to 'map.html'. Please open this file in a web browser." << std::endl;
}
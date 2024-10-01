#include <iostream>
#include <string>
#include <curl/curl.h>
#include <nlohmann/json.hpp>
#include "MapRenderer.h"

using json = nlohmann::json;

size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t totalSize = size * nmemb;
    output->append((char*)contents, totalSize);
    return totalSize;
}

double parseDouble(const json& j, const std::string& key) {
    if (j[key].is_number()) {
        return j[key].get<double>();
    } else if (j[key].is_string()) {
        return std::stod(j[key].get<std::string>());
    } else {
        throw std::runtime_error("Invalid type for " + key);
    }
}

int main() {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://nominatim.openstreetmap.org/search?format=json&q=Roermond");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        // Voeg een user-agent toe om te voldoen aan de Nominatim Usage Policy
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "RoermondMapProject/1.0");

        res = curl_easy_perform(curl);

        if(res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        } else {
            try {
                json j = json::parse(readBuffer);
                if (!j.empty() && j.is_array() && j[0].contains("lat") && j[0].contains("lon")) {
                    double lat = parseDouble(j[0], "lat");
                    double lon = parseDouble(j[0], "lon");

                    std::cout << "Latitude: " << lat << ", Longitude: " << lon << std::endl;

                    MapRenderer renderer;
                    renderer.renderMap(lat, lon, "Roermond");
                } else {
                    std::cerr << "Unexpected JSON structure or empty response" << std::endl;
                }
            } catch (const json::parse_error& e) {
                std::cerr << "JSON parsing error: " << e.what() << std::endl;
            } catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    return 0;
}
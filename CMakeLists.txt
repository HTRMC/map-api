cmake_minimum_required(VERSION 3.15)
project(RoermondMapProject)

set(CMAKE_CXX_STANDARD 17)

# Specificeer de paden voor curl
set(CURL_INCLUDE_DIR "C:/dev/CURL/curl-8.10.1/x64 Release/include")
set(CURL_LIBRARY "C:/dev/CURL/curl-8.10.1/x64 Release/lib/libcurl_a.lib")

# Zoek curl package
find_package(CURL REQUIRED)

# Gebruik FetchContent voor nlohmann/json
include(FetchContent)
FetchContent_Declare(
        json
        URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz
)
FetchContent_MakeAvailable(json)

# Voeg executable toe
add_executable(RoermondMapProject
        src/main.cpp
        src/MapRenderer.cpp
)

# Include directories
target_include_directories(RoermondMapProject PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CURL_INCLUDE_DIR}
)

# Link libraries
target_link_libraries(RoermondMapProject PRIVATE
        ${CURL_LIBRARY}
        nlohmann_json::nlohmann_json
)

# Voeg Windows-specifieke libraries toe
if(WIN32)
    target_link_libraries(RoermondMapProject PRIVATE
            wsock32 ws2_32 crypt32 wldap32 normaliz
    )
endif()

# Voeg deze definitie toe als je de statische curl library gebruikt
add_definitions(-DCURL_STATICLIB)

# Voeg deze compiler flag toe om conflicten met runtime libraries te voorkomen
if(MSVC)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /NODEFAULTLIB:LIBCMT")
endif()
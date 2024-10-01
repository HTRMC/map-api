# RoermondMapProject

This project demonstrates how to use the OpenStreetMap Nominatim API to fetch geographical coordinates for Roermond and display them on an interactive map using Leaflet.

## Prerequisites

Before you begin, ensure you have met the following requirements:

* You have a Windows machine
* You have installed [CMake](https://cmake.org/download/) (3.15 or higher)
* You have installed [Visual Studio](https://visualstudio.microsoft.com/downloads/) with C++ support
* You have installed [CLion](https://www.jetbrains.com/clion/download/) (optional, but recommended)
* You have a modern web browser to view the generated map

## Dependencies

This project uses the following external libraries:

* libcurl (for HTTP requests)
* nlohmann/json (for JSON parsing)

Make sure you have these libraries installed and properly set up on your system.

## Building the Project

1. Clone this repository:

```git clone https://github.com/yourusername/RoermondMapProject.git```
```cd RoermondMapProject```

2. Open the project in CLion.

3. CLion should automatically detect the CMakeLists.txt file and set up the project. If not, you may need to reload the CMake project (Tools -> CMake -> Reload CMake Project).

4. Build the project by clicking on the Build button or pressing Ctrl+F9.

## Running the Program

After building, you can run the program directly from CLion by clicking the Run button or pressing Shift+F10.

Alternatively, you can run the executable from the command line:
```.\cmake-build-release\RoermondMapProject.exe```

The program will fetch the coordinates for Roermond and generate an HTML file named `map.html` in the same directory as the executable.

## Viewing the Map

Open the generated `map.html` file in your web browser to view the interactive map showing the location of Roermond.

## Project Structure

- `src/main.cpp`: Contains the main program logic, including the API request and JSON parsing.
- `src/MapRenderer.cpp`: Implements the map rendering functionality.
- `include/MapRenderer.h`: Header file for the MapRenderer class.
- `CMakeLists.txt`: CMake configuration file for building the project.

## Troubleshooting

- Ensure that the paths to libcurl and nlohmann/json in CMakeLists.txt are correct for your system.
- Make sure you have an active internet connection when running the program and viewing the map.
- If the program fails to write the HTML file, check if it has write permissions in the current directory.

## License

This project uses the following license: [MIT](https://opensource.org/licenses/MIT).

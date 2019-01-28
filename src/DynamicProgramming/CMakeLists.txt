file(GLOB dp_sources *.cpp **/*.cpp **/**/*.cpp)
add_library(libDP OBJECT
        ${dp_sources})
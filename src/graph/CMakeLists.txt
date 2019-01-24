file(GLOB graph_sources *.cpp **/*.cpp **/**/*.cpp)
add_library(libGraph OBJECT
        ${graph_sources})
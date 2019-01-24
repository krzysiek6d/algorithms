file(GLOB sorting_sources *.cpp **/*.cpp **/**/*.cpp)
add_library(libSorting OBJECT
        ${sorting_sources})
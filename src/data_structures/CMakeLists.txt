file(GLOB data_structures_sources *.cpp **/*.cpp **/**/*.cpp)
add_library(lib_data_structures OBJECT
        ${data_structures_sources})
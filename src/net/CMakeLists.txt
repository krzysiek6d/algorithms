file(GLOB net_sources *.cpp **/*.cpp **/**/*.cpp)
add_library(libnet OBJECT
        ${net_sources})
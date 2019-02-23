add_subdirectory(graph)
add_subdirectory(net)
add_subdirectory(DynamicProgramming)
add_subdirectory(data_structures)

add_library(libAlgorithmMain OBJECT
        main.cpp
        )
find_package(Threads)

set(algorithms_sources
        $<TARGET_OBJECTS:libAlgorithmMain>
#        $<TARGET_OBJECTS:libGraph>
        games/sudoku.hpp)

add_executable(${PROJECT_NAME} ${algorithms_sources})
target_link_libraries(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})

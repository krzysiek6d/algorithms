add_subdirectory(graph)
add_subdirectory(sorting)

add_library(libAlgorithmMain OBJECT
        main.cpp
        )
find_package(Threads)

set(algorithms_sources
        $<TARGET_OBJECTS:libAlgorithmMain>
        $<TARGET_OBJECTS:libGraph>
        )

add_executable(${PROJECT_NAME} ${algorithms_sources})
target_link_libraries(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})

set(test_name MiscTests)

file(GLOB test_sources *.cpp **/*.cpp **/**/*.cpp)

add_executable(${test_name}
        $<TARGET_OBJECTS:gtest>
        ${test_sources})

target_link_libraries(
        ${test_name}
        ${CMAKE_THREAD_LIBS_INIT}
)

add_dependencies(
        ut
        ${test_name}
)

add_test(
        NAME ${test_name}
        COMMAND ${test_name}
)

set_tests_properties(${test_name} PROPERTIES LABELS UT)

cmake_minimum_required(VERSION 3.16)

project(starshipgen LANGUAGES CXX)

if(POLICY CMP0167)
    cmake_policy(SET CMP0167 NEW)
endif()

find_package(Boost REQUIRED)

add_executable(starshipgen
    civilisation.cpp
    civilisation_describe.cpp
    component.cpp
    componentlist.cpp
    componenttype.cpp
    dependency.cpp
    main.cpp
    randomgen.cpp
    starship.cpp
    starship_describe.cpp
)

target_compile_features(starshipgen PRIVATE cxx_std_11)
target_link_libraries(starshipgen PRIVATE Boost::headers)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(starshipgen PRIVATE -Wall)
endif()

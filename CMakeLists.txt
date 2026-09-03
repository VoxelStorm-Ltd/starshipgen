cmake_minimum_required(VERSION 3.20)

project(starshipgen LANGUAGES CXX)

if(POLICY CMP0167)
  cmake_policy(SET CMP0167 NEW)
endif()

find_package(Boost REQUIRED COMPONENTS program_options)

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

target_compile_features(starshipgen PRIVATE cxx_std_23)
target_link_libraries(starshipgen PRIVATE Boost::program_options)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
  target_compile_options(starshipgen PRIVATE -Wall)
endif()

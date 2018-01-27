cmake_minimum_required(VERSION 2.6)
project (spells)

# pkg-config-based library
include(FindPkgConfig)
pkg_check_modules(criterion REQUIRED criterion>=2.3.2)
if(criterion_FOUND)
	include_directories(${criterion_INCLUDE_DIRS})
	link_directories(${criterion_LIBRARY_DIRS})
endif()
add_executable(spells_tests
	src/Spells_tests.cpp 
	src/Spells.cpp 
	src/Spells.hpp 
)
target_link_libraries(spells_tests ${criterion_LIBRARIES})
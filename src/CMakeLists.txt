#Change this if you need to target a specific CMake version
cmake_minimum_required(VERSION 2.6)

set (CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable debug symbols by default
# must be done before project() statement
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()
# (you can also set it on the command line: -D CMAKE_BUILD_TYPE=Release)

project(myproject)

# Set version information in a config.h file
set(myproject_VERSION_MAJOR 1)
set(myproject_VERSION_MINOR 0)
configure_file(
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )
include_directories("${PROJECT_BINARY_DIR}")

# Define sources and executable
set(EXECUTABLE_NAME "myproject")
add_executable(${EXECUTABLE_NAME}
	src/main.cpp

	src/Engine.cpp
	src/Engine.hpp
	src/GameObj.cpp
	src/GameObj.hpp
	src/Scene.cpp
	src/Scene.hpp
	src/SpriteSheet.cpp
	src/SpriteSheet.hpp
	src/Utils.cpp
	src/Utils.hpp
	src/SpriteObj.hpp
	src/SpriteObj.cpp
	src/MoveObj.hpp
	src/MoveObj.cpp
	src/MainObj.cpp
	src/MainObj.hpp
	src/ColliderMap.cpp
	src/ColliderMap.hpp
	src/Collider.hpp
	src/Collider.cpp
	src/CrackObj.cpp
	src/CrackObj.hpp
	src/MonsterObj.cpp
	src/MonsterObj.hpp
	src/ShareObj.cpp
	src/ShareObj.hpp
	src/ExitObj.cpp
	src/ExitObj.hpp
	src/AttackObj.cpp
	src/AttackObj.hpp
	
	src/json.hpp

	src/FakeSceneA.cpp
	src/FakeSceneA.hpp
	src/JsonScene.cpp
	src/JsonScene.hpp
	src/Spells.cpp
	src/Spells.hpp
	src/Sound.cpp
	src/Sound.hpp
)

# Detect and add SFML
if (WIN32)
	set(SFML_ROOT "${CMAKE_SOURCE_DIR}/vendor/SFML-2.4.2")
endif ()
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED network audio graphics window system)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()


# Install target
install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)


# CPack packaging
include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/COPYING")
set(CPACK_PACKAGE_VERSION_MAJOR "${myproject_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${myproject_VERSION_MINOR}")
include(CPack)

# spells subprojet managed by Leos
if (NOT WIN32)
	add_subdirectory(spells)
endif ()


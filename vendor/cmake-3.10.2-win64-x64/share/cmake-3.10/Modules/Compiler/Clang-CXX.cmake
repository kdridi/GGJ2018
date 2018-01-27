include(Compiler/Clang)
__compiler_clang(CXX)

if(NOT "x${CMAKE_CXX_SIMULATE_ID}" STREQUAL "xMSVC")
  set(CMAKE_CXX_COMPILE_OPTIONS_VISIBILITY_INLINES_HIDDEN "-fvisibility-inlines-hidden")
endif()

cmake_policy(GET CMP0025 appleClangPolicy)
if(APPLE AND NOT appleClangPolicy STREQUAL NEW)
  return()
endif()

if(NOT "x${CMAKE_CXX_SIMULATE_ID}" STREQUAL "xMSVC")
  if(NOT CMAKE_CXX_COMPILER_VERSION VERSION_LESS 2.1)
    set(CMAKE_CXX98_STANDARD_COMPILE_OPTION "-std=c++98")
    set(CMAKE_CXX98_EXTENSION_COMPILE_OPTION "-std=gnu++98")
  endif()

  if(NOT CMAKE_CXX_COMPILER_VERSION VERSION_LESS 3.1)
    set(CMAKE_CXX11_STANDARD_COMPILE_OPTION "-std=c++11")
    set(CMAKE_CXX11_EXTENSION_COMPILE_OPTION "-std=gnu++11")
  elseif(NOT CMAKE_CXX_COMPILER_VERSION VERSION_LESS 2.1)
    set(CMAKE_CXX11_STANDARD_COMPILE_OPTION "-std=c++0x")
    set(CMAKE_CXX11_EXTENSION_COMPILE_OPTION "-std=gnu++0x")
  endif()

  if(NOT CMAKE_CXX_COMPILER_VERSION VERSION_LESS 3.5)
    set(CMAKE_CXX14_STANDARD_COMPILE_OPTION "-std=c++14")
    set(CMAKE_CXX14_EXTENSION_COMPILE_OPTION "-std=gnu++14")
  elseif(NOT CMAKE_CXX_COMPILER_VERSION VERSION_LESS 3.4)
    set(CMAKE_CXX14_STANDARD_COMPILE_OPTION "-std=c++1y")
    set(CMAKE_CXX14_EXTENSION_COMPILE_OPTION "-std=gnu++1y")
  endif()

  if (NOT CMAKE_CXX_COMPILER_VERSION VERSION_LESS 3.5)
    set(CMAKE_CXX17_STANDARD_COMPILE_OPTION "-std=c++1z")
    set(CMAKE_CXX17_EXTENSION_COMPILE_OPTION "-std=gnu++1z")
  endif()
else()
  # clang-cl does not know these options because it behaves like cl.exe
  set(CMAKE_CXX98_STANDARD_COMPILE_OPTION "")
  set(CMAKE_CXX98_EXTENSION_COMPILE_OPTION "")
  set(CMAKE_CXX11_STANDARD_COMPILE_OPTION "")
  set(CMAKE_CXX11_EXTENSION_COMPILE_OPTION "")
  set(CMAKE_CXX14_STANDARD_COMPILE_OPTION "")
  set(CMAKE_CXX14_EXTENSION_COMPILE_OPTION "")
  set(CMAKE_CXX17_STANDARD_COMPILE_OPTION "")
  set(CMAKE_CXX17_EXTENSION_COMPILE_OPTION "")
endif()

if(NOT "x${CMAKE_CXX_SIMULATE_ID}" STREQUAL "xMSVC")
  __compiler_check_default_language_standard(CXX 2.1 98)
else()
  set(CMAKE_CXX_STANDARD_DEFAULT "")
endif()

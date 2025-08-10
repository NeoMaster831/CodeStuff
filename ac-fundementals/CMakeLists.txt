cmake_minimum_required(VERSION 3.25)

project(ac-fundementals
  VERSION 0.1.0
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

foreach(cfg IN ITEMS Debug Release RelWithDebInfo MinSizeRel)
  string(TOUPPER "${cfg}" CFG_UP)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${CFG_UP} "${CMAKE_BINARY_DIR}/bin/${cfg}")
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${CFG_UP} "${CMAKE_BINARY_DIR}/lib/${cfg}")
  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${CFG_UP} "${CMAKE_BINARY_DIR}/lib/${cfg}")
endforeach()

if(MSVC)
  add_compile_options(/W4 /permissive- /Zc:preprocessor /Zc:__cplusplus)
  add_compile_options(/utf-8)
else()
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

function(safe_add_subdirectory dir)
  if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${dir}/CMakeLists.txt")
    message(STATUS "Configuring subproject: ${dir}")
    add_subdirectory("${dir}")
  else()
    message(STATUS "Skipping '${dir}' (no CMakeLists.txt found)")
  endif()
endfunction()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

safe_add_subdirectory(um-module)

set(WDK_PFX "${CMAKE_CURRENT_SOURCE_DIR}/cmake/TestSigning.pfx")
safe_add_subdirectory(km-module)
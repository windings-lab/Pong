cmake_minimum_required(VERSION 4.1)
project(Pong)

# set the output directory for built objects.
# This makes sure that the dynamic library goes into the build directory automatically.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

# prevent installing to system directories.
set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}" CACHE INTERNAL "")

set(BUILD_SHARED_LIBS OFF CACHE INTERNAL "")

add_executable(Pong)

# Configuration
target_compile_features(Pong PRIVATE cxx_std_23)

# PCH
target_precompile_headers(Pong PRIVATE "${Pong_SOURCE_DIR}/pch/pch.h")

# Sources
file(GLOB Pong_SOURCE_FILES "${Pong_SOURCE_DIR}/src/*.cpp")
target_sources(Pong PRIVATE ${Pong_SOURCE_FILES})

# Headers
add_library(Pong_Headers INTERFACE)
file(GLOB Pong_INCLUDE_FILES "${Pong_SOURCE_DIR}/include/*.h")
target_sources(Pong PRIVATE ${Pong_INCLUDE_FILES})
target_include_directories(Pong_Headers INTERFACE
						   "$<BUILD_INTERFACE:${Pong_SOURCE_DIR}/include>"
)
target_link_libraries(Pong PUBLIC Pong_Headers)

# Utility
add_library(Pong_Utility INTERFACE)
file(GLOB Pong_UTILITY_HEADERS "${Pong_SOURCE_DIR}/include/utility/*.h")
target_sources(Pong PRIVATE ${Pong_UTILITY_HEADERS})
target_include_directories(Pong_Utility INTERFACE
						   "$<BUILD_INTERFACE:${Pong_SOURCE_DIR}/include/utility>"
)
target_link_libraries(Pong PRIVATE Pong_Utility)

# Package Management
include(cmake/CPM.cmake)
set(FETCHCONTENT_QUIET FALSE)

# SDL3
CPMAddPackage(
	GITHUB_REPOSITORY "libsdl-org/SDL"
	GIT_TAG "release-3.4.0"
	OPTIONS "GIT_PROGRESS TRUE" "SDL_SHARED OFF" "SDL_TEST_LIBRARY OFF" "SDL_TESTS OFF" "SDL_INSTALL_TESTS OFF" "SDL_STATIC ON"
)
target_compile_definitions(Pong PRIVATE SDL_MAIN_USE_CALLBACKS)
target_link_libraries(Pong PRIVATE SDL3::SDL3)

# OpenGL
find_package(OpenGL REQUIRED)
target_link_libraries(Pong PRIVATE ${OPENGL_LIBRARIES})

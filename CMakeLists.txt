cmake_minimum_required(VERSION 3.10)

project(ConfigCreator LANGUAGES CXX)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "_CMake")

if (WIN32)
	set_property(DIRECTORY ${CMAKE_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
endif()

set(SOURCES example.cpp)

add_executable(ConfigCreator ${SOURCES})

cmake_minimum_required(VERSION 2.8)

project(BroPluginUAP)

include(BroPlugin)

#set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_GLIBCXX_USE_CXX11_ABI=1")

find_package(yaml-cpp REQUIRED)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.58.0 COMPONENTS regex REQUIRED)

include_directories(BEFORE ${JSON-C_INCLUDE_DIR})
include_directories(${Boost_INCLUDE_DIRS})


bro_plugin_begin(VR UAP)
bro_plugin_cc(src/Plugin.cc)
bro_plugin_bif(src/uap.bif)
bro_plugin_bif(src/types.bif)
bro_plugin_cc(src/UaParser.cpp)
bro_plugin_link_library(${JSON-C_LIBRARIES})
bro_plugin_link_library(${Boost_LIBRARIES})
bro_plugin_link_library(${YAML_CPP_LIBRARIES})
bro_plugin_dist_files(README CHANGES COPYING VERSION)
bro_plugin_end()

file(STRINGS "${CMAKE_CURRENT_SOURCE_DIR}/VERSION" VERSION LIMIT_COUNT 1)

if ("${PROJECT_SOURCE_DIR}" STREQUAL "${CMAKE_SOURCE_DIR}")
    # Allows building rpm/deb packages via "make package" in build dir.
    include(ConfigurePackaging)
    ConfigurePackaging(${VERSION})
endif ()

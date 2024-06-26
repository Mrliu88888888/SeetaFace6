cmake_minimum_required(VERSION 2.8)
set(SeetaMaskDetector_NAME "SeetaMaskDetector" CACHE STRING "The SeetaMaskDetector library name")
set(SeetaMaskDetector_VERSION_MAJOR "2")
set(SeetaMaskDetector_VERSION_MINOR "0")
set(SeetaMaskDetector_VERSION_SINOR "0")
set(SeetaMaskDetector_VERSION "${SeetaMaskDetector_VERSION_MAJOR}${SeetaMaskDetector_VERSION_MINOR}${SeetaMaskDetector_VERSION_SINOR}")
project(${SeetaMaskDetector_NAME}${SeetaMaskDetector_VERSION})
# set(CMAKE_VERBOSE_MAKEFILE on)

set(SOLUTION_DIR ${CMAKE_CURRENT_SOURCE_DIR})

# option for platform
set(PLATFORM "auto" CACHE STRING "x86 or x64")
#set(CONFIGURATION "Debug" CACHE STRING "Debug or Release")
#set(CONFIGURATION ${CMAKE_BUILD_TYPE})

# option for shared or static
set(TARGET "SHARED" CACHE STRING "SHARED or STATIC" FORCE)
# option for SeetaAuthorize
option(SEETA_AUTHORIZE "Using seeta authorize" OFF)
option(SEETA_MODEL_ENCRYPT "Using model encrypt" ON)
# option for build android
option(BUILD_ANDROID "Buid android" OFF)
message(STATUS "Build android: " ${BUILD_ANDROID})

# gether moduls
list(APPEND CMAKE_MODULE_PATH ${SOLUTION_DIR}/../build/cmake)
list(APPEND CMAKE_MODULE_PATH ${SOLUTION_DIR}/cmake)
message(STATUS "CMAKE_MODULE_PATH: ${CMAKE_MODULE_PATH}")

# install dir
set(CMAKE_INSTALL_PREFIX ${SOLUTION_DIR}/../build CACHE STRING "set install prefix" FORCE)
set(SEETA_INSTALL_PATH "" CACHE STRING "seeta install path")
if(SEETA_INSTALL_PATH STREQUAL "")
else()
	set(CMAKE_INSTALL_PREFIX ${SEETA_INSTALL_PATH} CACHE STRING "set install prefix" FORCE)
endif()
message(STATUS "cmake install prefix: ${CMAKE_INSTALL_PREFIX}")

# set base flags
set(CMAKE_CFLAGS "${CMAKE_C_FLAGS} -fvisibility=hidden -w")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fvisibility=hidden -w -std=c++11")

# env
include(LOCAL_ENV)
include(INC_ORZ)

if(SEETA_AUTHORIZE)
	add_definitions(-DSEETA_AUTO_ENCRYPT)
	message(STATUS "Seeta Authorize: ON")
else()
	message(STATUS "Seeta Authorize: OFF")
endif()

if(SEETA_MODEL_ENCRYPT)
	add_definitions(-DSEETA_MODEL_ENCRYPT)
	message(STATUS "Seeta Model Encrypt: ON")
else()
	message(STATUS "Seeta Model Encrypt: OFF")
endif()

if(SEETA_AUTHORIZE)
	message(STATUS "SeetaAuthorize: " ${SEETA_AUTHORIZE})
elseif()
endif ()

if (SEETA_MODEL_ENCRYPT)
   message(STATUS "SeetaModelEncrypt: " ${SEETA_MODEL_ENCRYPT})
endif ()

if ("${PLATFORM}" STREQUAL "x86")
    message(STATUS "Platform: " ${PLATFORM})
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -m32")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m32")
elseif ("${PLATFORM}" STREQUAL "x64")
    message(STATUS "Platform: " ${PLATFORM})
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -m64")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m64")
else()
	message(STATUS "Platform: " ${PLATFORM})
endif()

if ("${CONFIGURATION}" STREQUAL "Debug")
    message(STATUS "Configuration: " ${CONFIGURATION})
    set(CMAKE_CX_FLAGS "${CMAKE_CX_FLAGS} -O0 -g -ggdb")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g -ggdb")
else()
    message(STATUS "Configuration: " ${CONFIGURATION})
    set(CMAKE_CX_FLAGS "${CMAKE_CX_FLAGS} -O3")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
endif()

add_subdirectory(${SOLUTION_DIR}/MaskDetector)
if(NOT BUILD_ANDROID)
	#add_subdirectory(${SOLUTION_DIR}/example)
endif()
